/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long_itoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsticks <rsticks@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 16:34:02 by rsticks           #+#    #+#             */
/*   Updated: 2020/01/24 16:34:23 by rsticks          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char						*ft_long_itoa(long long int n)
{
	int						i;
	char					*s;
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
