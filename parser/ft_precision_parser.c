/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_precision_parser.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenedar <lbenedar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 18:53:48 by lbenedar          #+#    #+#             */
/*   Updated: 2021/01/04 16:42:13 by lbenedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_parser.h"

size_t	ft_precision_parser(const char *format, size_t index,
							t_placeholder *ph, va_list argptr)
{
	size_t	i;

	i = index + 1;
	if (format[i] == '*')
		ph->precision = va_arg(argptr, int);
	else if ((format[i] >= '0') && (format[i] <= '9'))
	{
		ph->precision = ft_atoi(format + i);
		while ((format[i] >= '0') && (format[i] <= '9'))
			++i;
		--i;
	}
	else
	{
		ph->precision = 0;
		--i;
	}
	return (i);
}
