/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_proc_spec_s.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenedar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 19:55:05 by lbenedar          #+#    #+#             */
/*   Updated: 2021/01/16 11:27:32 by lbenedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_processor.h"

long long	ft_proc_spec_s(t_placeholder *ph, long long val)
{
	if (ph->spec == spec_empty)
		val = (signed int)val;
	else if (ph->spec == spec_l)
		val = (signed long)val;
	else if (ph->spec == spec_h)
		val = (signed short)val;
	else if (ph->spec == spec_hh)
		val = (signed char)val;
	return (val);
}
