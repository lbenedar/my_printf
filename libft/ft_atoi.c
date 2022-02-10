/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenedar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 13:24:46 by lbenedar          #+#    #+#             */
/*   Updated: 2021/01/06 19:23:56 by lbenedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

long long	ft_atoi(const char *nptr)
{
	long long	num;
	long long	neg;

	num = 0;
	neg = 1;
	while ((*nptr == ' ') || (*nptr == '\t') || (*nptr == '\n') ||
			(*nptr == '\r') || (*nptr == '\f') || (*nptr == '\v'))
		nptr++;
	if ((*nptr == '-') || (*nptr == '+'))
	{
		if (*nptr == '-')
			neg = -1;
		nptr++;
	}
	while ((*nptr >= '0') && (*nptr <= '9'))
	{
		num = num * 10 + (*nptr - '0') * neg;
		nptr++;
	}
	return (num);
}
