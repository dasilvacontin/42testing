/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/08/13 19:22:30 by dda-silv          #+#    #+#             */
/*   Updated: 2014/08/13 20:00:41 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#define FAIL (printf("fail\n") || 1)
#define GOES (printf("works!\n") && 0)

#include "ft_list.h"
t_list		*ft_create_elem(void *data);

int		main(void)
{
	t_list	*elem;
	int		lol;

	lol = 42;
	elem = ft_create_elem(&lol);
	if (elem->next != (void*)0)
		return FAIL;
	if (elem->data != &lol)
		return FAIL;
	return GOES;
}
