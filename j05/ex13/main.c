/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/08/06 22:49:03 by dda-silv          #+#    #+#             */
/*   Updated: 2014/08/06 22:49:05 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

#define GOES return printf("\e[0;32mGOES ✓\e[0m\n");
#define FAKE_N_GAY return printf("\e[0;31mFAKE AND GAY ✗\e[0m\n")
#define SNAIL return printf("\e[0;33mYOU ARE TOO SLOW! ✗\e[0m\n")

#define TEST_CASES 4

char	*ft_strcat(char *dest, char *src);

void	ft_add_test_case(char **data, char *dest, char *src)
{
	data[0] = dest;
	data[1] = src;
}

void	ft_get_values(char **data, char **dest, char **src)
{
	*dest = data[0];
	*src = data[1];
}

int		main(void)
{
	time_t 	start_t, end_t;
	double	diff_t;
	char *data[TEST_CASES][2];
	char *dest;
	char *src;
	char your_result[100];
	char actual_answer[100];
	int i;

	ft_add_test_case(&data[0][0], "asi;yabs;fj", "sdhdhsh");
	ft_add_test_case(&data[1][0], "", "AGU:HIAHOS:GSOI:gsio;");
	ft_add_test_case(&data[2][0], "", "");
	ft_add_test_case(&data[3][0], "ASFPHA w0l0l0 SHOF", "");
	
	i = 0;
	while (i < TEST_CASES)
	{
		ft_get_values(&data[i][0], &dest, &src);
		stpcpy(your_result, dest);
		stpcpy(actual_answer, dest);
		time(&start_t);
		ft_strcat(your_result, src);
		time(&end_t);
		strcat(actual_answer, src);
		diff_t = difftime(end_t, start_t);
		printf("dest: %s, src: %s, your_result: %s, actual_result: %s, execution time = %f\n", dest, src, your_result, actual_answer, diff_t);
		if (strcmp(your_result, actual_answer))
			FAKE_N_GAY;
		if (diff_t >= 2.0)
			SNAIL;
		++i;
	}
	GOES;
}