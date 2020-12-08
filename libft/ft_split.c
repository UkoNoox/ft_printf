/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugdaniel <ugdaniel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 12:05:25 by ugdaniel          #+#    #+#             */
/*   Updated: 2020/11/23 16:30:10 by ugdaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	words(char const *s, char c)
{
	int		i;
	int		words;

	i = 0;
	while (s[i] && s[i] == c)
		i++;
	words = 0;
	while (s[i])
	{
		if (s[i] == c)
			i++;
		else
		{
			words++;
			while (s[i] != c && s[i])
				i++;
		}
	}
	return (words);
}

static int			len_to_sep(const char *s, char c, unsigned int i)
{
	int		len;

	len = 0;
	while (s[i + len] && s[i + len] != c)
		len++;
	return (len);
}

static void			*free_tab(char **tab, unsigned int max)
{
	unsigned int		i;

	i = 0;
	while (i < max)
		free(tab[i++]);
	free(tab);
	return (NULL);
}

char				**ft_split(char const *s, char c)
{
	char			**tab;
	unsigned int	i;
	unsigned int	j;
	unsigned int	k;

	if (!s || !(tab = (char**)malloc(sizeof(char*) * words(s, c) + 1)))
		return (NULL);
	i = 0;
	j = 0;
	while (i < words(s, c))
	{
		while (s[j] == c && s[j])
			j++;
		if (!(tab[i] = (char*)malloc(sizeof(char) * len_to_sep(s, c, j) + 1)))
			return (free_tab(tab, i));
		k = 0;
		while (s[j] && s[j] != c)
			if (s[j] != c)
				tab[i][k++] = s[j++];
		tab[i++][k] = '\0';
	}
	tab[i] = NULL;
	return (tab);
}
