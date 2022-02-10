/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_proc_char.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenedar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/02 18:35:43 by lbenedar          #+#    #+#             */
/*   Updated: 2021/01/06 23:55:50 by lbenedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_processor.h"

size_t	ft_proc_char(t_placeholder *ph, char c)
{
	size_t	len;

	len = 0;
	if (!ph->minus)
		len += ft_out_spaces(ph, ' ', 1);
	ft_putchar_fd(c, 1);
	if (ph->minus)
		len += ft_out_spaces(ph, ' ', 1);
	return (len + 1);
}
