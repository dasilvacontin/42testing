/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/08/06 19:49:05 by dda-silv          #+#    #+#             */
/*   Updated: 2014/08/06 19:49:06 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <time.h>
#include <string.h>

#define GOES return printf("\e[0;32mGOES ✓\e[0m\n");
#define FAKE_N_GAY return printf("\e[0;31mFAKE AND GAY ✗\e[0m\n")
#define SNAIL return printf("\e[0;33mYOU ARE TOO SLOW! ✗\e[0m\n")

#define TEST_CASES 5

int     ft_strncmp(char *s1, char *s2, unsigned int n);

void	ft_add_test_case(char **data, char *s1, char *s2, char *n)
{
	data[0] = s1;
	data[1] = s2;
	data[2] = n;
}

void	ft_get_values(char **data, char **s1, char **s2, char **n)
{
	*s1 = data[0];
	*s2 = data[1];
	*n = data[2];
}

int		main(void)
{
	time_t 	start_t, end_t;
	double	diff_t;
	char *data[TEST_CASES][3];
	char *s1;
	char *s2;
	char *n;
	int your_result;
	int actual_result;
	int i;

	ft_add_test_case(&data[0][0], "je code avec le cul", "je code avec le cul", "9");
	ft_add_test_case(&data[1][0], "u mad", "u maf", "2");
	ft_add_test_case(&data[2][0], "", "", "9");
	ft_add_test_case(&data[3][0], "asfg asg", "asfgasg", "7");
	ft_add_test_case(&data[4][0], "asd", "asd", "\0x7E");
	
	i = 0;
	while (i < TEST_CASES)
	{
		if (i == 4)
			printf("You might get a segfault, your fault.\n");
		ft_get_values(&data[i][0], &s1, &s2, &n);
		time(&start_t);
		your_result = ft_strncmp(s1, s2, n[0] - '0');
		time(&end_t);
		actual_result = strncmp(s1, s2, n[0] - '0');
		diff_t = difftime(end_t, start_t);
		printf("s1: %s, s2: %s, n: %i, your_result: %i, actual_result: %i, execution time = %f\n", s1, s2, n[0] - '0', your_result, actual_result, diff_t);
		if (your_result != actual_result)
			FAKE_N_GAY;
		if (diff_t >= 2.0)
			SNAIL;
		++i;
	}
	GOES;
}