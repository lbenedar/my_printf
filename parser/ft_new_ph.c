/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_ph.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenedar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 18:28:29 by lbenedar          #+#    #+#             */
/*   Updated: 2021/01/06 21:26:32 by lbenedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/struct.h"

t_placeholder	*ft_new_ph(t_placeholder *new_ph)
{
	new_ph = malloc(sizeof(t_placeholder));
	if (!new_ph)
		return (0);
	new_ph->precision = -1;
	new_ph->type = type_empty;
	new_ph->spec = spec_empty;
	new_ph->width = 0;
	new_ph->minus = 0;
	new_ph->star = 0;
	new_ph->zero = 0;
	return (new_ph);
}
