/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/08/02 14:13:47 by dda-silv          #+#    #+#             */
/*   Updated: 2014/08/02 14:18:34 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_swap(int *a, int *b);

int		main(void)
{
	int a;
	int b;

	a = 1;
	b = 2;
	ft_swap(&a, &b);
	if (a == 2 && b == 1)
		printf("CORRECT\n");
	else
		printf("FAKE AND GAY\n");
	return (0);
}
