/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsticks <rsticks@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 14:59:55 by rsticks           #+#    #+#             */
/*   Updated: 2019/11/05 19:40:00 by rsticks          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdio.h>
# include "../libft/libft.h"
# include <stdarg.h>

# define FLAG_MINUS (1 << 0)
# define FLAG_SPACE (1 << 1)
# define FLAG_PLUS (1 << 2)
# define FLAG_SHARP (1 << 3)
# define FLAG_NULL (1 << 4)


typedef struct	s_flags
{
	char		minus;
	char		space;
	char		plus;
	char		sharp;
	char		null;
}				t_flags;

typedef	struct		s_printf
{
	const char		*format;
	va_list			arg;
	uint32_t		flags;
	int				d;
	char			c;
	int				count;
	int				width;
	char			*buff;
}					t_printf;

int					ft_printf(const char *format, ...);
void				parser(t_printf *prnt);
#endif