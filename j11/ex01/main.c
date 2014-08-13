/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/08/13 20:13:11 by dda-silv          #+#    #+#             */
/*   Updated: 2014/08/13 20:27:28 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#define FAIL (printf("fail\n") || 1)
#define GOES (printf("works!\n") && 0)

#include "ft_list.h"

int		main(void)
{
	t_list	*begin_list;
	t_list	*curr;
	int		i;

	i = -1;
	begin_list = ft_create_elem((void*)&i);
	curr = begin_list;
	while (++i < 10)
	{
		curr->next = ft_create_elem((void*)&i);
		curr = curr->next;
	}
	ft_list_push_back(&begin_list);
	if (!curr->next)
		return FAIL;
	return GOES;
}
