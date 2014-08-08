/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/08/08 15:25:31 by dda-silv          #+#    #+#             */
/*   Updated: 2014/08/08 15:25:33 by dda-silv         ###   ########.fr       */
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

#define TEST_CASES 7

char	**ft_split_whitespaces(char *str);

void	ft_add_test_case(char **data, char *str, char *nl)
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
	time_t 	start_t, end_t;
	double	diff_t;
	char *data[TEST_CASES][2];
	char *str;
	char *nl;
	char **your_result;
	int i;
	int j;

	ft_add_test_case(&data[0][0], "Je Code avec le CUL", "5");
	ft_add_test_case(&data[1][0], "      U MAD BRO     ", "3");
	ft_add_test_case(&data[2][0], "", "0");
	ft_add_test_case(&data[3][0], "       iBI^7 	 			 toBO&*TY UIbb7", "3");
	ft_add_test_case(&data[4][0], "aaa aa aaa", "3");
	ft_add_test_case(&data[5][0], "bb  		 bb bbb 	 b", "4");
	ft_add_test_case(&data[6][0], "sdg  ssdg 	 sdgSDG", "3");
	
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