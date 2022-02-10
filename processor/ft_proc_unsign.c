/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_proc_unsign.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenedar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/02 23:16:09 by lbenedar          #+#    #+#             */
/*   Updated: 2021/01/06 21:54:32 by lbenedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_processor.h"

size_t			ft_proc_unsign(t_placeholder *ph, unsigned long long val)
{
	size_t	len;
	char	*str;
	char	*substr;

	val = ft_proc_spec_us(ph, val);
	if ((str = 0) || val || ph->precision)
		if (!(str = ft_uitoa(val)))
			return (0);
	if ((!str) && ((str = malloc(sizeof(char)))))
		str[0] = 0;
	else if (!str)
		return (0);
	if (!(substr = ft_proc_zero_flag(ph, str)))
		return (0);
	len = ft_proc_output(ph, substr, ' ');
	free(substr);
	return (len);
}
