/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_out_plus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugdaniel <ugdaniel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 19:59:09 by ugdaniel          #+#    #+#             */
/*   Updated: 2020/12/10 15:55:09 by ugdaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static char	*get_temp(int size)
{
	char	*temp;

	if (!(temp = (char*)malloc(sizeof(char) * size + 1)))
		return (NULL);
	ft_memset(temp, '0', size);
	temp[size] = '\0';
	return (temp);
}

static char	*add_zeros_int2(t_flags *flags, int len, char *s, int size)
{
	char	*temp;

	if (!(temp = get_temp(size)))
		return (s);
	if ((len < flags->precision || len < flags->width) && temp)
	{
		if (s[0] == '-')
		{
			if (flags->flags[FLAG_PREC])
			{
				s[0] = '0';
				temp = ft_strjoin("-", temp);
			}
			else if (flags->width)
			{
				temp = ft_strjoin("-", temp);
				s++;
			}
		}
		s = ft_strjoin(temp, s);
	}
	free(temp);
	return (s);
}

char		*add_zeros_int(t_flags *flags, char *s)
{
	int		len;
	int		size;

	if (!s)
		return (NULL);
	if (flags->flags[FLAG_PREC])
		size = flags->precision - ft_strlen(s);
	else
		size = flags->width - ft_strlen(s);
	size = size < 0 ? -size : size;
	if ((flags->flags[FLAG_MINUS] || flags->flags[FLAG_LEFT]) &&
		!flags->flags[FLAG_PREC])
		size = 0;
	if (size <= 0)
		return (s);
	if (flags->flags[FLAG_PREC] && flags->precision < flags->width &&
		flags->precision < (int)ft_strlen(s))
		return (s);
	len = ft_strlen(s);
	if (s[0] == '-')
		len--;
	return (add_zeros_int2(flags, len, s, size));
}
