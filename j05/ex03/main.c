/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/08/06 19:28:00 by dda-silv          #+#    #+#             */
/*   Updated: 2014/08/06 19:28:01 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <time.h>
#include <string.h>

#define GOES return printf("\e[0;32mGOES ✓\e[0m\n");
#define FAKE_N_GAY return printf("\e[0;31mFAKE AND GAY ✗\e[0m\n")
#define SNAIL return printf("\e[0;33mYOU ARE TOO SLOW! ✗\e[0m\n")

#define TEST_CASES 4

int		ft_strcmp(char *s1, char *s2);

void	ft_add_test_case(char **data, char *s1, char *s2)
{
	data[0] = s1;
	data[1] = s2;
}

void	ft_get_values(char **data, char **s1, char **s2)
{
	*s1 = data[0];
	*s2 = data[1];
}

int		main(void)
{
	time_t 	start_t, end_t;
	double	diff_t;
	char *data[TEST_CASES][2];
	char *s1;
	char *s2;
	int your_result;
	int actual_result;
	int i;

	ft_add_test_case(&data[0][0], "je code avec le cul", "je code avec le cul");
	ft_add_test_case(&data[1][0], "u mad", "u maf");
	ft_add_test_case(&data[2][0], "", "");
	ft_add_test_case(&data[3][0], "asfg asg", "asfgasg");
	
	i = 0;
	while (i < TEST_CASES)
	{
		ft_get_values(&data[i][0], &s1, &s2);
		time(&start_t);
		your_result = ft_strcmp(s1, s2);
		time(&end_t);
		actual_result = strcmp(s1, s2);
		diff_t = difftime(end_t, start_t);
		printf("s1: %s, s2: %s, your_result: %i, actual_result: %i, execution time = %f\n", s1, s2, your_result, actual_result, diff_t);
		if (your_result != actual_result)
			FAKE_N_GAY;
		if (diff_t >= 2.0)
			SNAIL;
		++i;
	}
	GOES;
}