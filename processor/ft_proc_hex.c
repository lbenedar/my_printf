/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_proc_hex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenedar <lbenedar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/02 23:11:30 by lbenedar          #+#    #+#             */
/*   Updated: 2021/01/16 11:28:38 by lbenedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_processor.h"

static size_t	ft_count_char(unsigned long long hex)
{
	size_t len;

	if (hex)
		len = 0;
	else
		len = 1;
	while (hex)
	{
		hex /= 16;
		len++;
	}
	return (len);
}

static char		*ft_hex_to_str(unsigned long long hex, int capitals)
{
	char	*str;
	size_t	strlen;

	strlen = ft_count_char(hex);
	if (!(str = malloc(sizeof(char) * (strlen + 1))))
		return (0);
	str[strlen] = 0;
	--strlen;
	if (!hex)
		str[0] = '0';
	while (hex)
	{
		if (hex % 16 < 10)
			str[strlen] = hex % 16 + 48;
		else
			str[strlen] = hex % 16 + 55 + capitals * 32;
		hex /= 16;
		strlen--;
	}
	return (str);
}

size_t			ft_proc_hex(t_placeholder *ph, int capitals,
							unsigned long long hex)
{
	size_t	len;
	char	*str;
	char	*substr;

	len = 0;
	hex = ft_proc_spec_us(ph, hex);
	if ((str = 0) || hex || ph->precision)
		if (!(str = ft_hex_to_str(hex, capitals)))
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
