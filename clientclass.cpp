/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clientclass.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blackrider <blackrider@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 11:44:21 by blackrider        #+#    #+#             */
/*   Updated: 2024/02/19 14:07:53 by blackrider       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "clientsrver.h"

Client*	Client::instance = nullptr;

Client::Client(int pid, char *msg)
{
	instance = this;
    gotanswer = 0;
    serverpid = pid;
    this->msg = msg;
    sa.sa_handler = sighandler_s;
    sa.sa_flags = 0;
    sigemptyset(&sa.sa_mask);
    sigaddset(&sa.sa_mask, SIGUSR1);
    sigaddset(&sa.sa_mask, SIGUSR2);
    sigaction(SIGUSR1, &sa, NULL);
    sigaction(SIGUSR2, &sa, NULL);
}

void	Client::sighadler(int signum)
{
	gotanswer = 1;
}

void	Client::sighandler_s(int signumnum)
{
	instance->sighadler(signumnum);
}

void    Client::sendchar(char ch)
{
    int     i;
    uchar   mask;

    i = 0;
    mask = 128;
    while (i < BYTESIZE)
    {
        if (mask & (ch << i))
           	kill(serverpid, SIGUSR1);
        else
            kill(serverpid, SIGUSR2);
        while (!gotanswer) {}
        ++i;
		gotanswer = 0;
    }
}

void    Client::senddata(void)
{
    string::iterator    i;
    int                 j;
    uchar               mask;

    i = msg.begin();
    mask = 128;
    while (i != msg.end())
    {
        sendchar(*i);
        ++i;
    }
    sendchar(0);
}

void    Client::setdata(int pid, char *msg)
{
    serverpid = pid;
    this->msg = msg;
}
