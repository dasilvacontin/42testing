/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/08/06 02:11:48 by dda-silv          #+#    #+#             */
/*   Updated: 2014/08/06 18:07:31 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <time.h>
#include <string.h>

#define GOES return printf("\e[0;32mGOES ✓\e[0m\n");
#define FAKE_N_GAY return printf("\e[0;31mFAKE AND GAY ✗\e[0m\n")
#define SNAIL return printf("\e[0;33mYOU ARE TOO SLOW! ✗\e[0m\n")

#define TEST_CASES 5

char	*ft_strcpy(char *dest, char *src);

int		main(void)
{
	time_t 	start_t, end_t;
	double	diff_t;
	char *data[TEST_CASES];
	char *original;
	char string[100];
	int i;

	data[0] = "je code avec le cul";
	data[1] = "u mad brah";
	data[2] = "euh";
	data[3] = "all your base are belong to us";
	data[4] = "raise your dongers ヽ༼ຈل͜ຈ༽ﾉ !!";
	
	i = 0;
	while (i < TEST_CASES)
	{
		original = data[i];
		time(&start_t);
		ft_strcpy(string, original);
		time(&end_t);
		diff_t = difftime(end_t, start_t);
		printf("original: %s, copy: %s, execution time = %f\n", original, string, diff_t);
		if (strcmp(original, string))
			FAKE_N_GAY;
		if (diff_t >= 2.0)
			SNAIL;
		++i;
	}
	GOES;
}
