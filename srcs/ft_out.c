/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_out.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugdaniel <ugdaniel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 18:06:46 by ugdaniel          #+#    #+#             */
/*   Updated: 2020/12/10 17:17:19 by ugdaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static char	*add_spaces(t_flags *flags, char *s, int size)
{
	char	*temp;
	char	*dest;

	if (!s || size < 0)
		return (s);
	if (!(temp = (char*)malloc(sizeof(char) * size + 1)))
		return (s);
	temp = ft_memset(temp, ' ', size);
	temp[size] = '\0';
	dest = s;
	if (!flags->flags[FLAG_LEFT] && !flags->flags[FLAG_MINUS])
		dest = ft_strjoin(temp, s);
	else if (flags->flags[FLAG_LEFT] || flags->flags[FLAG_MINUS])
		dest = ft_strjoin(s, temp);
	free(temp);
	free(s);
	return (dest);
}

char		*add_padding(t_flags *fl, char *s)
{
	if (fl->flags[FLAG_PREC] && fl->precision < (int)ft_strlen(s) &&
		(fl->specs[SPEC_CHAR] || fl->specs[SPEC_STR]))
		s = ft_strncpy(s, s, fl->precision);
	if (fl->specs[SPEC_INT] || fl->specs[SPEC_UINT] ||
		fl->specs[SPEC_HEX] || fl->specs[SPEC_PCENT])
	{
		if (fl->flags[FLAG_PREC] || fl->flags[FLAG_ZERO])
			s = add_zeros_int(fl, s);
		if (fl->width > (int)ft_strlen(s))
			s = add_spaces(fl, s, fl->width - ft_strlen(s));
	}
	else if (fl->specs[SPEC_CHAR] || fl->specs[SPEC_STR] ||
			fl->specs[SPEC_PTR] || fl->specs[SPEC_PCENT])
	{
		if (fl->flags[FLAG_ZERO])
			s = add_zeros_int(fl, s);
		if (fl->width)
			s = add_spaces(fl, s, fl->width - ft_strlen(s));
	}
	return (s);
}

int			out(t_flags *flags, char *s, int fd)
{
	int		ret;
	int		len;

	ret = 0;
	len = ft_strlen(s);
	if (flags->specs[SPEC_CHAR] && *s == '\0')
	{
		s = add_padding(flags, s);
		write(1, s, len + 1);
		free(s);
		return (1);
	}
	s = add_padding(flags, s);
	ft_putstr_fd(s, fd);
	ret += ft_strlen(s);
	free(s);
	return (ret);
}
