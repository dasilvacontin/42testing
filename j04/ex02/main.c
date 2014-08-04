/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/08/04 16:52:19 by dda-silv          #+#    #+#             */
/*   Updated: 2014/08/04 16:56:43 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#define GOES return printf("GOES ✓\n");
#define FAKE_N_GAY return printf("FAKE AND GAY ✗\n")

int		ft_iterative_power(int nb, int power);

int		main(void)
{
	if (ft_iterative_power(-3, 0) != 1)
		FAKE_N_GAY;
	if (ft_iterative_power(-235, -124) != 0)
		FAKE_N_GAY;
	if (ft_iterative_power(21, 3) != 9261)
		FAKE_N_GAY;
	if (ft_iterative_power(4, 10) != 1048576)
	   FAKE_N_GAY;
	GOES;	
}
