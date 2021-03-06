/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/08/06 21:32:00 by dda-silv          #+#    #+#             */
/*   Updated: 2014/08/06 21:32:02 by dda-silv         ###   ########.fr       */
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

char    *ft_strcapitalize(char *str);

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
	char *answer;
	char your_result[300];
	int i;

	ft_add_test_case(&data[0][0], "Je Code avec le CUL", "Je Code Avec Le Cul");
	ft_add_test_case(&data[1][0], "U MAD BRO", "U Mad Bro");
	ft_add_test_case(&data[2][0], "", "");
	ft_add_test_case(&data[3][0], "salut, comment tu vas ? 42mots quarante-deux; cinquante+et+un", "Salut, Comment Tu Vas ? 42mots Quarante-Deux; Cinquante+Et+Un");
	
	i = 0;
	while (i < TEST_CASES)
	{
		ft_get_values(&data[i][0], &original, &answer);
		strcpy(your_result, original);
		time(&start_t);
		ft_strcapitalize(your_result);
		time(&end_t);
		diff_t = difftime(end_t, start_t);
		printf("original: %s, your_result: %s, actual_result: %s, execution time = %f\n", original, your_result, answer, diff_t);
		if (strcmp(your_result,answer) != 0)
			FAKE_N_GAY;
		if (diff_t >= 2.0)
			SNAIL;
		++i;
	}
	GOES;
}