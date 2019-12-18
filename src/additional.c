/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additional.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsticks <rsticks@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 15:18:06 by rsticks           #+#    #+#             */
/*   Updated: 2019/12/18 18:07:10 by rsticks          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void					putstr_and_count(t_printf *prnt, char *c)
{
	if (prnt->count % 255 == 0 && prnt->count != 0)
		write(1, prnt->buff, 255);
	while(*c != '\0')
	{
		prnt->buff[prnt->count % 255] = *c;
		prnt->count++;
		c++;
	}
}

int		ftft_digits_count(long long int n)
{
	int i;

	i = 0;
	if (n == 0)
		i++;
	if (n < 0)
		i++;
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char				*ft_dec_to(unsigned long long int d, int sys, t_printf *prnt)
{
	char			*c;
	char			*s;
	int				i;
	int				otc;
	int				j;

	j = 0;
	otc = 39;
	if (FORM_X == (prnt->flags & FORM_X))
		otc = 7;
	i = 0;
	c = malloc(sizeof(char) * 30);
	if (d == 0)
	{
		c[i] = '0';
		i++;
	}
	while (d)
	{
		c[i] = 48 + d % sys;
		if (c[i] > 57)
			c[i] += otc;
		d /= sys;
		i++;
	}
	i--;
	s = malloc(sizeof(char) * i);
	while (i >= 0)
	{
		s[j] = c[i];
		i--;
		j++;
	}
	s[j] = '\0';
	free(c);
//	printf("in dec_to %s\n", s);
	return (s);
}

char				*ft_long_itoa(long long int n)
{
	int				i;
	char			*s;
	unsigned long long int	nb;

	nb = n;
	i = ftft_digits_count(n) - 1;
	s = ft_strnew((size_t)(i + 1));
	if (s == NULL)
		return (NULL);
	if (n == 0)
		s[0] = '0';
	if (n < 0)
	{
		s[0] = '-';
		nb = n * (-1);
	}
	while (nb != 0)
	{
		s[i] = nb % 10 + '0';
		nb = nb / 10;
		i--;
	}
	return (s);
}


void		process_width(t_printf *prnt, char *c)
{
	char	*ptr;
	int		count;
	int		acc;

	ptr = c;
	count = 0;
	count = ft_strlen(c);
	acc = count;
	if (c[0] == '-')
		acc--;
	if ((FLAG_PLUS == (prnt->flags & FLAG_PLUS) || FLAG_SPACE == (prnt->flags & FLAG_SPACE)) && (c[0] != '-'))
		count++;
	if (prnt->accuracy == 0 && *c == '0')
	{
		count--;
		if (prnt->width == 0)
			prnt->accuracy = -4;
		else
			prnt->accuracy = -3;
	}
	if (prnt->accuracy >= 0)
	{
		prnt->accuracy -= acc;
		if (prnt->accuracy > 0)
			count += prnt->accuracy;
		else
			prnt->accuracy = -2;
	}
	
	if (FLAG_MINUS != (prnt->flags & FLAG_MINUS) && (FLAG_NULL != (prnt->flags & FLAG_NULL)))
	{
		prnt->width -= count;
		while (prnt->width > 0)
		{
			putchar_and_count(prnt, ' ');
			prnt->width--;
		}
	}
	if (c[0] == '-')
		putchar_and_count(prnt, '-');
	if (FLAG_PLUS == (prnt->flags & FLAG_PLUS))
	{
		if (c[0] != '-' || c[0] == 0)
			putchar_and_count(prnt, '+');
	}
	if (FLAG_SPACE == (prnt->flags & FLAG_SPACE) && (FLAG_PLUS != (prnt->flags & FLAG_PLUS)))
	{
		if (c[0] != '-' || c[0] == 0)
			putchar_and_count(prnt, ' ');
	}
	while (prnt->accuracy > 0)
	{
		putchar_and_count(prnt, '0');
		prnt->accuracy--;
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
		if (*c == '-')
			c++;
		if (prnt->accuracy > -3)
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

void		unsigned_process_width(t_printf *prnt, char *c)
{
	char	*ptr;
	int		count;
	int		acc;

	ptr = c;
	count = ft_strlen(c);
	acc = count;
	if (prnt->accuracy == 0 && *c == '0')
	{
		if (prnt->width == 0)
			prnt->accuracy = -4;
		else
			prnt->accuracy = -3;
	}
	if (prnt->accuracy >= 0)
	{
		if ((FORM_O == (prnt->flags & FORM_O) && (FLAG_SHARP == (prnt->flags & FLAG_SHARP))) && c[0] != '0')
			prnt->accuracy--;
		prnt->accuracy -= acc;
		if (prnt->accuracy > 0)
			count += prnt->accuracy;
		else
			prnt->accuracy = -2;
	}
	//printf("FLAG = %c", c[0]);
	if ((FLAG_SHARP == (prnt->flags & FLAG_SHARP) && ((*c != '0') || FORM_O == (prnt->flags & FORM_O))) || (FORM_P == (prnt->flags & FORM_P)))
	{
		if ((!(FORM_O == (prnt->flags & FORM_O) && (c[0] == '0'))) || (prnt->accuracy == -4))
			count++;
		if (FORM_x == (prnt->flags & FORM_x) || (FORM_P == (prnt->flags & FORM_P)))
			count++;
		if (FORM_X == (prnt->flags & FORM_X))
			count++;
	}
	
	if (FLAG_MINUS != (prnt->flags & FLAG_MINUS) && (FLAG_NULL != (prnt->flags & FLAG_NULL)))
	{
		prnt->width -= count;
		while (prnt->width > 0)
		{
			putchar_and_count(prnt, ' ');
			prnt->width--;
		}
	}

	if ((FLAG_SHARP == (prnt->flags & FLAG_SHARP) && ((*c != '0') || FORM_O == (prnt->flags & FORM_O))) || (FORM_P == (prnt->flags & FORM_P)))
	{
		if ((!(FORM_O == (prnt->flags & FORM_O) && (c[0] == '0'))) || (prnt->accuracy == -4))
			putchar_and_count(prnt, '0');
		if (FORM_x == (prnt->flags & FORM_x) || (FORM_P == (prnt->flags & FORM_P)))
			putchar_and_count(prnt, 'x');
		if (FORM_X == (prnt->flags & FORM_X))
			putchar_and_count(prnt, 'X');
	}
	

	while (prnt->accuracy > 0)
	{
		putchar_and_count(prnt, '0');
		prnt->accuracy--;
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
	if (prnt->accuracy == -3 && (!(FORM_O == (prnt->flags & FORM_O) && c[0] == '0' && FLAG_SHARP == (prnt->flags & FLAG_SHARP))))
			putchar_and_count(prnt, ' ');
	else if (prnt->accuracy == -4)
		prnt->accuracy = 0;
	else
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
