/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printlonglong.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeisson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 14:34:06 by mmeisson          #+#    #+#             */
/*   Updated: 2016/05/20 10:04:29 by mmeisson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int			ft_getsize(unsigned long long nb)
{
	long long		ret;

	ret = 1;
	while (nb >= 10)
	{
		ret++;
		nb /= 10;
	}
	return (ret);
}

int					ft_printlonglong(va_list ap)
{
	unsigned long long		n;
	int						ret;
	int						len;
	long long				nb;

	nb = va_arg(ap, long long);
	ret = (nb < 0) ? 1 : 0;
	n = (nb < 0) ? (unsigned long long)-nb : (unsigned long long)nb;
	ret += ft_getsize(n);
	g_conf.len += ret;
	len = g_conf.len;
	while (n >= 10)
	{
		g_conf.print[--len] = (n % 10) + '0';
		n /= 10;
	}
	g_conf.print[--len] = n % 10 + '0';
	if (nb < 0)
		g_conf.print[--len] = '-';
	return (ret);
}

int					ft_printulonglong(va_list ap)
{
	int					ret;
	int					len;
	unsigned long long	n;

	n = va_arg(ap, unsigned long long);
	ret = ft_getsize(n);
	g_conf.len += ret;
	len = g_conf.len;
	while (n >= 10)
	{
		g_conf.print[--len] = (n % 10) + '0';
		n /= 10;
	}
	g_conf.print[--len] = n % 10 + '0';
	return (ret);
}
