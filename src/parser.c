/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsticks <rsticks@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 18:42:14 by rsticks           #+#    #+#             */
/*   Updated: 2019/11/06 18:24:14 by rsticks          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void					form(t_printf *prnt)
{
	if (*prnt->format == 'd' || *prnt->format == 'i')
		prnt->flags |= FORM_D_I;
	if (*prnt->format == 'u')
		prnt->flags == FORM_U;
	if (*prnt->format == 'X')
		prnt->flags == FORM_X;
	if (*prnt->format == 'x')
		prnt->flags == FORM_x;
	if (*prnt->format == 'F' || *prnt->format == 'f')
		prnt->flags == FORM_F;
	if (*prnt->format == 'E')
		prnt->flags == FORM_E;
	if (*prnt->format == 'e')
		prnt->flags == FORM_e;
	if (*prnt->format == 'g' || *prnt->format == 'G')
		prnt->flags == FORM_G;
	if (*prnt->format == 'a')
		prnt->flags == FORM_a;
	if (*prnt->format == 'A')
		prnt->flags == FORM_A;
	if (*prnt->format == 'c')
		prnt->flags == FORM_C;
	if (*prnt->format == 's')
		prnt->flags == FORM_s;
	if (*prnt->format == 'S')
		prnt->flags == FORM_S;
	if (*prnt->format == 'p')
		prnt->flags == FORM_P;
	if (*prnt->format == 'n')
		prnt->flags == FORM_N;
}

void					mods(t_printf *prnt)
{
	if (*prnt->format == 'h')
	{
		prnt->format++;
		if (*prnt->format == 'h')
		{
			prnt->flags |=  MOD_HH;
		}
		else
		{
			prnt->flags |= 	MOD_H;
		}
	}
	if (*prnt->format == 'l')
	{
		prnt->format++;
		if (*prnt->format == 'l')
		{
			prnt->flags |=  MOD_LL;
		}
		else
		{
			prnt->flags |= 	MOD_L;
		}
	}
	if (*prnt->format == 'L')
		prnt->flags |= 	MOD_LLL;	
}

int						countdigits(int n)
{
	int i;

	i = 0;
	if (n < 0)
		i++;
	
	while (n)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

void					accuracy(t_printf *prnt)
{
	int tmp;

	tmp = 0;
	if (*prnt->format == '.')
	{
		prnt->format++;
		prnt->accuracy = ft_atoi_nb(prnt->format, &tmp);
		prnt->format += tmp;
	}
}

void					flags(t_printf *prnt)
{
	if (*prnt->format == '-')
		prnt->flags |= FLAG_MINUS;
	if (*prnt->format == ' ')
		prnt->flags |= FLAG_SPACE;
	if (*prnt->format == '+')
		prnt->flags |= FLAG_PLUS;
	if (*prnt->format == '#')
		prnt->flags |= FLAG_SHARP;
	if (*prnt->format == '0')
		prnt->flags |= FLAG_NULL;
}

void					width(t_printf *prnt)
{
	int tmp;

	tmp = 0;
	if (*prnt->format >= '0' && *prnt->format <= '9')
	{
		prnt->width = ft_atoi_nb(prnt->format, &tmp);
		prnt->format += tmp;
	}
}


void					putchar_and_count(t_printf *prnt, char c)
{
	prnt->buff[prnt->count] = c;
	prnt->count++;
}


int						ft_atoi_nb(const char *str, int *nb)
{
	struct s_atoi a;

	a.nb = 0;
	a.m = 1;
	a.i = 0;
	a.g = 0;
	while (str[a.i] == '\t' || str[a.i] == '\n' || str[a.i] == '\v'
			|| str[a.i] == '\f' || str[a.i] == ' '
			|| str[a.i] == '\r')
		a.i++;
	if (str[a.i] == '-' || str[a.i] == '+')
		if (str[a.i++] == '-')
			a.m = -1;
	while (str[a.i + a.g] >= '0' && str[a.i + a.g] <= '9')
	{
		a.nb = a.nb * 10 + (str[a.i + a.g] - '0');
		a.g++;
	}
	*nb = a.g;
	if ((a.nb <= 9223372036854775807) && (a.g <= 19))
		return (((int)a.nb) * a.m);
	else if (a.m > 0)
		return (-1);
	return (0);
}

void		*if_procent(t_printf *prnt)
{
	int			temp;

	temp = 0;
	
	
	while (*prnt->format != '\0' || *prnt->format != '%')
	{
		flags(prnt);
		width(prnt);
		accuracy(prnt);
		mods(prnt);
		if (!(FORM_TRUE == prnt->flags & FORM_TRUE))
			form(prnt);
		if (*prnt->format != '\0' && *prnt->format != '%')
			prnt->format++;
	}
}