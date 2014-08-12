/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/08/12 12:20:31 by dda-silv          #+#    #+#             */
/*   Updated: 2014/08/12 12:21:40 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_point.h"

void		set_point(t_point *point)
{
	point->x = 42;
	point->y = 21;
}

int			main(void)
{
	t_point	point;

	set_point(&point);
	return (0);
}
