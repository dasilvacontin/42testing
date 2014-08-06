/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/08/06 22:08:16 by dda-silv          #+#    #+#             */
/*   Updated: 2014/08/06 22:08:17 by dda-silv         ###   ########.fr       */
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

int		ft_str_is_lowercase(char *str);

void	ft_add_test_case(char **data, char *original, char *answer)
{
	data[0] = original;
	data[1] = answer;
}

void	ft_get_values(char **data, char **original, char **answer)
{
	*original = data[0];
	*answer = data[1];
}

int		main(void)
{
	time_t 	start_t, end_t;
	double	diff_t;
	char *data[TEST_CASES][2];
	char *original;
	int your_result;
	char *answer;
	int i;

	ft_add_test_case(&data[0][0], "jecodeavecleCUL", "0");
	ft_add_test_case(&data[1][0], "235UMA 346DBRO", "0");
	ft_add_test_case(&data[2][0], "", "1");
	ft_add_test_case(&data[3][0], "aflibgaius", "1");
	
	i = 0;
	while (i < TEST_CASES)
	{
		ft_get_values(&data[i][0], &original, &answer);
		time(&start_t);
		your_result = ft_str_is_lowercase(original);
		time(&end_t);
		diff_t = difftime(end_t, start_t);
		printf("str: %s, your_result: %i, actual_result: %i, execution time = %f\n", original, your_result, answer[0] - '0', diff_t);
		if (your_result != answer[0] - '0')
			FAKE_N_GAY;
		if (diff_t >= 2.0)
			SNAIL;
		++i;
	}
	GOES;
}