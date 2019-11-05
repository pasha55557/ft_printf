/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsticks <rsticks@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 18:56:00 by rsticks           #+#    #+#             */
/*   Updated: 2019/10/31 12:47:23 by rsticks          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../includes/ft_printf.h"

int	main()
{
	int ft_i;
	char c;
	int j;
	int test;

	test = 45;
	c = 'f';
	ft_i = 0;
	j = 0;
	ft_i = printf("%.0d", test);
	//j = ft_printf("%-5k");
	printf("\ncount printf     (%d)\n", ft_i);
	//printf("count ft_printf  (%d)\n", j);
	return(0);
}