/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsticks <rsticks@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 18:18:50 by rsticks           #+#    #+#             */
/*   Updated: 2020/01/25 18:45:18 by rsticks          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void						form2(t_printf *prnt)
{
	if (*prnt->format == 'e')
		prnt->flags |= FORM_EE;
	if (*prnt->format == 'g' || *prnt->format == 'G')
		prnt->flags |= FORM_G;
	if (*prnt->format == 'a')
		prnt->flags |= FORM_AA;
	if (*prnt->format == 'A')
		prnt->flags |= FORM_A;
	if (*prnt->format == 'c')
		prnt->flags |= FORM_C;
	if (*prnt->format == 's')
		prnt->flags |= FORM_SS;
	if (*prnt->format == 'S')
		prnt->flags |= FORM_S;
	if (*prnt->format == 'p')
		prnt->flags |= FORM_P;
	if (*prnt->format == 'E')
		prnt->flags |= FORM_E;
}

void							form(t_printf *prnt)
{
	uint32_t					tmp;
	char						*str;

	str = ft_strstr(prnt->buff, "\\");
	tmp = prnt->flags;
	if (*prnt->format == 'd' || *prnt->format == 'i' || *prnt->format == 'D')
		prnt->flags |= FORM_D_I;
	if (*prnt->format == 'u')
		prnt->flags |= FORM_U;
	if (*prnt->format == 'o')
		prnt->flags |= FORM_O;
	if (*prnt->format == 'X')
		prnt->flags |= FORM_X;
	if (*prnt->format == 'x')
		prnt->flags |= FORM_XX;
	if (*prnt->format == 'F' || *prnt->format == 'f')
		prnt->flags |= FORM_F;
	form2(prnt);
	if (*prnt->format == 'n' && !str)
		prnt->flags |= FORM_N;
	if (tmp != prnt->flags)
		prnt->flags |= FORM_TRUE;
}

static int						mods2(t_printf *prnt)
{
	if (prnt->format[1] == 'h')
	{
		prnt->format++;
		prnt->flags |= MOD_HH;
	}
	else
	{
		prnt->flags |= MOD_H;
	}
	prnt->flags |= MODS_TRUE;
	return (1);
}

int								mods(t_printf *prnt)
{
	if (*prnt->format == 'h')
		return (mods2(prnt));
	if (*prnt->format == 'l')
	{
		if (prnt->format[1] == 'l')
		{
			prnt->format++;
			prnt->flags |= MOD_LL;
		}
		else
		{
			prnt->flags |= MOD_L;
		}
		prnt->flags |= MODS_TRUE;
		return (1);
	}
	if (*prnt->format == 'L')
	{
		prnt->flags |= MOD_LLL;
		prnt->flags |= MODS_TRUE;
		return (1);
	}
	return (0);
}
