/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putrstr_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugdaniel <ugdaniel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 14:37:09 by ugdaniel          #+#    #+#             */
/*   Updated: 2020/11/27 01:15:43 by ugdaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putrstr_fd(char *s, int fd)
{
	char	*t;

	if (s)
	{
		t = s + ft_strlen(s) - 1;
		while (t >= s)
			ft_putchar_fd(*t--, fd);
	}
}
