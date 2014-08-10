/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/08/10 18:46:36 by dda-silv          #+#    #+#             */
/*   Updated: 2014/08/10 19:44:30 by dda-silv         ###   ########.fr       */
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

#define TEST_CASES 24

int		match(char *s1, char *s2);

void	ft_add_test_case(char **data, char *s1, char *s2, char *result)
{
	data[0] = s1;
	data[1] = s2;
	data[2] = result;
}

void	ft_get_values(char **data, char **s1, char **s2, char **result)
{
	*s1 = data[0];
	*s2 = data[1];
	*result = data[2];
}

int		main(void)
{
	time_t 	start_t, end_t;
	double	diff_t;
	char	*data[TEST_CASES][3];
	char	*s1;
	char	*s2;
	int		your_result;
	char	*actual_result;
	int		i;

	i = 0;
	//Normal match
	ft_add_test_case(&data[i++][0], "abc", "abc", "1");
	ft_add_test_case(&data[i++][0], "abc", "abd", "0");

	// * matches empty string, different places
	ft_add_test_case(&data[i++][0], "abcd", "ab*cd", "1");
	ft_add_test_case(&data[i++][0], "abcd", "ab*ce", "0");
	ft_add_test_case(&data[i++][0], "abcd", "ab*ed", "0");
	ft_add_test_case(&data[i++][0], "abcd", "*abcd", "1");
	ft_add_test_case(&data[i++][0], "abcd", "a*abcd", "0");
	ft_add_test_case(&data[i++][0], "abcd", "abcd*", "1");
	ft_add_test_case(&data[i++][0], "abcd", "abcd*d", "0");
	ft_add_test_case(&data[i++][0], "abcd", "*abcd*", "1");
	ft_add_test_case(&data[i++][0], "abcd", "ab**cd", "1");
	ft_add_test_case(&data[i++][0], "abcd", "a*b*c*d", "1");
	ft_add_test_case(&data[i++][0], "abcd", "ab**cd", "1");
	ft_add_test_case(&data[i++][0], "abcd", "*", "1");
	ft_add_test_case(&data[i++][0], "abcd", "**", "1");
	ft_add_test_case(&data[i++][0], "abcd", "***", "1");

	// * matches non-empty string, different places
	ft_add_test_case(&data[i++][0], "abilgewbi;wewb;bicd", "ab*cd", "1");
	ft_add_test_case(&data[i++][0], "qfwyjhbqw fwqgf abcd", "*abcd", "1");
	ft_add_test_case(&data[i++][0], "abcdybqwdkqwg   qwiulg", "abcd*", "1");
	ft_add_test_case(&data[i++][0], "ewg abcdwef", "*abcd*", "1");
	ft_add_test_case(&data[i++][0], "abfoijqwfijcd", "ab**cd", "1");
	ft_add_test_case(&data[i++][0], "aasdbqwdcqwdd", "a*b*c*d", "1");
	ft_add_test_case(&data[i++][0], "abcdgh abcedgh", "*abc*edgh", "1");
	ft_add_test_case(&data[i++][0], "abcdgh abcdgh", "*abc*edgh", "0");
	
	i = 0;
	while (i < TEST_CASES)
	{
		ft_get_values(&data[i][0], &s1, &s2, &actual_result);
		time(&start_t);
		your_result = match(s1, s2);
		time(&end_t);
		diff_t = difftime(end_t, start_t);
		printf("s1: %s, s2: %s, your_result: %i, actual_result: %i, execution time = %f\n", s1, s2, your_result, actual_result[0] - '0', diff_t);
		if (your_result != actual_result[0] - '0')
			FAKE_N_GAY;
		if (diff_t >= 2.0)
			SNAIL;
		++i;
	}
	GOES;
}