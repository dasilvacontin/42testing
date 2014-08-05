/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/08/04 18:09:49 by dda-silv          #+#    #+#             */
/*   Updated: 2014/08/05 17:44:26 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <time.h>

#define GOES return printf("\e[0;32mGOES ✓\e[0m\n");
#define FAKE_N_GAY return printf("\e[0;31mFAKE AND GAY ✗\e[0m\n")
#define SNAIL return printf("\e[0;33mYOU ARE TOO SLOW! ✗\e[0m\n")

int		ft_fibonacci(int index);

int		main(void)
{
	time_t 	start_t, end_t;
	double	diff_t;
	int data[7][2];
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
	
	data[6][0] = 46;
	data[6][1] = 1836311903;

	i = 0;
	while (i < 7)
	{
		time(&start_t);
		result = ft_fibonacci(data[i][0]);
		time(&end_t);
		diff_t = difftime(end_t, start_t);
		printf("index: %i, result: %i, actual: %i, execution time = %f\n", data[i][0], result, data[i][1], diff_t);
		if (result != data[i][1])
			FAKE_N_GAY;
		if (diff_t >= 2.0)
			SNAIL;
		++i;
	}
	GOES;
}
