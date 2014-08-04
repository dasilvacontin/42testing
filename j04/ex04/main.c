/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/08/04 18:09:49 by dda-silv          #+#    #+#             */
/*   Updated: 2014/08/04 18:16:58 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#define GOES return printf("GOES ✓\n");
#define FAKE_N_GAY return printf("FAKE AND GAY ✗\n")

int		ft_fibonacci(int index);

int		main(void)
{

	int data[6][2];
	int result;
	int i;
	
	// Each couple is index,actual
	
	data[0][0] = 0;
	data[0][1] = 0;

	data[1][0] = 1;
	data[1][1] = 1;
	
	data[2][0] = 2;
	data[2][1] = 1;

	data[3][0] = 3;
	data[3][1] = 2;

	data[4][0] = -3;
	data[4][1] = -1;

	data[5][0] = 10;
	data[5][1] = 55;

	i = 0;
	while (i < 6)
	{
		result = ft_fibonacci(data[i][0]);
		printf("index: %i, result: %i, actual: %i\n", data[i][0], result, data[i][1]);
		if (result != data[i][1])
			FAKE_N_GAY;
		++i;
	}
	GOES;
}
