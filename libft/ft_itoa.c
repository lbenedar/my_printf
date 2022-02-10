/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenedar <lbenedar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 17:34:28 by lbenedar          #+#    #+#             */
/*   Updated: 2021/01/16 11:49:17 by lbenedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_countn(long long n)
{
	int	len;

	len = 1;
	if (n < 0)
		len++;
	while ((n > 9) || (n < -9))
	{
		len++;
		n /= 10;
	}
	return (len);
}

static void	ft_itstr(long long n, int len, char *str)
{
	long long pow;

	pow = 1;
	while (len > 1)
	{
		pow *= 10;
		len--;
	}
	len = 0;
	if (n < 0)
	{
		str[len] = (n / pow) * (-1) + '0';
		n = (n % pow) * (-1);
		pow /= 10;
		len++;
	}
	while (pow)
	{
		str[len] = n / pow + '0';
		n = n % pow;
		pow /= 10;
		len++;
	}
	str[len] = 0;
}

char		*ft_itoa(long long n)
{
	int		len;
	char	*str;

	len = ft_countn(n);
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (0);
	if (n < 0)
	{
		str[0] = '-';
		len--;
		ft_itstr(n, len, &str[1]);
	}
	else
		ft_itstr(n, len, str);
	return (str);
}
