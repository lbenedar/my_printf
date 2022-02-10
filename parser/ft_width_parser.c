/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_width_parser.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenedar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/03 18:19:46 by lbenedar          #+#    #+#             */
/*   Updated: 2021/01/03 23:58:07 by lbenedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_parser.h"

size_t	ft_width_parser(const char *format, size_t index, t_placeholder *ph)
{
	if (ph->star == 1)
		ph->width = 0;
	while ((format[index] >= '0') && (format[index] <= '9'))
		ph->width = ph->width * 10 + (format[index++] - '0');
	return (index - 1);
}
