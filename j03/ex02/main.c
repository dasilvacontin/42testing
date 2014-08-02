/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/08/02 12:45:18 by dda-silv          #+#    #+#             */
/*   Updated: 2014/08/02 12:50:34 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_div_mod(int a, int b, int *div, int *mod);

int		main(void)
{
	int a;
	int b;
	int div;
	int mod;

	a = 10;
	b = 3;
	ft_div_mod(a, b, &div, &mod);
	printf("a: %i, b: %i, div: %i, mod: %i\n", a, b, div, mod);
	if (a == b * div + mod)
		printf("CORRECT\n");
	else
		printf("FAKE AND GAY\n");
	return (0);
}
