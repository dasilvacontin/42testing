/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/08/06 23:06:08 by dda-silv          #+#    #+#             */
/*   Updated: 2014/08/06 23:06:10 by dda-silv         ###   ########.fr       */
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

char	*ft_strncat(char *dest, char *src, int nb);

void	ft_add_test_case(char **data, char *dest, char *src, char *nb)
{
	data[0] = dest;
	data[1] = src;
	data[2] = nb;
}

void	ft_get_values(char **data, char **dest, char **src, char **nb)
{
	*dest = data[0];
	*src = data[1];
	*nb = data[2];
}

int		main(void)
{
	time_t 	start_t, end_t;
	double	diff_t;
	char *data[TEST_CASES][3];
	char *dest;
	char *src;
	char *nb;
	char your_result[100];
	char actual_answer[100];
	int i;

	ft_add_test_case(&data[0][0], "asi;yabs;fj", "sdhdhsh", "4");
	ft_add_test_case(&data[1][0], "", "AGU:", "9");
	ft_add_test_case(&data[2][0], "", "", "3");
	ft_add_test_case(&data[3][0], "ASFPHA w0l0l0 SHOF", "", "6");
	
	i = 0;
	while (i < TEST_CASES)
	{
		ft_get_values(&data[i][0], &dest, &src, &nb);
		stpcpy(your_result, dest);
		stpcpy(actual_answer, dest);
		time(&start_t);
		ft_strncat(your_result, src, nb[0] - '0');
		time(&end_t);
		strncat(actual_answer, src, nb[0] - '0');
		diff_t = difftime(end_t, start_t);
		printf("dest: %s, src: %s, nb: %i, your_result: %s, actual_result: %s, execution time = %f\n", dest, src, nb[0] - '0', your_result, actual_answer, diff_t);
		if (strcmp(your_result, actual_answer))
			FAKE_N_GAY;
		if (diff_t >= 2.0)
			SNAIL;
		++i;
	}
	GOES;
}