/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/08/12 12:41:03 by dda-silv          #+#    #+#             */
/*   Updated: 2014/08/12 12:41:04 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_par.h"
#include <unistd.h>
#include <string.h>
#include <stdio.h>

int		buffer_index;
char	buffer[200];

void	ft_reset_buffer(void)
{
	int i;

	i = -1;
	while(++i < 200)
		buffer[i] = '\0';
	buffer_index = 0;
}

void	ft_putchar(char c)
{
	buffer[buffer_index++] = c;
	write(1, &c, 1);
}

struct	s_stock_par	*ft_param_to_tab(int ac, char **av);

void	ft_show_tab(struct s_stock_par *par);

int		main(void)
{
	char *av[5];

	printf("-> ./a.out\n");
	av[0] = "./a.out";
	av[1] = 0;

	ft_reset_buffer();
	ft_show_tab(ft_param_to_tab(1, av));
	if (strcmp(buffer, "./a.out\n7\n./a.out\n") != 0)
		return (1);

	ft_putchar('\n');

	printf("-> ./a.out \"are you mad bro\" \"smells fishy\"\n");
	av[1] = "are you mad bro";
	av[2] = "smells fishy";
	av[3] = 0;

	ft_reset_buffer();
	ft_show_tab(ft_param_to_tab(3, av));
	if (strcmp(buffer, "./a.out\n7\n./a.out\nare you mad bro\n15\nare\nyou\nmad\nbro\nsmells fishy\n12\nsmells\nfishy\n") != 0)
		return (1);
	return (0);
}