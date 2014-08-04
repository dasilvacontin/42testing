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
	int nb;
	int power;
	int result;
	int actual;

	nb = -3;
	power = 0;
	result = ft_iterative_power(nb, power);
	actual = 1;
	printf("nb: %i, power: %i, result: %i, actual: %i\n", nb, power, result, actual);
	if (result != actual)
		FAKE_N_GAY;

	nb = -235;
	power = -124;
	result = ft_iterative_power(nb, power);
	actual = 0;
	printf("nb: %i, power: %i, result: %i, actual: %i\n", nb, power, result, actual);
	if (result != actual)
		FAKE_N_GAY;

	nb = 21;
	power = 3;
	result = ft_iterative_power(nb, power);
	actual = 9261;
	printf("nb: %i, power: %i, result: %i, actual: %i\n", nb, power, result, actual);
	if (result != actual)
		FAKE_N_GAY;

	nb = 4;
	power = 10;
	result = ft_iterative_power(nb, power);
	actual = 1048576;
	printf("nb: %i, power: %i, result: %i, actual: %i\n", nb, power, result, actual);
	if (result != actual)
		FAKE_N_GAY;

	GOES;	
}
