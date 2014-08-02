/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/08/02 14:19:33 by dda-silv          #+#    #+#             */
/*   Updated: 2014/08/02 14:40:02 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strrev(char *str);

int		main(void)
{
	char 	str[] = "w0l0l0";
	char 	strrev[] = "0l0l0w";
	char 	*test;
	int		i;

	test = ft_strrev(str);
	i = 0;
	while (strrev[i] != '\0')
	{
		if (strrev[i] != test[i])
		{
			printf("FAKE AND GAY\n");
			return (0);
		}
		++i;
	}
	printf("CORRECT\n");
	return (0);
}
