/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/08/13 20:56:03 by dda-silv          #+#    #+#             */
/*   Updated: 2014/08/13 21:02:40 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#define FAIL(x) (printf("fail: %s\n", x) || 1)
#define GOES (printf("works!\n") && 0)

#include "ft_list.h"

void	ft_list_push_front(t_list **begin_list, void *data);

int		main(void)
{
	t_list	*begin_list;
	t_list	*first_elem;
	int i;

	i = 4;
	begin_list = ft_create_elem(&i);
	begin_list->next = ft_create_elem(&i);
	first_elem = begin_list;
	ft_list_push_front(&begin_list, &i);
	if (begin_list == first_elem)
		return FAIL("first elem is still the same");
	if (begin_list->data != &i)
		return FAIL("wrong data on first elem");
	if (begin_list->next != first_elem)
		return FAIL("broke list chain");
	return GOES;	
}
