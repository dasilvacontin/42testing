/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_elem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/08/13 19:09:44 by dda-silv          #+#    #+#             */
/*   Updated: 2014/08/13 19:22:53 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_list.h"

t_list	*ft_create_elem(void *data)
{
	t_list *elem;

	elem = (t_list*)malloc(sizeof(t_list));
	if (elem)
	{
		elem->next = 0;
		elem->data = data;
	}
	return (elem);
}
