/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_proc_int.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenedar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/02 23:14:42 by lbenedar          #+#    #+#             */
/*   Updated: 2021/01/06 22:48:24 by lbenedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_processor.h"

static char		*ft_str_minus(char *str)
{
	char *substr;

	substr = str;
	if (*substr)
		substr = ft_strdup(substr + 1);
	free(str);
	return (substr);
}

static size_t	ft_out_int(t_placeholder *ph, char *str, int minus)
{
	size_t	len;
	long	sublen;

	len = 0;
	sublen = ft_strlen(str) + minus;
	if (((ph->precision) || ((ph->width) && (!ph->zero))) && (!ph->minus))
		len += ft_out_spaces(ph, ' ', sublen);
	if (minus)
		ft_putchar_fd('-', 1);
	ft_putstr_fd(str, 1);
	if (((ph->precision) || ((ph->width) && (!ph->zero))) && (ph->minus))
		len += ft_out_spaces(ph, ' ', sublen);
	return (len + sublen);
}

static char		*ft_add_zeros(char *str, t_placeholder *ph, int minus)
{
	char *substr;

	substr = str;
	if (ph->precision > (int)ft_strlen(str))
	{
		substr = ft_use_zero_flag(ph->precision, str, ft_strlen(str));
		free(str);
	}
	else if ((ph->precision < 0) && (ph->zero)
			&& (ph->width > (int)ft_strlen(str)))
	{
		substr = ft_use_zero_flag(ph->width - minus, str, ft_strlen(str));
		free(str);
		ph->width = 0;
	}
	return (substr);
}

size_t			ft_proc_int(t_placeholder *ph, long long val)
{
	size_t	len;
	char	*str;
	int		minus;
	char	*substr;

	val = ft_proc_spec_s(ph, val);
	if ((str = 0) || val || ph->precision)
		if (!(str = ft_itoa(val)))
			return (0);
	if ((!str) && (str = malloc(sizeof(char))))
		str[0] = 0;
	else if (!str)
		return (0);
	minus = 0;
	if ((val < 0) && (minus = 1))
		str = ft_str_minus(str);
	if (!(substr = ft_add_zeros(str, ph, minus)))
		return (0);
	len = ft_out_int(ph, substr, minus);
	free(substr);
	return (len);
}
