/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_ph.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenedar <lbenedar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/02 16:42:35 by lbenedar          #+#    #+#             */
/*   Updated: 2021/01/16 16:51:59 by lbenedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_parser.h"

size_t	ft_parse_ph(const char *format, size_t index,
					t_placeholder *ph, va_list argptr)
{
	while (format[index])
	{
		if ((format[index] == '0') && (!ph->width) && (!ph->minus))
			ph->zero = 1;
		else if (format[index] == '.')
			index = ft_precision_parser(format, index, ph, argptr);
		else if (format[index] == '-')
		{
			ph->minus = 1;
			ph->zero = 0;
		}
		else if (format[index] == '*')
			ft_star_parser(ph, argptr);
		else if ((format[index] >= '0') && (format[index] <= '9'))
			index = ft_width_parser(format, index, ph);
		else if (ft_type_parser(format[index], ph))
			break ;
		++index;
	}
	return (index);
}
