/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/08/07 11:03:52 by dda-silv          #+#    #+#             */
/*   Updated: 2014/08/07 11:03:53 by dda-silv         ###   ########.fr       */
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

char	*ft_strdup(char *src);

void	ft_add_test_case(char **data, char *str)
{
	data[0] = str;
}

void	ft_get_values(char **data, char **str)
{
	*str = data[0];
}

int		main(void)
{
	time_t 	start_t, end_t;
	double	diff_t;
	char *data[TEST_CASES];
	char *str;
	char *your_result;
	char *actual_result;
	int i;

	ft_add_test_case(&data[0], "Je Code avec le CUL");
	ft_add_test_case(&data[1], "U MAD BRO");
	ft_add_test_case(&data[2], "");
	ft_add_test_case(&data[3], "iBI^7toBO&*TYUIbb7");
	ft_add_test_case(&data[4], "aaaaaaaa");
	ft_add_test_case(&data[5], "bbbbbbbb");
	
	i = 0;
	while (i < TEST_CASES)
	{
		ft_get_values(&data[i], &str);
		time(&start_t);
		your_result = ft_strdup(str);
		time(&end_t);
		actual_result = strdup(str);
		diff_t = difftime(end_t, start_t);
		printf("str: %s, your_result: %s, actual_result: %s, execution time = %f\n", str, your_result, actual_result, diff_t);
		if (strcmp(your_result, actual_result) != 0)
			FAKE_N_GAY;
		if (diff_t >= 2.0)
			SNAIL;
		++i;
	}
	GOES;
}