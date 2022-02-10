/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_processor.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenedar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/02 17:48:50 by lbenedar          #+#    #+#             */
/*   Updated: 2021/01/06 20:02:58 by lbenedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_processor.h"

size_t	ft_processor(t_placeholder *ph, va_list argptr)
{
	size_t	len;

	len = 0;
	if (ph->type == type_c)
		len = ft_proc_char(ph, va_arg(argptr, int));
	else if (ph->type == type_s)
		len = ft_proc_str(ph, va_arg(argptr, char*));
	else if (ph->type == type_p)
		len = ft_proc_pointer(ph, va_arg(argptr, unsigned long));
	else if (ph->type == type_d_i)
		len = ft_proc_int(ph, va_arg(argptr, int));
	else if (ph->type == type_u)
		len = ft_proc_unsign(ph, va_arg(argptr, unsigned int));
	else if (ph->type == type_x_upper)
		len = ft_proc_hex(ph, 0, va_arg(argptr, unsigned int));
	else if (ph->type == type_x_lower)
		len = ft_proc_hex(ph, 1, va_arg(argptr, unsigned int));
	else if (ph->type == type_o)
		len = ft_proc_oct(ph, va_arg(argptr, unsigned int));
	else if (ph->type == type_percentage)
		len = ft_proc_percent(ph);
	return (len);
}
