/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/08/02 14:40:37 by dda-silv          #+#    #+#             */
/*   Updated: 2014/08/02 17:27:27 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int		ft_atoi(char *str);

int		main(void)
{
	char 	*test_str[10];
	int		t;
	int 	nbr_atoi;
	int		nbr_ft_atoi;

	test_str[0] = "2362";
	test_str[1] = "000";
	test_str[2] = "0";
	test_str[3] = "-00";
	test_str[4] = "678nsaf9n8";
	test_str[5] = "fsd23";
	test_str[6] = "-f32";
	test_str[7] = "7957";
	test_str[8] = "";
	test_str[9] = "-";
	t = 0;
	while (t < 10)
	{
		nbr_atoi = atoi(test_str[t]);
		nbr_ft_atoi = ft_atoi(test_str[t]);
		printf("string: %s, atoi: %i, ft_atoi: %i\n", test_str[t], nbr_atoi, nbr_ft_atoi);
		if (nbr_atoi != nbr_ft_atoi)
		{
			printf("FAKE AND GAY\n");
			return (0);
		}
		++t;
	}
	printf("CORRECT\n");
	return (0);
}
