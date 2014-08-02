/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/08/02 12:52:35 by dda-silv          #+#    #+#             */
/*   Updated: 2014/08/02 13:26:27 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_ultimate_div_mod(int *a, int *b);

int		main(void)
{
	int a;
	int b;
	int copya;
	int copyb;

	a = 10;
	copya = a;
	b = 3;
	copyb = b;
	ft_ultimate_div_mod(&a, &b);
	printf("a(before): %i, b(before): %i, a(after): %i, b(after): %i\n", copya, copyb, a, b);
	if (copya == copyb * a + b)
		printf("CORRECT\n");
	else
		printf("FAKE AND GAY\n");
	return (0);
}
