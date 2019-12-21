/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjonella <tjonella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 14:59:55 by rsticks           #+#    #+#             */
/*   Updated: 2019/12/21 20:15:26 by tjonella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdio.h>
# include "../libft/libft.h"
# include <stdarg.h>
#include <stddef.h>

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
# define FORM_O (1 << 30)

# define FORM_TRUE (1 << 26)
# define MODS_TRUE (1 << 27)
# define PRO_TRUE (1 << 28)
# define DOUBLE_PRO (1 << 29)

typedef struct		s_int
{
	short int		sh;
	int				in;
	long int		lin;
	long long int	llin;
	char			ch;
}					t_int;

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
	t_int			st_int;
}					t_printf;

union				u_floats
{
	long double				f;
	struct					s_bits
	{
		unsigned long int	mant : 64;
		unsigned int		exp : 15;
		unsigned int		sign : 1;
	}						t_bits;

}							t_floats; 

void				putstr_and_count(t_printf *prnt, char *c);
int					ft_udigits_count(unsigned long long int n);
char				*ft_ulong_itoa(unsigned long long int n);
void				ft_ptr_n(t_printf *prnt);
void				ft_ptr(t_printf *prnt);
void				ft_str(t_printf *prnt);
void				ft_char(t_printf *prnt);
void				unsigned_process_width(t_printf *prnt, char *c);
char				*x_modificator(t_printf *prnt);
void				x_intger(t_printf *prnt);
char				*o_modificator(t_printf *prnt);
void				o_intger(t_printf *prnt);
char				*ft_dec_to(unsigned long long int d, int sys, t_printf *prnt);
void				u_intger(t_printf *prnt);
void				process_width(t_printf *prnt, char *c);
char				*modificator(t_printf *prnt);
char				*u_modificator(t_printf *prnt);
char				*ft_long_itoa(long long int n);
int					ftft_digits_count(long long int n);
void				transform(t_printf *prnt);
void				ft_intger(t_printf *prnt);
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

int		ft_abs(int n);
void	mult_flt(int i, char *local);
void	add_to_flt(char *flt, int i, char *local, int exp);
void	bias_digit(char *flt, int i, int exp);
void	count_flt(char *flt, int exp, int bits);
char	*print_flt(int bits);
void	itg_mult(char *local, int i);
void	add_func(char *itg, int i);
char	*count_itg(int bits);
void	rounding_int_aft_flt(char *res, int i);
void	rounding_flt_4(char *res, int i, int acc);
void	rounding_flt_3(char *res, char *flt, int i, int j, t_printf *prnt);
char	*rounding_flt_2(char *itg, char *flt, t_printf *prnt);
char	*rounding_flt(char *itg, char *flt, t_printf *prnt);
char	*ft_flt(long double d, t_printf *prnt);

void	ft_flt_get(t_printf *prnt);
char	*modif_flt(t_printf *prnt);

#endif