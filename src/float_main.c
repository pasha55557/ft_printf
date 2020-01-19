/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjonella <tjonella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 19:31:07 by tjonella          #+#    #+#             */
/*   Updated: 2020/01/19 17:50:34 by tjonella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*not_num(char *c, t_printf *prnt)
{
	if (t_floats.t_bits.exp == 32767 && t_floats.t_bits.sign == 0 && t_floats.t_bits.mant == 1UL << 63)
	{
		c = "inf";
		prnt->flags &= 7;
		prnt->accuracy = -2;
	}
	else if (t_floats.t_bits.exp == 32767 && t_floats.t_bits.sign == 1 && t_floats.t_bits.mant == 1UL << 63)
	{
		prnt->flags &= 7;
		c = "-inf";
		prnt->accuracy = -2;
	}
	else if (t_floats.t_bits.exp == 32767)
	{
		prnt->flags &= 1;
		c = "nan";
		prnt->accuracy = -2;
	}
	return (c);
}

char	*modif_flt(t_printf *prnt)
{
	char			*c;
	long double 	lln;
	double			ln;

	ln = 0;
	if (MOD_L == (prnt->flags & MOD_L))
	{
		ln = va_arg(prnt->arg, double);
		c = ft_flt((double)ln, prnt);
		c = not_num(c, prnt);
	}
	else if (MOD_LLL == (prnt->flags & MOD_LLL))
	{
		lln = va_arg(prnt->arg, long double);
		c = ft_flt((long double)lln, prnt);
		c = not_num(c, prnt);
	}
	else
	{
		ln = va_arg(prnt->arg, double);
		c = ft_flt((double)ln, prnt);
		c = not_num(c, prnt);
	}
	return (c);
}

void	ft_flt_get(t_printf *prnt)
{
	char	*c;

	c = modif_flt(prnt);
	//process_width(prnt, c);
	process_width_for_float(prnt, c);
}