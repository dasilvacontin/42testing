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

#define TEST_CASES 3

char	*ft_strncpy(char *dest, char *src, unsigned int n);

void	ft_add_test_case(char **data, char *original, char *actual, char *n)
{
	data[0] = original;
	data[1] = actual;
	data[2] = n;
}

void	ft_get_values(char **data, char **original, char **actual, char **n)
{
	*original = data[0];
	*actual = data[1];
	*n = data[2];
}

int		main(void)
{
	time_t 	start_t, end_t;
	double	diff_t;
	char *data[TEST_CASES][3];
	char *original;
	char *wat;
	char actual[100];
	char *n;
	char string[100];
	int i;

	ft_add_test_case(&data[0][0], "je code avec le cul", "je co", "5");
	ft_add_test_case(&data[1][0], "u mad", "u mad", "9");
	ft_add_test_case(&data[2][0], "", "", "5");
	
	i = 0;
	while (i < TEST_CASES)
	{
		ft_get_values(&data[i][0], &original, &wat, &n);
		time(&start_t);
		ft_strncpy(string, original, n[0] - '0');
		time(&end_t);
		strncpy(actual, original, n[0] - '0');
		string[n[0] - '0'] = '\0';
		diff_t = difftime(end_t, start_t);
		printf("original: %s, n: %i, copy: %s, actual: %s, execution time = %f\n", original, n[0] - '0', string, actual, diff_t);
		if (strcmp(actual, string))
			FAKE_N_GAY;
		if (diff_t >= 2.0)
			SNAIL;
		++i;
	}
	GOES;
}
