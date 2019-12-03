/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsticks <rsticks@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 18:56:00 by rsticks           #+#    #+#             */
/*   Updated: 2019/12/03 18:42:11 by rsticks          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../includes/ft_printf.h"

int	main()
{
	int ft_i;
	int j;
	char c;
	int d;
	double	f;

	f = 0.006;
	d = 97;
	c = 'f';
	ft_i = 0;
	j = 0;
	
	ft_i = printf("(%2.5i)\n", d);
	//ft_i = printf("(%5i)\n", d);
	//printf("%e",);
	j = ft_printf("(%2.5i)\n", d);
	printf("\ncount printf     (%d)\n", ft_i);
	printf("count ft_printf  (%d)\n", j);
	return(0);
}