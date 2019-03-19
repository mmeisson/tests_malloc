/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prlonghexa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeisson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 00:19:51 by mmeisson          #+#    #+#             */
/*   Updated: 2016/05/20 12:50:18 by mmeisson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int			ft_getsize(unsigned long nb)
{
	int		ret;

	ret = 1;
	while (nb >= 16)
	{
		ret++;
		nb /= 16;
	}
	return (ret);
}

int					ft_printlonghexa_max(va_list ap)
{
	const char			hexa[] = "0123456789ABCDEF";
	int					ret;
	int					len;
	unsigned long		n;

	n = va_arg(ap, unsigned long);
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

int					ft_printlonghexa_min(va_list ap)
{
	const char			hexa[] = "0123456789abcdef";
	int					ret;
	int					len;
	unsigned long		n;

	n = va_arg(ap, unsigned long);
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
