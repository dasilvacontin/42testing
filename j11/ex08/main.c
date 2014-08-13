/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/08/13 23:13:02 by dda-silv          #+#    #+#             */
/*   Updated: 2014/08/13 23:31:33 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdio.h>

void	ft_list_reverse(t_list **begin_list);

int		main(void)
{
	t_list	*list;

	list = ft_create_elem("1\n");
	list->next = ft_create_elem("2\n");
	list->next->next = ft_create_elem("3\n");
	ft_list_reverse(&list);
	printf("Begining bbbbbbucle\n");
	while (list)
	{
		printf(list->data);
		list = list->next;
	}
	return (0);
}
