/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/08/06 19:05:30 by dda-silv          #+#    #+#             */
/*   Updated: 2014/08/06 19:05:45 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <time.h>
#include <string.h>

#define GOES return printf("\e[0;32mGOES ✓\e[0m\n");
#define FAKE_N_GAY return printf("\e[0;31mFAKE AND GAY ✗\e[0m\n")
#define SNAIL return printf("\e[0;33mYOU ARE TOO SLOW! ✗\e[0m\n")

#define TEST_CASES 3

char    *ft_strstr(char *str, char *to_find);

void	ft_add_test_case(char **data, char *str, char *to_find)
{
	data[0] = str;
	data[1] = to_find;
}

void	ft_get_values(char **data, char **str, char **to_find)
{
	*str = data[0];
	*to_find = data[1];
}

int		main(void)
{
	time_t 	start_t, end_t;
	double	diff_t;
	char *data[TEST_CASES][2];
	char *str;
	char *to_find;
	char *your_ptr;
	char *actual_ptr;
	int i;

	ft_add_test_case(&data[0][0], "je code avec le cul", "code");
	ft_add_test_case(&data[1][0], "u mad", "e");
	ft_add_test_case(&data[2][0], "dflisigdidsgdhsghg", "sg");
	
	i = 0;
	while (i < TEST_CASES)
	{
		ft_get_values(&data[i][0], &str, &to_find);
		time(&start_t);
		your_ptr = ft_strstr(str, to_find);
		time(&end_t);
		actual_ptr = strstr(str, to_find);
		diff_t = difftime(end_t, start_t);
		printf("str: %s, to_find: %s, your_ptr: %p, actual_ptr: %p, execution time = %f\n", str, to_find, your_ptr, actual_ptr, diff_t);
		if (your_ptr != actual_ptr)
			FAKE_N_GAY;
		if (diff_t >= 2.0)
			SNAIL;
		++i;
	}
	GOES;
}

