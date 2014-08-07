/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/08/06 18:24:03 by dda-silv          #+#    #+#             */
/*   Updated: 2014/08/06 18:24:05 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <time.h>
#include <string.h>

#define GOES return printf("\e[0;32mGOES ✓\e[0m\n");
#define FAKE_N_GAY return printf("\e[0;31mFAKE AND GAY ✗\e[0m\n")
#define SNAIL return printf("\e[0;33mYOU ARE TOO SLOW! ✗\e[0m\n")

#define TEST_CASES 4

char	*ft_strncpy(char *dest, char *src, unsigned int n);

void	ft_add_test_case(char **data, char *dest, char *src, char *n)
{
	data[0] = dest;
	data[1] = src;
	data[2] = n;
}

void	ft_get_values(char **data, char **dest, char **src, char **n)
{
	*dest = data[0];
	*src = data[1];
	*n = data[2];
}

int		main(void)
{
	time_t 	start_t, end_t;
	double	diff_t;
	char *data[TEST_CASES][3];
	char *dest;
	char *src;
	char *n;
	char your_result[100];
	char actual_answer[100];
	int i;

	ft_add_test_case(&data[0][0], "je code avec le cul", "wut", "3");
	ft_add_test_case(&data[1][0], "u mad", "ooooo", "2");
	ft_add_test_case(&data[2][0], "", "", "5");
	ft_add_test_case(&data[3][0], "lelelelelelele", "lalalala", "5");
	
	i = 0;
	while (i < TEST_CASES)
	{
		printf("test %i\n", i);
		ft_get_values(&data[i][0], &dest, &src, &n);
		time(&start_t);
		strcpy(your_result, dest);
		strcpy(actual_answer, dest);
		ft_strncpy(your_result, src, n[0] - '0');
		time(&end_t);
		strncpy(actual_answer, src, n[0] - '0');
		diff_t = difftime(end_t, start_t);
		printf("dest: %s, src: %s, n: %i, your_result: %s, actual_answer: %s, execution time = %f\n", dest, src, n[0] - '0', your_result, actual_answer, diff_t);
		if (strcmp(your_result, actual_answer))
			FAKE_N_GAY;
		if (diff_t >= 2.0)
			SNAIL;
		++i;
	}
	GOES;
}
