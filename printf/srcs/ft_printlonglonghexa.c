/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printlonglonghexa.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeisson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 14:34:50 by mmeisson          #+#    #+#             */
/*   Updated: 2016/05/20 10:15:20 by mmeisson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int			ft_getsize(unsigned long long nb)
{
	long long		ret;

	ret = 1;
	while (nb >= 16)
	{
		ret++;
		nb /= 16;
	}
	return (ret);
}

int					ft_printlonglonghexa_max(va_list ap)
{
	const char			hexa[] = "0123456789ABCDEF";
	int					ret;
	int					len;
	unsigned long long	n;

	n = va_arg(ap, unsigned long long);
	ret = ft_getsize(n);
	g_conf.len += ret;
	len = g_conf.len;
	while (n >= 16)
	{
		g_conf.print[--len] = hexa[n % 16];
		n /= 16;
	}
	g_conf.print[--len] = hexa[n % 16];
	return (ret);
}

int					ft_printlonglonghexa_min(va_list ap)
{
	const char			hexa[] = "0123456789abcdef";
	int					ret;
	int					len;
	unsigned long long	n;

	n = va_arg(ap, unsigned long long);
	ret = ft_getsize(n);
	g_conf.len += ret;
	len = g_conf.len;
	while (n >= 16)
	{
		g_conf.print[--len] = hexa[n % 16];
		n /= 16;
	}
	g_conf.print[--len] = hexa[n % 16];
	return (ret);
}
