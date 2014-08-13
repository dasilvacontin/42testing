/**************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/08/13 20:13:11 by dda-silv          #+#    #+#             */
/*   Updated: 2014/08/13 20:38:04 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#define FAIL(x) (printf("fail: %s\n", x) || 1)
#define GOES (printf("works!\n") && 0)

#include "ft_list.h"

void	ft_list_push_back(t_list **begin_list, void *data);

int		main(void)
{
	t_list	**list;
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
	ft_list_push_back(&begin_list, &i);
	if (!curr->next)
		return FAIL("didn't append to the end of the list");
	if (curr->next->data != &i)
		return FAIL("incorrect data in the elem");
	curr = (void*)0;
	list = &curr;
	ft_list_push_back(list, &i);
	if (!curr)
		return FAIL("failed to add elem to empty list");
	if (curr->data != &i)
		return FAIL("wrong data in the elem");
	return GOES;
}
