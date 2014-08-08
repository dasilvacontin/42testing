/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/08/08 10:05:10 by dda-silv          #+#    #+#             */
/*   Updated: 2014/08/08 10:05:12 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define GOES return printf("\e[0;32mGOES ✓\e[0m\n");
#define FAKE_N_GAY return printf("\e[0;31mFAKE AND GAY ✗\e[0m\n")
#define SNAIL return printf("\e[0;33mYOU ARE TOO SLOW! ✗\e[0m\n")

#define TEST_CASES 6

int		ft_ultimate_range(int **range, int min, int max);

void	ft_add_test_case(int *data, int min, int max)
{
	data[0] = min;
	data[1] = max;
}

void	ft_get_values(int *data, int *min, int *max)
{
	*min = data[0];
	*max = data[1];
}

int		main(void)
{
	time_t 	start_t, end_t;
	double	diff_t;
	int		data[TEST_CASES][3];
	int 	*tab;
	int		tab_size;
	int		min;
	int		max;
	int 	i;
	int		j;

	ft_add_test_case(&data[0][0], 10, 100);
	ft_add_test_case(&data[1][0], 50, 49);
	ft_add_test_case(&data[2][0], 14, 374);
	ft_add_test_case(&data[3][0], 0, 0);
	ft_add_test_case(&data[4][0], 32, 8);
	ft_add_test_case(&data[5][0], 3, 45);
	
	i = 0;
	while (i < TEST_CASES)
	{
		ft_get_values(&data[i][0], &min, &max);
		time(&start_t);
		tab_size = ft_ultimate_range(&tab, min, max);
		time(&end_t);
		diff_t = difftime(end_t, start_t);
		printf("min: %i, max: %i, tab_size: %i, tab_pointer: %p, tab_sizeexecution time = %f\n", min, max, tab_size, tab, diff_t);
		if ((min < max && tab_size != max - min) || (min >= max && tab_size != 0))
		{
			printf("Wrong tab size !\n");
			FAKE_N_GAY;
		}
		if (min >= max && tab != 0)
		{
			printf("Pointer to tab is not NULL when min >= max !\n");
			FAKE_N_GAY;
		}
		j = -1;
		while (min < max)
			if (tab[++j] != min++) FAKE_N_GAY;
		if (diff_t >= 2.0)
			SNAIL;
		++i;
	}
	GOES;
}