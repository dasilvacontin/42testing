/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/08/13 17:39:51 by dda-silv          #+#    #+#             */
/*   Updated: 2014/08/13 17:42:59 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_log(int nb)
{
	printf("%i\n", nb);
}

void	ft_foreach(int *tab, int length, void(*f)(int));

int		main(void)
{
	int		tab[5];
	int		i;

	i = -1;
	while (++i < 5)
		tab[i] = i;

	ft_foreach(tab, 5, &ft_log);
	return (0);
}
