/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsticks <rsticks@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 14:59:55 by rsticks           #+#    #+#             */
/*   Updated: 2019/11/08 15:47:56 by rsticks          ###   ########.fr       */
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

# define MOD_H (1 << 5)
# define MOD_HH (1 << 6)
# define MOD_L (1 << 7)
# define MOD_LL (1 << 8)
# define MOD_LLL (1 << 10)

# define FORM_D_I (1 << 11)
# define FORM_U (1 << 12)
# define FORM_X (1 << 13)
# define FORM_x (1 << 14)
# define FORM_F (1 << 15)
# define FORM_E (1 << 16)
# define FORM_e (1 << 17)
# define FORM_G (1 << 18)
# define FORM_a (1 << 19)
# define FORM_A (1 << 20)
# define FORM_C (1 << 21)
# define FORM_s (1 << 22)
# define FORM_S (1 << 23)
# define FORM_P (1 << 24)
# define FORM_N (1 << 25)

# define FORM_TRUE (1 << 26)
# define MODS_TRUE (1 << 27)

typedef struct		s_flags
{
	char			minus;
	char			space;
	char			plus;
	char			sharp;
	char			null;
}					t_flags;

typedef	struct		s_printf
{
	const char		*format;
	int				accuracy;
	va_list			arg;
	uint32_t		flags;
	int				d;
	char			c;
	int				count;
	int				width;
	char			*buff;
}					t_printf;

int					mods(t_printf *prnt);
void				form(t_printf *prnt);
int					ft_printf(const char *format, ...);
int					ft_atoi_nb(const char *str, int *nb);
void				parser(t_printf *prnt);
int					countdigits(int n);
int					accuracy(t_printf *prnt);
int					flags(t_printf *prnt);
int					width(t_printf *prnt);
void				putchar_and_count(t_printf *prnt, char c);
void				if_procent(t_printf *prnt);
void				parser(t_printf *prnt);

#endif