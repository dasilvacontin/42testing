/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/08/04 16:22:28 by dda-silv          #+#    #+#             */
/*   Updated: 2014/08/06 12:23:04 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <time.h>

#define GOES return printf("\e[0;32mGOES ✓\e[0m\n");
#define FAKE_N_GAY return printf("\e[0;31mFAKE AND GAY ✗\e[0m\n")
#define SNAIL return printf("\e[0;33mYOU ARE TOO SLOW! ✗\e[0m\n")

#define TEST_CASES 5

int		ft_iterative_factorial(int nb);

void	ft_add_test_case(int *data, int nb, int result)
{
	data[0] = nb;
	data[1] = result;
}

void	ft_get_values(int *data, int *nb, int *actual)
{
	*nb = data[0];
	*actual = data[1];
}

int		main(void)
{
	time_t 	start_t, end_t;
	double	diff_t;
	int data[TEST_CASES][2];
	int nb;
	int result;
	int actual;
	int i;
	
	ft_add_test_case(&data[0][0], 5, 120);
	ft_add_test_case(&data[1][0], 0, 1);
	ft_add_test_case(&data[2][0], -42, 0);
	ft_add_test_case(&data[3][0], 12, 479001600);
	ft_add_test_case(&data[4][0], 13, 0);

	i = 0;
	while (i < TEST_CASES)
	{
		ft_get_values(&data[i][0], &nb, &actual);
		time(&start_t);
		result = ft_iterative_factorial(nb);
		time(&end_t);
		diff_t = difftime(end_t, start_t);
		printf("nb: %i, result: %i, actual: %i, execution time = %f\n", nb, result, actual, diff_t);
		if (result != actual)
		{
			if (i == 4)
				printf("(tip: you aren't testing if an INT overflow has occurred!\n");
			FAKE_N_GAY;
		}
		if (diff_t >= 2.0)
			SNAIL;
		++i;
	}
	GOES;
}
