/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_proc_oct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenedar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 16:50:36 by lbenedar          #+#    #+#             */
/*   Updated: 2021/01/06 21:54:25 by lbenedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_processor.h"

static size_t	ft_count_char(unsigned long long oct)
{
	size_t len;

	if (oct)
		len = 0;
	else
		len = 1;
	while (oct)
	{
		oct /= 8;
		len++;
	}
	return (len);
}

static char		*ft_oct_to_str(unsigned long long oct)
{
	char	*str;
	size_t	strlen;

	strlen = ft_count_char(oct);
	if (!(str = malloc(sizeof(char) * (strlen + 1))))
		return (0);
	str[strlen] = 0;
	--strlen;
	if (!oct)
		str[0] = '0';
	while (oct)
	{
		str[strlen] = oct % 8 + 48;
		oct /= 8;
		strlen--;
	}
	return (str);
}

size_t			ft_proc_oct(t_placeholder *ph, unsigned long long oct)
{
	size_t	len;
	char	*str;
	char	*substr;

	len = 0;
	oct = ft_proc_spec_us(ph, oct);
	if ((str = 0) || oct || ph->precision)
		if (!(str = ft_oct_to_str(oct)))
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
