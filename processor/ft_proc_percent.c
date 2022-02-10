/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_proc_percent.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenedar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/02 23:13:37 by lbenedar          #+#    #+#             */
/*   Updated: 2021/01/06 18:07:38 by lbenedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_processor.h"

size_t			ft_proc_percent(t_placeholder *ph)
{
	size_t	len;
	char	space;

	len = 0;
	if (ph->zero)
		space = '0';
	else
		space = ' ';
	len += ft_proc_output(ph, "%", space);
	return (len);
}
