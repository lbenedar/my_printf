/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_proc_zero_flag.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenedar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 17:58:25 by lbenedar          #+#    #+#             */
/*   Updated: 2021/01/16 11:26:55 by lbenedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_processor.h"

char	*ft_use_zero_flag(size_t sublen, char *str, size_t len)
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
		if (sublen > len + i)
			substr[i] = '0';
		else
			substr[i] = str[index++];
		i++;
	}
	return (substr);
}

char	*ft_proc_zero_flag(t_placeholder *ph, char *str)
{
	int		len;
	char	*substr;

	len = ft_strlen(str);
	substr = str;
	if (ph->precision > len)
	{
		substr = ft_use_zero_flag(ph->precision, str, len);
		free(str);
	}
	else if ((ph->precision < 0) && (ph->zero) && (ph->width > len))
	{
		substr = ft_use_zero_flag(ph->width, str, len);
		free(str);
		ph->width = 0;
	}
	return (substr);
}
