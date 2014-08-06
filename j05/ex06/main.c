/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/08/06 20:48:43 by dda-silv          #+#    #+#             */
/*   Updated: 2014/08/06 20:48:45 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

#define GOES return printf("\e[0;32mGOES ✓\e[0m\n");
#define FAKE_N_GAY return printf("\e[0;31mFAKE AND GAY ✗\e[0m\n")
#define SNAIL return printf("\e[0;33mYOU ARE TOO SLOW! ✗\e[0m\n")

#define TEST_CASES 5

char	*strlowcase(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		str[i] = tolower(str[i]);
		++i;
	}
	return (str);
}

char	*ft_strlowcase(char *str);

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
	char your_result[300];
	char actual_result[300];
	char master_test[300];
	int i;

	ft_add_test_case(&data[0], "Je Code avec le CUL");
	ft_add_test_case(&data[1], "U MAD BRO");
	ft_add_test_case(&data[2], "");
	ft_add_test_case(&data[3], "iBI^7toBO&*TYUIbb7");
	ft_add_test_case(&data[4], master_test);

	i = 21;
	while (i < 255)
	{
		master_test[i-21] = i;
		++i;
	}
	master_test[i-21] = '\0';
	
	i = 0;
	while (i < TEST_CASES)
	{
		ft_get_values(&data[i], &str);
		strcpy(your_result, str);
		strcpy(actual_result, str);
		time(&start_t);
		ft_strlowcase(your_result);
		time(&end_t);
		strlowcase(actual_result);
		diff_t = difftime(end_t, start_t);
		printf("str: %s, your_result: %s, actual_result: %s, execution time = %f\n", str, your_result, actual_result, diff_t);
		if (strcmp(your_result,actual_result) != 0)
			FAKE_N_GAY;
		if (diff_t >= 2.0)
			SNAIL;
		++i;
	}
	GOES;
}