/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blackrider <blackrider@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 14:02:28 by blackrider        #+#    #+#             */
/*   Updated: 2024/02/19 14:03:17 by blackrider       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "clientsrver.h"

int	main(int argc, char **argv)
{
	Client client{atoi(argv[1]), argv[2]};

	client.senddata();
}