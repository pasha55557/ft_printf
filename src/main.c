/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsticks <rsticks@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 18:56:00 by rsticks           #+#    #+#             */
/*   Updated: 2020/01/16 14:56:47 by rsticks          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../includes/ft_printf.h"
#include <float.h>

int	main()
{
	int 	ft_i;
	int 	j;
	double	*f;
	long	l_f;
	int		d;
	char	*format = "%+6f\n";

	d = 54;
	l_f = DBL_NAN;
	f = (double *)&l_f;
	ft_i = printf(format, *f);
	j = ft_printf(format, *f);
	printf("\ncount printf     (%d)\n", ft_i);
	printf("count ft_printf  (%d)\n", j);
	return(0);
}