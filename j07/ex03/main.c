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

char	*ft_strcpy(char *dest, char *src)
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
		ft_strcpy(tab[words], ptr);
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

#define TEST_CASES 1

char	*ft_concat_params(int argc, char **argv);

void	ft_add_test_case(char **data, char *c_argc, char *nl)
{
	data[0] = str;
	data[1] = nl;
}

void	ft_get_values(char **data, char **str, char **nl)
{
	*str = data[0];
	*nl = data[1];
}

int		main(void)
{
	time_t	start_t, end_t;
	double	diff_t;
	char	*data[TEST_CASES][3];

	char 	*c_argc;
	int		argc;

	char	*c_argv;
	char	**argv;

	char	*your_result
	char	*actual_result;

	int		i;
	int		j;

	ft_add_test_case(&data[0][0], "4", "./a.out a b c");
	
	i = 0;
	while (i < TEST_CASES)
	{
		ft_get_values(&data[i][0], &str, &nl);
		time(&start_t);
		your_result = ft_split_whitespaces(str);
		time(&end_t);
		diff_t = difftime(end_t, start_t);
		j = -1;
		printf("test string: %s\n", str);
		while (your_result[++j])
			printf("%s\n", your_result[j]);
		printf("your_words: %i, actual_words: %i, execution time = %f\n", j, nl[0]-'0', diff_t);
		if (j != nl[0]-'0')
			FAKE_N_GAY;
		if (diff_t >= 2.0)
			SNAIL;
		++i;
	}
	GOES;
}