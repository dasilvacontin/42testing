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
	if (ft_recursive_factorial(5) != 120)
		FAKE_N_GAY;
	if (ft_recursive_factorial(0) != 1)
		FAKE_N_GAY;
	if (ft_recursive_factorial(-42) != 0)
		FAKE_N_GAY;
	GOES;
}