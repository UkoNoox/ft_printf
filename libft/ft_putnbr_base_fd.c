/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugdaniel <ugdaniel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 21:12:21 by ugdaniel          #+#    #+#             */
/*   Updated: 2020/12/01 13:48:21 by ugdaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	check_base(char *base)
{
	int		i;
	int		j;

	i = 0;
	if (!base)
		return (0);
	while (base[i])
	{
		j = 0;
		while (base[j])
		{
			if (base[j] == base[i] && i != j)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void			ft_putnbrbase_fd(int nbr, char *base, int fd)
{
	if (nbr * -1 - 1 == 2147483647 || !(check_base(base)))
		return ;
	if (nbr < 0)
	{
		nbr = nbr * -1;
		ft_putchar_fd('-', fd);
	}
	if (nbr / ft_strlen(base) != 0)
		ft_putnbrbase_fd(nbr / ft_strlen(base), base, fd);
	ft_putchar_fd(base[nbr % ft_strlen(base)], fd);
}
