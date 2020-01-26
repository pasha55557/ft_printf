/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjonella <tjonella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/19 18:50:50 by tjonella          #+#    #+#             */
/*   Updated: 2020/01/26 16:01:40 by tjonella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*ft_strcat(char *dst, const char *append)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (dst[i] != '\0')
		i++;
	while (append[j] != '\0')
	{
		dst[i] = append[j];
		j++;
		i++;
	}
	dst[i] = append[j];
	return (dst);
}

char	*ft_strrev(char *str)
{
	int		i;
	int		j;
	char	c;

	if (!str)
		return (NULL);
	i = 0;
	j = ft_strlen(str);
	if (!j)
		return (NULL);
	while (i < j)
	{
		c = str[j - 1];
		str[j - 1] = str[i];
		str[i] = c;
		i++;
		j--;
	}
	return (str);
}

char	*rounding_flt(char *itg, char *flt, t_printf *prnt)
{
	int		i;
	char	*res;

	i = 0;
	res = NULL;
	if (!flt)
		return (big_int(itg, prnt));
	while (flt[i])
		i++;
	if (prnt->accuracy == 0 && flt[--i] > '5')
		itg[0]++;
	else if (prnt->accuracy == 0 && flt[i] == '5')
	{
		while ((i + 1) && flt[i] != '0')
			i--;
		if (i > -1)
			itg[0]++;
	}
	else
		res = rounding_flt_2(itg, flt, prnt);
	ft_strrev(itg);
	free(res ? itg : res);
	return (res ? res : itg);
}

int		ft_abs(int n)
{
	return (n < 0 ? -n : n);
}

void	first_bias(char *flt, int bits, int exp)
{
	int		i;

	i = exp - 1;
	bits = ft_abs(t_floats.t_bits.exp - 16383 + bits - 63);
	while ((i + 1) && !flt[i])
		i--;
	bits = bits - i - 1;
	while (bits--)
		flt[++i] += '0';
}
