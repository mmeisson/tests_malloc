/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prlonglong.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeisson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 00:05:37 by mmeisson          #+#    #+#             */
/*   Updated: 2016/05/20 13:21:16 by mmeisson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ft_getsize(unsigned long nb)
{
	int		ret;

	ret = 1;
	while (nb >= 10)
	{
		ret++;
		nb /= 10;
	}
	return (ret);
}

int				ft_printlong(va_list ap)
{
	unsigned long		n;
	int					ret;
	int					len;
	long				nb;

	nb = va_arg(ap, long);
	ret = (nb < 0) ? 1 : 0;
	n = (nb < 0) ? (unsigned long)-nb : (unsigned long)nb;
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

int				ft_printulong(va_list ap)
{
	int					ret;
	int					len;
	unsigned long		n;

	n = va_arg(ap, unsigned long);
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
