/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_proc_str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenedar <lbenedar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/02 18:39:06 by lbenedar          #+#    #+#             */
/*   Updated: 2021/01/16 16:44:41 by lbenedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_processor.h"

static size_t	ft_minus_1(t_placeholder *ph, char *str)
{
	size_t	i;
	size_t	len;
	long	sublen;
	long	width;

	i = 0;
	if (ph->precision >= 0)
		sublen = ph->precision;
	else
		sublen = ft_strlen(str);
	width = ph->width;
	len = sublen;
	if (ph->precision >= 0)
		while (ph->precision - i)
			ft_putchar_fd(str[i++], 1);
	else
		ft_putstr_fd(str, 1);
	while (width-- > sublen)
	{
		ft_putchar_fd(' ', 1);
		len++;
	}
	return (len);
}

static size_t	ft_minus_0(t_placeholder *ph, char *str)
{
	size_t	i;
	size_t	len;
	long	sublen;
	long	width;

	i = 0;
	if (ph->precision >= 0)
		sublen = ph->precision;
	else
		sublen = ft_strlen(str);
	width = ph->width;
	len = sublen;
	while (width-- > sublen)
	{
		ft_putchar_fd(' ', 1);
		len++;
	}
	if (ph->precision >= 0)
		while (ph->precision - i)
			ft_putchar_fd(str[i++], 1);
	else
		ft_putstr_fd(str, 1);
	return (len);
}

static char		*ft_str_w_zeros(size_t sublen, char *str, size_t len)
{
	char	*substr;
	size_t	i;
	size_t	index;

	if (!(substr = malloc(sizeof(char) * (sublen + 1))))
		return (0);
	substr[sublen] = 0;
	i = 0;
	index = 0;
	while (i < sublen)
	{
		if (sublen - i > len)
			substr[i] = '0';
		else
			substr[i] = str[index++];
		i++;
	}
	return (substr);
}

size_t			ft_proc_str(t_placeholder *ph, char *str)
{
	size_t	len;
	int		free_var;

	len = 0;
	free_var = 0;
	if (!str)
		str = "(null)";
	if ((ph->precision >= 0) && (ph->precision > (long)ft_strlen(str)))
		ph->precision = ft_strlen(str);
	if ((ph->precision > (int)ft_strlen(str)) && (free_var = 1))
		str = ft_str_w_zeros(ph->precision, str, ft_strlen(str));
	else if ((ph->precision < 0) && (ph->zero)
			&& (ph->width > (int)ft_strlen(str)))
	{
		str = ft_str_w_zeros(ph->width, str, ft_strlen(str));
		free_var = 1;
		ph->width = 0;
	}
	if (ph->minus)
		len += ft_minus_1(ph, str);
	else
		len += ft_minus_0(ph, str);
	if (free_var)
		free(str);
	return (len);
}
