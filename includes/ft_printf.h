/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsticks <rsticks@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 14:59:55 by rsticks           #+#    #+#             */
/*   Updated: 2019/10/29 19:31:12 by rsticks          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../libft/libft.h"
#include <stdarg.h>

int		ft_printf(const char *format, ...);
int		parser(va_list arg, const char *format);