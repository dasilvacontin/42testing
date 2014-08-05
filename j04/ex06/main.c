/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/08/05 10:04:23 by dda-silv          #+#    #+#             */
/*   Updated: 2014/08/05 12:20:18 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <time.h>
#include <stdio.h>

#define GOES return printf("GOES ✓\n");
#define FAKE_N_GAY return printf("FAKE AND GAY ✗\n")
#define TEST_CASES 9

int		ft_is_prime(int nb);

void	ft_add_case(int *test, int nb, int is_prime)
{
	test[0] = nb;
	test[1] = is_prime;
}

int		main(void)
{
	time_t 	start_t, end_t;
	double	diff_t;
	int test[TEST_CASES][2];
	int i, nb, result, actual;

	ft_add_case(&test[0][0], 7919, 1);
	ft_add_case(&test[1][0], -236, 0);
	ft_add_case(&test[2][0], 0, 0);
	ft_add_case(&test[3][0], 1, 0);
	ft_add_case(&test[4][0], 2, 1);
	ft_add_case(&test[5][0], 3313, 1);
	ft_add_case(&test[6][0], 30967, 0);
	ft_add_case(&test[7][0], 31051, 1);
	ft_add_case(&test[8][0], 2000000000, 0);

	i = 0;
	while (i < TEST_CASES)
	{
		
		if (i == 9)
		{
			printf("\n/!\\WARNING/!\\\n");
			printf("You might fail the following test because of int overflow.\n");
			printf("INT_MAX: %i\n\n", INT_MAX);
		}

		nb = test[i][0];
		actual = test[i][1];

		printf("number %i, prime?\n", nb);
		time(&start_t);
		result = ft_is_prime(nb);
		time(&end_t);
		diff_t = difftime(end_t, start_t);
		
		printf(" result: %i, actual> %i, execution time = %f\n", result, test[i][1], diff_t);
		if (result != actual)
			FAKE_N_GAY;
		++i;
	}
	GOES;
}
