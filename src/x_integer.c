/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_integer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsticks <rsticks@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 17:57:23 by rsticks           #+#    #+#             */
/*   Updated: 2020/01/24 17:16:56 by rsticks          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void						x_intger(t_printf *prnt)
{
	char					*c;

	c = x_modificator(prnt);
	unsigned_process_width(prnt, c);
}

void						ft_ptr(t_printf *prnt)
{
	char					*c;
	unsigned long long int	ln;

	ln = va_arg(prnt->arg, ptrdiff_t);
	c = ft_dec_to(ln, 16, prnt);
	unsigned_process_width(prnt, c);
}

void						ft_ptr_n(t_printf *prnt)
{
	int						*ln;

	ln = va_arg(prnt->arg, int*);
	*ln = prnt->count;
}
