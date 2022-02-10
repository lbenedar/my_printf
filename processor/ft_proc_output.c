/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_proc_output.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenedar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 17:53:13 by lbenedar          #+#    #+#             */
/*   Updated: 2021/01/16 11:24:42 by lbenedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_processor.h"

size_t	ft_out_spaces(t_placeholder *ph, char space, int strlen)
{
	size_t len;

	len = 0;
	while (ph->width-- > strlen)
	{
		ft_putchar_fd(space, 1);
		len++;
	}
	return (len);
}

size_t	ft_proc_output(t_placeholder *ph, char *str, char space)
{
	size_t	len;
	long	sublen;

	len = 0;
	sublen = ft_strlen(str);
	if (((ph->precision) || ((ph->width) && (!ph->zero))) && (!ph->minus))
		len += ft_out_spaces(ph, space, sublen);
	ft_putstr_fd(str, 1);
	if (((ph->precision) || ((ph->width) && (!ph->zero))) && (ph->minus))
		len += ft_out_spaces(ph, space, sublen);
	return (len + sublen);
}
