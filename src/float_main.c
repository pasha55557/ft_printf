/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsticks <rsticks@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 19:31:07 by tjonella          #+#    #+#             */
/*   Updated: 2020/01/29 19:57:36 by rsticks          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*not_num(t_printf *prnt)
{
	char	*c;
	
	c = NULL;
	if (t_floats.t_bits.exp == 32767 && t_floats.t_bits.sign == 0 && \
		t_floats.t_bits.mant == 1UL << 63)
	{
		c = ft_strdup("inf");
		prnt->flags &= 7;
		prnt->accuracy = -2;
	}
	else if (t_floats.t_bits.exp == 32767 && t_floats.t_bits.sign == 1 && \
	t_floats.t_bits.mant == 1UL << 63)
	{
		prnt->flags &= 7;
		c = ft_strdup("-inf");
		prnt->accuracy = -2;
	}
	else if (t_floats.t_bits.exp == 32767)
	{
		prnt->flags &= 1;
		c = ft_strdup("nan");
		prnt->accuracy = -2;
	}
	return (c);
}

char	*modif_flt(t_printf *prnt)
{
	char			*c;
	long double		lln;
	double			ln;

	ln = 0;
	if (MOD_LLL == (prnt->flags & MOD_LLL))
	{
		lln = va_arg(prnt->arg, long double);
		t_floats.f = lln;
		c = not_num(prnt);
		c = c ? c : ft_flt((long double)lln, prnt);
	}
	else
	{
		ln = va_arg(prnt->arg, double);
		t_floats.f = ln;
		c = not_num(prnt);
		c = c ? c : ft_flt((double)ln, prnt);
	}
	return (c);
}

void	ft_flt_get(t_printf *prnt)
{
	char	*c;

	c = modif_flt(prnt);
	process_width_for_float(prnt, c);
}
