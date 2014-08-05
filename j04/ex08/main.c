/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/08/05 13:47:00 by dda-silv          #+#    #+#             */
/*   Updated: 2014/08/05 14:13:06 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int		ft_eight_queens_puzzle(void);

int		main(void)
{
	printf("Your programe says that there are %i combinations.\n", ft_eight_queens_puzzle());
	return (0);
}
