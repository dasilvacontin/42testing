/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/08/04 18:52:59 by dda-silv          #+#    #+#             */
/*   Updated: 2014/08/04 20:13:29 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdio.h>

#define GOES return printf("GOES ✓\n");
#define FAKE_N_GAY return printf("FAKE AND GAY ✗\n")

int		ft_sqrt(int nb);

int		main(void)
{
	int i;
	int result;
	int actual;

	i = -50;
	while (i < 500)
	{
		result = ft_sqrt(i);
		actual = (int) sqrt(i);
		if (actual * actual != i)
			actual = 0;	
		printf("sqrt of %i; result: %i, actual: %i\n", i, result, actual);
		if (result != actual)
			FAKE_N_GAY;
		++i;
	}
	GOES;
}
