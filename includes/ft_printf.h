/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsticks <rsticks@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 14:59:55 by rsticks           #+#    #+#             */
/*   Updated: 2020/01/24 15:55:50 by rsticks          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdio.h>
# include "../libft/libft.h"
# include <stdarg.h>
# include <stddef.h>
# define ULLONG_MAX __LONG_LONG_MAX__*2ULL+1ULL
# define FLAG_MINUS 1
# define FLAG_SPACE 2
# define FLAG_PLUS	4
# define FLAG_SHARP 8
# define FLAG_NULL	16
# define MOD_H		32
# define MOD_HH		64
# define MOD_L		128
# define MOD_LL		256
# define MOD_LLL	512
# define FORM_D_I	1024
# define FORM_U		2048
# define FORM_X		4096
# define FORM_XX	8192
# define FORM_F		16384
# define FORM_E		32768
# define FORM_EE	65536
# define FORM_G		131072
# define FORM_AA	262144
# define FORM_A		524288
# define FORM_C		1048576
# define FORM_SS	2097152
# define FORM_S 	4194304
# define FORM_P 	8388608
# define FORM_N		16777216
# define FORM_O 	33554432
# define FORM_TRUE 	67108864
# define MODS_TRUE 	134217728
# define PRO_TRUE 	268435456
# define DOUBLE_PRO 536870912
# define DBL_INF 0x7FF0000000000000
# define DBL_NINF 0xFFF0000000000000
# define DBL_NAN 0x7FF0000000100000
# define DBL_PZERO 0x0000000000000000
# define DBL_NZERO 0x8000000000000000
# define LDBL_INF 0x7FFF
# define LDBL_NINF 0xFFFF0000000000000000L
# define LDBL_NAN 0x7FFF0000000001000000L
# define LDBL_PZERO 0x00000000000000000000L
# define LDBL_NZERO 0x80000000000000000000L

typedef struct				s_dec_to
{
	char					*c;
	char					*s;
	int						i;
	int						otc;
	int						j;
}							t_dec_to;

typedef struct				s_int
{
	short int				sh;
	int						in;
	long int				lin;
	long long int			llin;
	char					ch;
}							t_int;

typedef struct				s_flags
{
	char					minus;
	char					space;
	char					plus;
	char					sharp;
	char					null;
}							t_flags;

typedef	struct				s_printf
{
	char					herna;
	const char				*format;
	int						accuracy;
	va_list					arg;
	uint32_t				flags;
	int						d;
	char					c;
	int						count;
	int						width;
	char					*buff;
	t_int					st_int;
}							t_printf;

union						u_floats
{
	long double				f;
	struct					s_bits
	{
		unsigned long int	mant : 64;
		unsigned int		exp : 15;
		unsigned int		sign : 1;
	}						t_bits;

}							t_floats;

void						init_prnt(t_printf *prnt);
void						process_width_for_float(t_printf *prnt, char *c);
void						putstr_and_count(t_printf *prnt, char *c);
int							ft_udigits_count(unsigned long long int n);
char						*ft_ulong_itoa(unsigned long long int n);
void						ft_ptr_n(t_printf *prnt);
void						ft_ptr(t_printf *prnt);
void						ft_str(t_printf *prnt);
void						ft_char(t_printf *prnt);
void						unsigned_process_width(t_printf *prnt, char *c);
char						*x_modificator(t_printf *prnt);
void						x_intger(t_printf *prnt);
char						*o_modificator(t_printf *prnt);
void						o_intger(t_printf *prnt);
char						*ft_dec_to(unsigned long long int d,
							int sys, t_printf *prnt);
void						u_intger(t_printf *prnt);
void						process_width(t_printf *prnt, char *c);
char						*modificator(t_printf *prnt);
char						*u_modificator(t_printf *prnt);
char						*ft_long_itoa(long long int n);
int							ftft_digits_count(long long int n);
void						transform(t_printf *prnt);
void						ft_intger(t_printf *prnt);
int							mods(t_printf *prnt);
void						form(t_printf *prnt);
int							ft_printf(const char *format, ...);
int							ft_atoi_nb(const char *str, int *nb);
void						parser(t_printf *prnt);
int							countdigits(int n);
int							accuracy(t_printf *prnt);
int							flags(t_printf *prnt);
int							width(t_printf *prnt);
void						putchar_and_count(t_printf *prnt, char c);
void						if_procent(t_printf *prnt);
void						parser(t_printf *prnt);
int							ft_abs(int n);
void						mult_flt(int i, char *local);
void						add_to_flt(char *flt, int i, char *local, int exp);
void						bias_digit(char *flt, int i, int exp);
void						count_flt(char *flt, int exp, int bits);
char						*print_flt(int bits);
void						itg_mult(char *local, int i);
void						add_func(char *itg, int i);
char						*count_itg(int bits);
void						rounding_int_aft_flt(char *res, int i);
void						rounding_flt_4(char *res, int i, t_printf *prnt);
int							rounding_flt_3(char *res, char *flt, int i, int j);
char						*rounding_flt_2(char *itg,
							char *flt, t_printf *prnt);
char						*rounding_flt(char *itg, char *flt, t_printf *prnt);
char						*ft_flt(long double d, t_printf *prnt);
void						ft_flt_get(t_printf *prnt);
char						*modif_flt(t_printf *prnt);
char						*ft_strrev(char *str);
void						first_bias(char *flt, int bits, int exp);
char						*ft_if_negative(char *res);
char						*big_int(char *itg, t_printf *prnt);
char						*not_num(char *c, t_printf *prnt);

#endif
