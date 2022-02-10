/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_parser.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenedar <lbenedar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 18:58:36 by lbenedar          #+#    #+#             */
/*   Updated: 2021/01/04 17:03:43 by lbenedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_parser.h"

t_type	ft_type_parser(const char c, t_placeholder *ph)
{
	if ((c == 'd') || (c == 'i'))
		ph->type = type_d_i;
	else if (c == 'u')
		ph->type = type_u;
	else if (c == 'c')
		ph->type = type_c;
	else if (c == 's')
		ph->type = type_s;
	else if (c == 'p')
		ph->type = type_p;
	else if (c == 'x')
		ph->type = type_x_lower;
	else if (c == 'X')
		ph->type = type_x_upper;
	else if (c == '%')
		ph->type = type_percentage;
	else if (c == 'o')
		ph->type = type_o;
	return (ph->type);
}
