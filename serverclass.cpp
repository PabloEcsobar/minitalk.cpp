/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serverclass.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blackrider <blackrider@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 12:56:11 by blackrider        #+#    #+#             */
/*   Updated: 2024/02/20 16:22:59 by blackrider       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "clientsrver.h"

Server*	Server::instance = nullptr;

Server::Server()
{
    dllst = NULL;
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

void    Server::handsigusr1(siginfo_t *si, t_dllist *dllst)
{
	t_dllist	*tmp;

    charackter |= 1;
    if (counter < BYTESIZE - 1)
        charackter <<= 1;
    ++counter;
    kill(si->si_pid, SIGUSR1);
    if (counter >= BYTESIZE)
    {
		*(string *)(dllst->data) += charackter;
		counter = 0;
		if (!charackter)
		{
			cout << *(string *)(dllst->data) << endl;
			this->dllst = dllistdelnode(&dllst, deldata);
		}
		charackter = 0;
    }
}

void    Server::handsigusr0(siginfo_t *si, t_dllist *dllst)
{
	t_dllist	*tmp;

    if (counter < BYTESIZE - 1)
        charackter <<= 1;
    ++counter;
    kill(si->si_pid, SIGUSR1);
    if (counter >= BYTESIZE)
    {
		*(string *)(dllst->data) += charackter;
		counter = 0;
		if (!charackter)
		{
			cout << *(string *)(dllst->data) << endl;
			this->dllst = dllistdelnode(&dllst, deldata);
		}
		charackter = 0;
    }
}

void    Server::sighadler(int signum, siginfo_t *si, void *unctx)
{
    t_dllist *tmp;

    tmp = findpid(dllst, si->si_pid);
    if (!tmp)
		tmp = dllistadd_back(&dllst, dllistnewnode(si->si_pid, new string));
    if (signum == SIGUSR1)
    {
        handsigusr1(si, tmp);
        return ;
    }
    handsigusr0(si, tmp);
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

t_dllist* Server::findpid(t_dllist *dllst, int pid)
{
	t_dllist	*tmp;

	if (!(dllst))
		return (NULL);
	tmp = dllst->previous;
    while (dllst)
    {
        if (dllst->pid == pid)
            return (dllst);
        dllst = dllst->next;
    }
	if (!tmp)
		return (NULL);
	while (tmp->next)
	{
		if (tmp->pid == pid)
            return (tmp);
        tmp = tmp->previous;
	}
    return (NULL);
}

void	deldata(void *data)
{
	delete ((string *)data);
}

t_dllist    *dllistdelnode_test(t_dllist **dllst, void (*del)(void *))
{
    t_dllist    *tmp;

	if (!(*dllst))
		return (NULL);
	tmp = *dllst;
	if ((*dllst)->previous && (*dllst)->previous->next)
		(*dllst)->previous->next = (*dllst)->next;
	if ((*dllst)->next && (*dllst)->previous != (*dllst)->next)
		(*dllst)->next->previous = (*dllst)->previous;
	*dllst = (*dllst)->next;
	del(tmp->data);
	free(tmp);
	return (*dllst);
}