/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/08/08 17:11:29 by dda-silv          #+#    #+#             */
/*   Updated: 2014/08/08 17:11:30 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int		ft_is_delimeter(char c)
{
	return (c == ' ' || c == '\0' || c == '	' || c == '\n');
}

char	*fft_strcpy(char *dest, char *src)
{
	int i;

	i = 0;
	while (!ft_is_delimeter(src[i]))
	{
		dest[i] = src[i];
		++i;
	}
	dest[i] = src[i];
	return (dest);
}

int		ft_advance(char **str)
{
	while (!ft_is_delimeter(**str))
		++(*str);
	return (1);
}

void	ft_advance_whitespace(char **str)
{
	while (**str && ft_is_delimeter(**str))
		++(*str);
}

char	**ft_split_whitespaces(char *str)
{
	char	**tab;
	char	*ptr;
	int		words;

	words = 0;
	ptr = str;
	while (*ptr != '\0')
	{
		ft_advance_whitespace(&ptr);
		words += ft_advance(&ptr);
		ft_advance_whitespace(&ptr);
	}
	tab = (char**)malloc(sizeof(tab) * words + 1);
	words = 0;
	while (*str)
	{
		ft_advance_whitespace(&str);
		ptr = str;
		ft_advance(&str);
		tab[words] = (char*)malloc(sizeof(char) * (str - ptr) + 1);
		fft_strcpy(tab[words], ptr);
		tab[words++][str - ptr] = '\0';
		ft_advance_whitespace(&str);
	}
	return (tab);
}

#include <stdio.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define GOES return printf("\e[0;32mGOES ✓\e[0m\n");
#define FAKE_N_GAY return printf("\e[0;31mFAKE AND GAY ✗\e[0m\n")
#define SNAIL return printf("\e[0;33mYOU ARE TOO SLOW! ✗\e[0m\n")

#define TEST_CASES 3

char	*ft_concat_params(int argc, char **argv);

void	ft_add_test_case(char **data, char *argc, char *argv, char *actual)
{
	data[0] = argc;
	data[1] = argv;
	data[2] = actual;
}

void	ft_get_values(char **data, char **argc, char **argv, char **actual)
{
	*argc = data[0];
	*argv = data[1];
	*actual = data[2];
}

int		main(void)
{
	time_t 	start_t, end_t;
	double	diff_t;
	char *data[TEST_CASES][3];

	char 	*c_argc;
	int		argc;

	char 	*c_argv;
	char	**argv;
	char	*your_result;
	char	*actual_answer;
	int		i;

	ft_add_test_case(&data[0][0], "4", "./a.out a b c", "a\nb\nc");
	ft_add_test_case(&data[1][0], "1", "./a.out", "");
	ft_add_test_case(&data[2][0], "2", "./a.out 364", "364");
	
	i = 0;
	while (i < TEST_CASES)
	{
		ft_get_values(&data[i][0], &c_argc, &c_argv, &actual_answer);
		argc = c_argc[0] - '0';
		argv = ft_split_whitespaces(c_argv);
		time(&start_t);
		your_result = ft_concat_params(argc, argv);
		time(&end_t);
		diff_t = difftime(end_t, start_t);
		printf("argc: %i, argv: %s, execution time = %f\n", argc, c_argv, diff_t);
		printf("your answer:\n%s\nactual answer:\n%s\n",your_result, actual_answer);
		if (strcmp(your_result, actual_answer) != 0)
			FAKE_N_GAY;
		if (diff_t >= 2.0)
			SNAIL;
		++i;
	}
	GOES;
}