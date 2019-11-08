/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsticks <rsticks@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 18:56:00 by rsticks           #+#    #+#             */
/*   Updated: 2019/11/08 15:46:54 by rsticks          ###   ########.fr       */
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
	double	ft;

	ft = 5.006;
	test = 97;
	c = 'f';
	ft_i = 0;
	j = 0;
	ft_i = printf("%d5", test);
	//printf("%e",);
	j = ft_printf("%55d");
	printf("\ncount printf     (%d)\n", ft_i);
	//printf("count ft_printf  (%d)\n", j);
	return(0);
}