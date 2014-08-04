/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/08/04 16:41:00 by dda-silv          #+#    #+#             */
/*   Updated: 2014/08/04 16:41:02 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#define GOES return printf("GOES ✓\n");
#define FAKE_N_GAY return printf("FAKE AND GAY ✗\n")

int		ft_recursive_factorial(int nb);

int		main(void)
{
	int nb;
	int result;
	int actual;

	nb = 5;
	result = ft_recursive_factorial(nb);
	actual = 120;
	printf("nb: %i, result: %i, actual: %i\n", nb, result, actual);
	if (result != actual)
		FAKE_N_GAY;

	nb = 0;
	result = ft_recursive_factorial(nb);
	actual = 1;
	printf("nb: %i, result: %i, actual: %i\n", nb, result, actual);
	if (result != actual)
		FAKE_N_GAY;

	nb = -42;
	result = ft_recursive_factorial(nb);
	actual = 0;
	printf("nb: %i, result: %i, actual: %i\n", nb, result, actual);
	if (result != actual)
		FAKE_N_GAY;

	GOES;
}