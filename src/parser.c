/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsticks <rsticks@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 18:42:14 by rsticks           #+#    #+#             */
/*   Updated: 2019/12/05 18:09:05 by rsticks          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void					form(t_printf *prnt)
{
	uint32_t tmp;

	tmp = prnt->flags;
	if (*prnt->format == 'd' || *prnt->format == 'i')
		prnt->flags |= FORM_D_I;
	if (*prnt->format == 'u')
		prnt->flags |= FORM_U;
	if (*prnt->format == 'X')
		prnt->flags |= FORM_X;
	if (*prnt->format == 'x')
		prnt->flags |= FORM_x;
	if (*prnt->format == 'F' || *prnt->format == 'f')
		prnt->flags |= FORM_F;
	if (*prnt->format == 'E')
		prnt->flags |= FORM_E;
	if (*prnt->format == 'e')
		prnt->flags |= FORM_e;
	if (*prnt->format == 'g' || *prnt->format == 'G')
		prnt->flags |= FORM_G;
	if (*prnt->format == 'a')
		prnt->flags |= FORM_a;
	if (*prnt->format == 'A')
		prnt->flags |= FORM_A;
	if (*prnt->format == 'c')
		prnt->flags |= FORM_C;
	if (*prnt->format == 's')
		prnt->flags |= FORM_s;
	if (*prnt->format == 'S')
		prnt->flags |= FORM_S;
	if (*prnt->format == 'p')
		prnt->flags |= FORM_P;
	if (*prnt->format == 'n')
		prnt->flags |= FORM_N;
	if (tmp != prnt->flags)
		prnt->flags |= FORM_TRUE;
}

int					mods(t_printf *prnt)
{
	if (*prnt->format == 'h')
	{
		if (prnt->format[1] == 'h')
		{
			prnt->format++;
			prnt->flags |=  MOD_HH;
		}
		else
		{
			prnt->flags |= 	MOD_H;
		}
		prnt->flags |= MODS_TRUE;
		return(1);
	}
	if (*prnt->format == 'l')
	{
		if (prnt->format[1] == 'l')
		{
			prnt->format++;
			prnt->flags |=  MOD_LL;
		}
		else
		{
			prnt->flags |= 	MOD_L;
		}
		prnt->flags |= MODS_TRUE;
		return(1);
	}
	if (*prnt->format == 'L')
	{
		prnt->flags |= 	MOD_LLL;
		prnt->flags |= MODS_TRUE;
		return(1);
	}
	return(0);
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

int					accuracy(t_printf *prnt)
{
	int tmp;

	tmp = 0;
	
	if (*prnt->format == '.')
	{
		if (FLAG_NULL == (prnt->flags & FLAG_NULL))
			prnt->flags -= FLAG_NULL;
		prnt->format++;
		prnt->accuracy = ft_atoi_nb(prnt->format, &tmp);
		prnt->format += tmp;
		return(1);
	}
	return(0);
}

int					flags(t_printf *prnt)
{
	if (*prnt->format == '-')
	{
		prnt->flags |= FLAG_MINUS;
		return(1);
	}
	if (*prnt->format == ' ')
	{
		prnt->flags |= FLAG_SPACE;
		return(1);
	}
	if (*prnt->format == '+')
	{
		prnt->flags |= FLAG_PLUS;
		return(1);
	}
	if (*prnt->format == '#')
	{
		prnt->flags |= FLAG_SHARP;
		return(1);
	}
	if (*prnt->format == '0')
	{
		prnt->flags |= FLAG_NULL;
		return(1);
	}
	return(0);
}

int					width(t_printf *prnt)
{
	int tmp;

	tmp = 0;
	if (*prnt->format >= '0' && *prnt->format <= '9')
	{
		prnt->width = ft_atoi_nb(prnt->format, &tmp);
		prnt->format += tmp;
		return(1);
	}
	return(0);
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

void		if_procent(t_printf *prnt)
{
	int			temp;

	temp = 0;
	prnt->format++;
	while (*prnt->format != '\0' && *prnt->format != '%' && (!(FORM_TRUE == (prnt->flags & FORM_TRUE))))
	{
		if (flags(prnt))
		{
			prnt->format++;
			continue;
		}
		if (width(prnt))
		{
			continue;
		}
		if (accuracy(prnt))
		{
			continue;
		}
		if (!(MODS_TRUE == (prnt->flags & MODS_TRUE)))
		{
			if (mods(prnt))
			{
				prnt->format++;
				continue;
			}
		}
		if (!(FORM_TRUE == (prnt->flags & FORM_TRUE)))
		{
			form(prnt);
			if (FORM_TRUE == (prnt->flags & FORM_TRUE))
			{
				transform(prnt);
				prnt->format++;
				continue;
			}
		}
		else
		{
			putchar_and_count(prnt, *prnt->format);
			prnt->format++;
		}
	}
	prnt->flags |= PRO_TRUE;
}