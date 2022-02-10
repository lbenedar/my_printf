/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_proc_spec_us.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenedar <lbenedar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 19:54:59 by lbenedar          #+#    #+#             */
/*   Updated: 2021/01/16 16:15:21 by lbenedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_processor.h"

long long	ft_proc_spec_us(t_placeholder *ph, unsigned long long val)
{
	if (ph->spec == spec_empty)
		val = (unsigned int)val;
	else if (ph->spec == spec_l)
		val = (unsigned long)val;
	else if (ph->spec == spec_h)
		val = (unsigned short)val;
	else if (ph->spec == spec_hh)
		val = (unsigned char)val;
	return (val);
}
