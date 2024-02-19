/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blackrider <blackrider@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 14:03:29 by blackrider        #+#    #+#             */
/*   Updated: 2024/02/19 14:04:04 by blackrider       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "clientsrver.h"

int main(void)
{
	Server server;
	
	cout << server.getpid_srv() << endl;
	server.getdata();
	server.showmsg();
	return (0);
}
