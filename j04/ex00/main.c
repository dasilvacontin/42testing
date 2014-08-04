/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/08/04 16:22:28 by dda-silv          #+#    #+#             */
/*   Updated: 2014/08/04 16:28:41 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#define GOES return printf("GOES ✓\n");
#define FAKE_N_GAY return printf("FAKE AND GAY ✗\n")

int		ft_iterative_factorial(int nb);

int		main(void)
{
	if (ft_iterative_factorial(5) != 120)
		FAKE_N_GAY;
	if (ft_iterative_factorial(0) != 1)
		FAKE_N_GAY;
	if (ft_iterative_factorial(-42) != 0)
		FAKE_N_GAY;
	GOES;
}
