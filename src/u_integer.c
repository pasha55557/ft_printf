/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u_integer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsticks <rsticks@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 15:19:20 by rsticks           #+#    #+#             */
/*   Updated: 2020/01/25 18:59:04 by rsticks          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int							ft_udigits_count(unsigned long long int n)
{
	int						i;

	i = 0;
	if (n == 0)
		i++;
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char						*ft_ulong_itoa(unsigned long long int n)
{
	int						i;
	char					*s;
	unsigned long long int	nb;

	nb = n;
	i = ft_udigits_count(n) - 1;
	s = ft_strnew((size_t)(i + 1));
	if (s == NULL)
		return (NULL);
	if (nb == 0)
		s[0] = '0';
	while (nb != 0)
	{
		s[i] = nb % 10 + '0';
		nb = nb / 10;
		i--;
	}
	return (s);
}

void						u_intger(t_printf *prnt)
{
	char					*c;

	c = u_modificator(prnt);
	unsigned_process_width(prnt, c);
}
