/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_proc_pointer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenedar <lbenedar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/02 21:30:52 by lbenedar          #+#    #+#             */
/*   Updated: 2021/01/16 11:31:44 by lbenedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_processor.h"

static size_t	ft_count_char(unsigned long ptr)
{
	size_t len;

	if (ptr)
		len = 0;
	else
		len = 1;
	while (ptr)
	{
		ptr /= 16;
		len++;
	}
	return (len);
}

static char		*ft_ptr_to_str(unsigned long ptr)
{
	char	*str;
	size_t	strlen;

	strlen = ft_count_char(ptr);
	if (!(str = malloc(sizeof(char) * (strlen + 1))))
		return (0);
	str[strlen] = 0;
	--strlen;
	if (!ptr)
		str[0] = '0';
	while (ptr)
	{
		if (ptr % 16 < 10)
			str[strlen] = ptr % 16 + 48;
		else
			str[strlen] = ptr % 16 + 87;
		ptr /= 16;
		strlen--;
	}
	return (str);
}

static size_t	ft_out_ptr(t_placeholder *ph, char *str, char space)
{
	size_t	len;
	long	sublen;

	len = 0;
	sublen = ft_strlen(str) + 2;
	if (((ph->precision) || ((ph->width) && (!ph->zero))) && (!ph->minus))
		len += ft_out_spaces(ph, space, sublen);
	ft_putstr_fd("0x", 1);
	ft_putstr_fd(str, 1);
	if (((ph->precision) || ((ph->width) && (!ph->zero))) && (ph->minus))
		len += ft_out_spaces(ph, space, sublen);
	return (len + sublen);
}

size_t			ft_proc_pointer(t_placeholder *ph, unsigned long ptr)
{
	size_t	len;
	char	*str;
	char	*substr;

	len = 0;
	if ((str = 0) || ptr || ph->precision)
		if (!(str = ft_ptr_to_str(ptr)))
			return (0);
	if ((!str) && ((str = malloc(sizeof(char)))))
		str[0] = 0;
	else if (!str)
		return (0);
	if (!(substr = ft_proc_zero_flag(ph, str)))
		return (0);
	len = ft_out_ptr(ph, substr, ' ');
	free(substr);
	return (len);
}
