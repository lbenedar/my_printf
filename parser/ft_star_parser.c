/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_star_parser.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenedar <lbenedar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/03 18:19:36 by lbenedar          #+#    #+#             */
/*   Updated: 2021/01/04 16:43:15 by lbenedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_parser.h"

void	ft_star_parser(t_placeholder *ph, va_list argptr)
{
	ph->star = 1;
	ph->width = va_arg(argptr, int);
	if (ph->width < 0)
	{
		ph->minus = 1;
		ph->zero = 0;
		ph->width = ph->width * (-1);
	}
}
