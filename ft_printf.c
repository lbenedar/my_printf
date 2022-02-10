/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenedar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 17:52:15 by lbenedar          #+#    #+#             */
/*   Updated: 2021/01/03 23:57:48 by lbenedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int		ft_printf(const char *format, ...)
{
	va_list			argptr;
	size_t			len;

	if (!format)
		return (-1);
	len = 0;
	va_start(argptr, format);
	len = ft_parser(format, argptr);
	va_end(argptr);
	return (len);
}
