/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clientsrver.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blackrider <blackrider@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 11:30:27 by blackrider        #+#    #+#             */
/*   Updated: 2024/02/20 16:13:20 by blackrider       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

extern "C"
{
	#include "libft/libft.h"
}
#include <iostream>
#include <cstdlib>
#include <csignal>
#include <string>

#define	BYTESIZE	8

typedef unsigned char	uchar;

using namespace std;

class Client
{
	int					gotanswer;
	int					serverpid;
	struct sigaction	sa;
	string				msg;
	static Client*		instance;
	void				sendchar(char ch);
	void				sighadler(int signum);
	static void			sighandler_s(int signum);
public:
	Client(int pid = 0, char *msg = nullptr);
	~Client() {};
	void				setdata(int pid, char *msg);
	void				senddata(void);
};

class Server
{
	char				charackter;
	int					counter;
	struct sigaction	sa;
	t_dllist			*dllst;
	string				msg;
	static Server*		instance;
	t_dllist			*findpid(t_dllist *dllst, int pid);
	void				handsigusr1(siginfo_t* si, t_dllist *dllst);
	void				handsigusr0(siginfo_t* si, t_dllist *dllst);
	void				sighadler(int signum, siginfo_t* si, void* unct);
	static void			sighandler_s(int signum, siginfo_t* si, void* unct);
public:
	Server();
	~Server() {};
	string				showmsg();
	void				getdata();
	int					getpid_srv();
};

void					deldata(void *data);
t_dllist    *dllistdelnode_test(t_dllist **dllst, void (*del)(void *));