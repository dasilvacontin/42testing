/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/08/02 14:07:54 by dda-silv          #+#    #+#             */
/*   Updated: 2014/08/02 14:12:49 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int		ft_strlen(char *str);

int		main(void)
{
	char str[] = "w0l0l0";
	int len;
	len = ft_strlen(str);
	printf("Your function says that '%s' has length %i, and that is...\n", str, len);
	if (len == 6)
		printf("CORRECT\n");
	else
		printf("FAKE AND GAY\n");
	return (0);
}
