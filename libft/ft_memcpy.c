/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugdaniel <ugdaniel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 12:43:27 by ugdaniel          #+#    #+#             */
/*   Updated: 2020/12/09 15:28:24 by ugdaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char		*d;
	const char	*s;
	int			i;

	if (!src && !dest)
		return (NULL);
	d = dest;
	s = src;
	i = 0;
	while (n-- > 0)
	{
		d[i] = s[i];
		i++;
	}
	return (dest);
}
