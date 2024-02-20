/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blackrider <blackrider@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 14:03:29 by blackrider        #+#    #+#             */
/*   Updated: 2024/02/20 16:36:43 by blackrider       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "clientsrver.h"

int main(void)
{
	Server server;
	cout << ft_strlen("vasia!") << endl;
	cout << server.getpid_srv() << endl;
	server.getdata();
	server.showmsg();
	return (0);
}
