/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsticks <rsticks@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 15:38:44 by rsticks           #+#    #+#             */
/*   Updated: 2019/12/11 17:09:22 by rsticks          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void		char_process_width(t_printf *prnt, char *c)
{
	int			count;

	count = ft_strlen(c);
	
	if (FLAG_MINUS != (prnt->flags & FLAG_MINUS) && (FLAG_NULL != (prnt->flags & FLAG_NULL)))
	{
		prnt->width -= count;
		while (prnt->width > 0)
		{
			putchar_and_count(prnt, ' ');
			prnt->width--;
		}
	}
	
	if (FLAG_NULL == (prnt->flags & FLAG_NULL) && FLAG_MINUS != (prnt->flags & FLAG_MINUS))
	{
		prnt->width -= count;
		while (prnt->width > 0)
		{
			putchar_and_count(prnt, '0');
			prnt->width--;
		}
	}

	while (*c != '\0')
	{
		putchar_and_count(prnt, *c);
		c++;
	}
	if (FLAG_MINUS == (prnt->flags & FLAG_MINUS))
	{
		prnt->width -= count;
		while (prnt->width > 0)
		{
			putchar_and_count(prnt, ' ');
			prnt->width--;
		}
	}
}

void			ft_char(t_printf *prnt)
{
	char		*c;

	c = malloc(sizeof(char));
	*c = (unsigned char)va_arg(prnt->arg, unsigned int);
	char_process_width(prnt, c);
}

void			ft_str(t_printf *prnt)
{
	char		*c;

//c = va_arg(prnt->arg, ptrdiff_t);

	c = va_arg(prnt->arg, char*);
	char_process_width(prnt, c);
}

