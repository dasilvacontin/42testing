/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/08/02 17:34:14 by dda-silv          #+#    #+#             */
/*   Updated: 2014/08/02 17:47:11 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <time.h>
#include <stdlib.h>
#include <stdio.h>

#define TAB_SIZE 100
#define TEST_COUNT 10

void	ft_sort_integer_table(int *tab, int size);

int		main(void)
{
	int tab[TAB_SIZE];
	int i;
	int t;

	srand(time(NULL));
	t = 0;
	while (t < TEST_COUNT)
	{
		i = 0;
		while (i < TAB_SIZE)
		{
			tab[i] = rand()%200 - 100;
			++i;
		}
		ft_sort_integer_table(tab, TAB_SIZE);
		i = 1;
		while (i < TAB_SIZE)
		{
			if (tab[i-1] > tab[i])
			{
				printf("FAKE AND GAY\n");
				return (0);
			}
			++i;
		}
		++t;
	}
	printf("CORRECT\n");
	return (0);
}
