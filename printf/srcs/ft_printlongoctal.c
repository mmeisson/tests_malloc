/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printlongoctal.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeisson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 18:37:22 by mmeisson          #+#    #+#             */
/*   Updated: 2016/05/20 10:06:36 by mmeisson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ft_getsize(unsigned long nb)
{
	long		ret;

	ret = 1;
	while (nb >= 8)
	{
		ret++;
		nb /= 8;
	}
	return (ret);
}

int				ft_printlongoctal(va_list ap)
{
	int				ret;
	int				len;
	unsigned long	n;

	n = va_arg(ap, unsigned long);
	ret = ft_getsize(n);
	g_conf.len += ret;
	len = g_conf.len;
	while (n >= 8)
	{
		g_conf.print[--len] = (n % 8) + '0';
		n /= 8;
	}
	g_conf.print[--len] = (n % 8) + '0';
	return (ret);
}
