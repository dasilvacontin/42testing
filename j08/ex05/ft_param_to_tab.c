/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fft_param_to_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/08/11 21:10:07 by dda-silv          #+#    #+#             */
/*   Updated: 2014/08/11 23:27:12 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_par.h"
#include <stdlib.h>

char				**ft_split_whitespaces(char *str);

int					fft_strlen(char *str)
{
	int len;

	len = 0;
	while (str[len])
		++len;
	return (len);
}

char				*ffft_strcpy(char *dest, char *src)
{
	int i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		++i;
	}
	dest[i] = src[i];
	return (dest);
}

char				*fft_strdup(char *src)
{
	char	*cpy;

	cpy = (char*)malloc(sizeof(char) * (fft_strlen(src) + 1));
	return (cpy == 0 ? cpy : ffft_strcpy(cpy, src));
}

void				fft_init_param_in_tab(t_stock_par *tab, char *str)
{
	tab->size_param = fft_strlen(str);
	tab->str = str;
	tab->copy = fft_strdup(str);
	tab->tab = ft_split_whitespaces(str);
}

struct	s_stock_par	*ft_param_to_tab(int ac, char **av)
{
	t_stock_par	*tab;
	int			i;

	tab = (t_stock_par*)malloc(sizeof(t_stock_par) * (ac + 1));
	if (tab == 0)
		return (tab);
	i = -1;
	while (++i < ac)
		fft_init_param_in_tab(&(tab[i]), av[i]);
	tab[i].str = 0;
	return (tab);
}
