/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testdelfunc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blackrider <blackrider@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 16:24:11 by blackrider        #+#    #+#             */
/*   Updated: 2024/02/20 20:13:47 by blackrider       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <stdio.h>
#include <time.h>

void    deldata(void *data)
{
    free(data);
}

int main()
{
    int size;
    t_dllist    *dll;
    t_dllist    *tmp;
    int         i;

    printf("Enter a size of list:\n");
    scanf("%d", &size);
    srand(time(NULL));
    dll = NULL;
    for (int i = 0; i < size; ++i)
        dllistadd_back(&dll, dllistnewnode(rand() % 100, NULL));
    tmp = dll;
    i = 0;
    while (tmp)
    {
        printf("dll[%d].pid:\t%d\n", i, tmp->pid);
        tmp = tmp->next;
        ++i;
    }
    i = 0;
    tmp = dll;
    dllistdelnode(&(dll->previous), deldata);
    while (dll)
    {
        dllistdelnode(&dll, deldata);
		if (dll)
			dllistdelnode(&(dll->previous), deldata);
    }
    // dllistclear(&dll, deldata);
}