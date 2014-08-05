/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/08/05 12:39:10 by dda-silv          #+#    #+#             */
/*   Updated: 2014/08/05 13:44:43 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <time.h>
#include <stdio.h>

#define GOES return printf("GOES ✓\n");
#define FAKE_N_GAY return printf("FAKE AND GAY ✗\n")
#define TEST_CASES 9

int		ft_find_next_prime(int nb);

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

	ft_add_case(&test[0][0], 7919, 7919);
	ft_add_case(&test[1][0], -236, 2);
	ft_add_case(&test[2][0], 0, 2);
	ft_add_case(&test[3][0], 1, 2);
	ft_add_case(&test[4][0], 2, 2);
	ft_add_case(&test[5][0], 3313, 3313);
	ft_add_case(&test[6][0], 30967, 30971);
	ft_add_case(&test[7][0], 31051, 31051);
	ft_add_case(&test[8][0], 855890, 855901);

	i = 0;
	while (i < TEST_CASES)
	{

		nb = test[i][0];
		actual = test[i][1];

		printf("number %i, next prime?\n", nb);
		time(&start_t);
		result = ft_find_next_prime(nb);
		time(&end_t);
		diff_t = difftime(end_t, start_t);
		
		printf(" result: %i, actual> %i, execution time = %f\n", result, test[i][1], diff_t);
		if (result != actual)
			FAKE_N_GAY;
		++i;
	}
	GOES;
}
