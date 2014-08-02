/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/08/02 11:54:32 by dda-silv          #+#    #+#             */
/*   Updated: 2014/08/02 11:59:25 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_ft(int *nbr);

int		main(void)
{
	int nbr;

	nbr = 3;
	printf("Before call, nbr: %i\n", nbr);
	ft_ft(&nbr);
	printf("After call, nbr: %i\n", nbr);
	return (0);
}
