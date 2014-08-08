/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/08/08 22:57:55 by dda-silv          #+#    #+#             */
/*   Updated: 2014/08/08 22:57:58 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

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

int		j;
char	*your_result;

void	ft_putchar(char c)
{
	your_result[j++] = c;
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

void	ft_print_words_tables(char **tab);

void	ft_add_test_case(char **data, char *str, char *actual)
{
	data[0] = str;
	data[1] = actual;
}

void	ft_get_values(char **data, char **str, char **actual)
{
	*str = data[0];
	*actual = data[1];
}

int		main(void)
{
	time_t 	start_t, end_t;
	double	diff_t;
	char *data[TEST_CASES][2];

	char 	*str;
	char	**tab;
	char	*actual_answer;
	int		i;

	ft_add_test_case(&data[0][0], "a b c", "a\nb\nc\n");
	ft_add_test_case(&data[1][0], "", "");
	ft_add_test_case(&data[2][0], "364", "364\n");
	
	i = 0;
	while (i < TEST_CASES)
	{
		ft_get_values(&data[i][0], &str, &actual_answer);
		tab = ft_split_whitespaces(str);
		j = 0;
		your_result = (char*)malloc(sizeof(char)*100);
		time(&start_t);
		ft_print_words_tables(tab);
		time(&end_t);
		ft_putchar('\0');
		diff_t = difftime(end_t, start_t);
		printf("tab: %s, your_result:\n%s, actual_answer:\n%s, execution time = %f\n", str, your_result, actual_answer, diff_t);
		if (strcmp(your_result, actual_answer) != 0)
			FAKE_N_GAY;
		if (diff_t >= 2.0)
			SNAIL;
		++i;
	}
	GOES;
}