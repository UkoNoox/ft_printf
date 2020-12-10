/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugdaniel <ugdaniel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 17:07:00 by ugdaniel          #+#    #+#             */
/*   Updated: 2020/12/11 00:11:30 by ugdaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/libft.h"

# include <stdlib.h>
# include <stdarg.h>

# include <stdio.h>

# define STDOUT		1

# define NB_SPECS	8
# define NB_FLAGS	8

# define SPEC_CHAR	0
# define SPEC_STR	1
# define SPEC_PTR	2
# define SPEC_INT	3
# define SPEC_UINT	4
# define SPEC_HEX	5
# define SPEC_PCENT	6
# define SPEC_NONE	7
# define FLAG_ZERO	0
# define FLAG_MINUS	1
# define FLAG_PLUS	2
# define FLAG_SPACE	3
# define FLAG_HASH	4
# define FLAG_LEFT	5
# define FLAG_PREC	6
# define FLAG_UPPER	7

typedef struct	s_flags
{
	unsigned int	specs[NB_SPECS];
	unsigned int	flags[NB_FLAGS];
	int				width;
	int				precision;
}				t_flags;

void			init_flags(t_flags *flags);
void			check_flags(t_flags *flags);

const char		*get_flags(const char *f, t_flags *flags, va_list va);

char			*ft_itoa_hex(t_flags *flags, long value, int base);
int				check_prec_zero(t_flags *flags, va_list args, int temp);

void			join(char *s1, char *s2);
void			join2(char *s1, char *s2);

char			*add_zeros_int(t_flags *flags, char *s);
int				out(t_flags *flags, char *s, int fd);

int				ft_printf(const char *format, ...);

#endif
