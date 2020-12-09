/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugdaniel <ugdaniel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 17:06:59 by ugdaniel          #+#    #+#             */
/*   Updated: 2020/12/09 20:10:23 by ugdaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static char	*check_ptr(t_flags *flags, char *s)
{
	char	*dest;

	if (flags->specs[SPEC_PTR] || flags->flags[FLAG_HASH])
	{
		if (flags->flags[FLAG_UPPER])
			dest = ft_strjoin("0X", s);
		else
			dest = ft_strjoin("0x", s);
	}
	else
		dest = ft_strdup(s);
	free(s);
	return (dest);
}

char		*ft_itoa_hex(t_flags *flags, long value, int base)
{
	char	*s;
	int		size;
	char	*tab;
	long	tmp;

	tab = "0123456789abcdef";
	if (flags->flags[FLAG_UPPER])
		tab = "0123456789ABCDEF";
	tmp = value;
	size = 0;
	while (tmp /= base)
		size++;
	size = size + 1;
	if (!(s = (char *)malloc(sizeof(char) * size + 1)))
		return (NULL);
	s[size] = '\0';
	while (size > 0)
	{
		s[size - 1] = tab[value % base];
		size--;
		value /= base;
	}
	return (check_ptr(flags, s));
}

int			check_prec_zero(t_flags *flags, va_list args)
{
	va_list args2;

	va_copy(args2, args);
	if (!flags->specs[SPEC_INT] && !flags->specs[SPEC_UINT] &&
		!flags->specs[SPEC_HEX] && !flags->specs[SPEC_PTR] &&
		flags->precision == 0 && flags->flags[FLAG_PREC])
	{
		if (va_arg(args2, int) == 0 && flags->width == 0)
		{
			va_end(args2);
			return (1);
		}
	}
	else if (flags->precision == 0 && flags->flags[FLAG_PREC])
	{
		va_copy(args2, args);
		if (va_arg(args2, int) == 0 && !flags->specs[SPEC_PTR])
		{
			va_end(args2);
			return (1);
		}
	}
	va_end(args2);
	return (0);
}
