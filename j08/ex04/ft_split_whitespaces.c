/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fft_split_whitespaces.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/08/08 13:07:55 by dda-silv          #+#    #+#             */
/*   Updated: 2014/08/08 15:10:46 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int		fft_is_delimeter(char c)
{
	return (c == ' ' || c == '\0' || c == '	' || c == '\n');
}

char	*fft_strcpy(char *dest, char *src)
{
	int i;

	i = 0;
	while (!fft_is_delimeter(src[i]))
	{
		dest[i] = src[i];
		++i;
	}
	dest[i] = src[i];
	return (dest);
}

int		fft_advance(char **str)
{
	while (!fft_is_delimeter(**str))
		++(*str);
	return (1);
}

void	fft_advance_whitespace(char **str)
{
	while (**str && fft_is_delimeter(**str))
		++(*str);
}

char	**ft_split_whitespaces(char *str)
{
	char	**tab;
	char	*ptr;
	int		words;

	words = 0;
	ptr = str;
	while (*ptr != '\0')
	{
		fft_advance_whitespace(&ptr);
		words += fft_advance(&ptr);
		fft_advance_whitespace(&ptr);
	}
	tab = (char**)malloc(sizeof(tab) * words + 1);
	words = 0;
	while (*str)
	{
		fft_advance_whitespace(&str);
		ptr = str;
		fft_advance(&str);
		tab[words] = (char*)malloc(sizeof(char) * (str - ptr) + 1);
		fft_strcpy(tab[words], ptr);
		tab[words++][str - ptr] = '\0';
		fft_advance_whitespace(&str);
	}
	return (tab);
}
