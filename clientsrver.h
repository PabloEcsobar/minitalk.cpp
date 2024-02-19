/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clientsrver.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blackrider <blackrider@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 11:30:27 by blackrider        #+#    #+#             */
/*   Updated: 2024/02/19 13:20:30 by blackrider       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
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
	string				msg;
	static Server*		instance;
	void				handsigusr1(siginfo_t* si);
	void				handsigusr0(siginfo_t* si);
	void				sighadler(int signum, siginfo_t* si, void* unct);
	static void			sighandler_s(int signum, siginfo_t* si, void* unct);
public:
	Server();
	~Server() {};
	string				showmsg();
	void				getdata();
	int					getpid_srv();
};