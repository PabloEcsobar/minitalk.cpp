/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serverclass.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blackrider <blackrider@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 12:56:11 by blackrider        #+#    #+#             */
/*   Updated: 2024/02/19 14:07:34 by blackrider       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "clientsrver.h"

Server*	Server::instance = nullptr;

Server::Server()
{
    charackter = 0;
    counter = 0;
    instance = this;
    sa.sa_sigaction = sighandler_s;
    sa.sa_flags = SA_SIGINFO;
    sigemptyset(&sa.sa_mask);
    sigaddset(&sa.sa_mask, SIGUSR1);
    sigaddset(&sa.sa_mask, SIGUSR2);
    sigaction(SIGUSR1, &sa, NULL);
    sigaction(SIGUSR2, &sa, NULL);
}

void    Server::handsigusr1(siginfo_t *si)
{
    charackter |= 1;
    if (counter < BYTESIZE - 1)
        charackter <<= 1;
    ++counter;
    kill(si->si_pid, SIGUSR1);
    if (counter >= BYTESIZE)
    {
        msg += charackter;
        if (charackter)
            counter = 0;
        else
            counter = -1;
		charackter = 0;
    }
}

void    Server::handsigusr0(siginfo_t *si)
{
    if (counter < BYTESIZE - 1)
        charackter <<= 1;
    ++counter;
    kill(si->si_pid, SIGUSR1);
    if (counter >= BYTESIZE)
    {
        msg += charackter;
        if (charackter)
            counter = 0;
        else
			counter = -1;
		charackter = 0;
    }
}

void    Server::sighadler(int signum, siginfo_t *si, void *unctx)
{
    if (signum == SIGUSR1)
    {
        handsigusr1(si);
        return ;
    }
    handsigusr0(si);
}

void    Server::sighandler_s(int signum, siginfo_t *si, void *unctx)
{
    instance->sighadler(signum, si, unctx);
}

void    Server::getdata()
{
    while (counter > -1)
    {
        
    }
}

string  Server::showmsg()
{
    cout << msg << endl;
    return (msg);
}

int     Server::getpid_srv()
{
    return (getpid());
}
