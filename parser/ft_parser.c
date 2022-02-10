/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenedar <lbenedar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 18:18:26 by lbenedar          #+#    #+#             */
/*   Updated: 2021/01/16 17:20:58 by lbenedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_parser.h"

static size_t	ft_parse_format(const char *format, size_t *index,
							t_placeholder *ph, va_list argptr)
{
	size_t len;

	len = 0;
	if (format[(*index)] == '%')
	{
		if ((format[(*index) + 1] == ' ') && (++len))
			ft_putchar_fd(format[++(*index)], 1);
		(*index) = ft_parse_ph(format, (*index) + 1, ph, argptr);
		if ((ph->type) && (!format[*index]))
			return (0);
		if (ph->type)
			len += ft_processor(ph, argptr);
		else if (++len)
			ft_putchar_fd(format[(*index)], 1);
	}
	else if (++len)
		ft_putchar_fd(format[*index], 1);
	return (len);
}

size_t			ft_parser(const char *format, va_list argptr)
{
	size_t			len;
	size_t			index;
	t_placeholder	*ph;

	len = 0;
	index = 0;
	while (format[index])
	{
		if (!(ph = ft_new_ph(ph)))
			return (0);
		len += ft_parse_format(format, &index, ph, argptr);
		if (ph)
			free(ph);
		if (!format[index])
			return (len);
		++index;
	}
	return (len);
}
