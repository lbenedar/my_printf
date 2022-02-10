/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_spec_parser.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenedar <lbenedar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 19:02:02 by lbenedar          #+#    #+#             */
/*   Updated: 2021/01/16 16:17:59 by lbenedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_parser.h"

size_t	ft_spec_parser(const char *format, size_t index, t_placeholder *ph)
{
	if (format[index] == 'l')
	{
		if (format[index + 1] == 'l')
		{
			ph->spec = spec_ll;
			++index;
		}
		else
			ph->spec = spec_l;
	}
	else if (format[index] == 'h')
	{
		if (format[index + 1] == 'h')
		{
			ph->spec = spec_hh;
			++index;
		}
		else
			ph->spec = spec_h;
	}
	return (index);
}
