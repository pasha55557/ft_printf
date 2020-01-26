/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add3.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsticks <rsticks@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 18:21:55 by rsticks           #+#    #+#             */
/*   Updated: 2020/01/25 18:38:59 by rsticks          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int								countdigits(int n)
{
	int							i;

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

int								accuracy(t_printf *prnt)
{
	int							tmp;

	tmp = 0;
	if (*prnt->format == '.')
	{
		prnt->format++;
		prnt->accuracy = ft_atoi_nb(prnt->format, &tmp);
		prnt->format += tmp;
		return (1);
	}
	return (0);
}

int								flags(t_printf *prnt)
{
	char						trigger;

	trigger = 1;
	if (*prnt->format == '-')
		prnt->flags |= FLAG_MINUS;
	else if (*prnt->format == ' ')
		prnt->flags |= FLAG_SPACE;
	else if (*prnt->format == '+')
		prnt->flags |= FLAG_PLUS;
	else if (*prnt->format == '#')
		prnt->flags |= FLAG_SHARP;
	else if (*prnt->format == '0')
		prnt->flags |= FLAG_NULL;
	else
		trigger = 0;
	return (trigger);
}

int								if_procent4(t_printf *prnt)
{
	if (flags(prnt))
	{
		prnt->format++;
		return (1);
	}
	return (0);
}
