/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenedar <lbenedar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/03 19:51:48 by lbenedar          #+#    #+#             */
/*   Updated: 2021/01/16 11:49:33 by lbenedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_countn(unsigned long long n)
{
	int	len;

	len = 1;
	while (n > 9)
	{
		len++;
		n /= 10;
	}
	return (len);
}

static void	ft_itstr(unsigned long long n, int len, char *str)
{
	unsigned long long pow;

	pow = 1;
	while (len > 1)
	{
		pow *= 10;
		len--;
	}
	len = 0;
	while (pow)
	{
		str[len] = n / pow + '0';
		n = n % pow;
		pow /= 10;
		len++;
	}
	str[len] = 0;
}

char		*ft_uitoa(unsigned long long n)
{
	int		len;
	char	*str;

	len = ft_countn(n);
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (0);
	ft_itstr(n, len, str);
	return (str);
}
