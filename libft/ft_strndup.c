/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugdaniel <ugdaniel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 13:44:14 by ugdaniel          #+#    #+#             */
/*   Updated: 2020/12/05 19:10:04 by ugdaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s, unsigned int n)
{
	char	*d;

	if (n > ft_strlen(s))
		return (NULL);
	if (!(d = (char*)malloc(sizeof(char) * n)))
		return (NULL);
	return ((char*)ft_memcpy(d, s, n));
}
