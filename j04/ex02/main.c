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
#include <time.h>

#define GOES return printf("\e[0;32mGOES ✓\e[0m\n");
#define FAKE_N_GAY return printf("\e[0;31mFAKE AND GAY ✗\e[0m\n")
#define SNAIL return printf("\e[0;33mYOU ARE TOO SLOW! ✗\e[0m\n")

#define TEST_CASES 5

int		ft_iterative_power(int nb, int power);

void	ft_add_test_case(int *data, int nb, int power, int result)
{
	data[0] = nb;
	data[1] = power;
	data[2] = result;
}

void	ft_get_values(int *data, int *nb, int *power, int *actual)
{
	*nb = data[0];
	*power = data[1];
	*actual = data[2];
}

int		main(void)
{
	time_t 	start_t, end_t;
	double	diff_t;
	int data[TEST_CASES][3];
	int nb;
	int power;
	int result;
	int actual;
	int i;
	
	ft_add_test_case(&data[0][0], -3, 0 ,1);
	ft_add_test_case(&data[1][0], -235, -124, 0);
	ft_add_test_case(&data[2][0], 21, 3, 9261);
	ft_add_test_case(&data[3][0], 4, 10, 1048576);
	ft_add_test_case(&data[4][0], 14, 8, 1475789056);

	i = 0;
	while (i < TEST_CASES)
	{
		ft_get_values(&data[i][0], &nb, &power, &actual);
		time(&start_t);
		result = ft_iterative_power(nb, power);
		time(&end_t);
		diff_t = difftime(end_t, start_t);
		printf("nb: %i, power: %i, result: %i, actual: %i, execution time = %f\n", nb, power, result, actual, diff_t);
		if (result != actual)
			FAKE_N_GAY;
		if (diff_t >= 2.0)
			SNAIL;
		++i;
	}
	GOES;
}
