/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/08/05 21:16:44 by dda-silv          #+#    #+#             */
/*   Updated: 2014/08/05 21:20:06 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_putchar(char c)
{
	write(1, &c, 1);
	return (0);
}

void	ft_eight_queens_puzzle_2(void);

int		main(void)
{
	ft_eight_queens_puzzle_2();
	return (0);
}
