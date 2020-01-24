/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsticks <rsticks@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 15:38:44 by rsticks           #+#    #+#             */
/*   Updated: 2020/01/24 15:15:06 by rsticks          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

// static void		char_process_width(t_printf *prnt, int count)
// {
// 	if (FLAG_MINUS != (prnt->flags & FLAG_MINUS) && (FLAG_NULL != (prnt->flags & FLAG_NULL)))
// 	{
// 		prnt->width -= count;
// 		while (prnt->width > 0)
// 		{
// 			putchar_and_count(prnt, ' ');
// 			prnt->width--;
// 		}
// 	}
	
// 	if (FLAG_NULL == (prnt->flags & FLAG_NULL) && FLAG_MINUS != (prnt->flags & FLAG_MINUS))
// 	{
// 		prnt->width -= count;
// 		while (prnt->width > 0)
// 		{
// 			putchar_and_count(prnt, '0');
// 			prnt->width--;
// 		}
// 	}
// }

static void		char_process_width(t_printf *prnt, char *c)
{
	int			count;
	char		*ptr;

	ptr = c;
	if (FLAG_NULL == (prnt->flags & FLAG_NULL) && (prnt->accuracy >= 0))
		prnt->flags -= FLAG_NULL;
	count = ft_strlen(c);
	if (*c == (int)NULL && (FORM_C == (prnt->flags & FORM_C)))
		count++;
	if (prnt->accuracy >= 0 && prnt->accuracy < count)
		count = prnt->accuracy;
	
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
	if (*c == (int)NULL && (FORM_C == (prnt->flags & FORM_C)))
	{
		putchar_and_count(prnt, (char)NULL);
	}
	while (*c != '\0' && prnt->accuracy != 0)
	{
		putchar_and_count(prnt, *c);
		prnt->accuracy--;
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
	if (prnt->herna == 1)
		free(ptr);
}

void			ft_char(t_printf *prnt)
{
	char		c[2];

	c[0] = (char)va_arg(prnt->arg, int);
	c[1] = '\0';
	char_process_width(prnt, c);
}

void			ft_str(t_printf *prnt)
{
	char		*c;

	prnt->herna = 0;
	if (!(c = va_arg(prnt->arg, char*)))
	{
		c = ft_strdup("(null)");
		prnt->herna = 1;
	}
		char_process_width(prnt, c);
}
