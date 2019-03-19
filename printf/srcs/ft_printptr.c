/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeisson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 00:22:32 by mmeisson          #+#    #+#             */
/*   Updated: 2016/05/20 10:07:40 by mmeisson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ft_getsize(size_t nb)
{
	int			ret;

	ret = 1;
	while (nb >= 16)
	{
		ret++;
		nb /= 16;
	}
	return (ret);
}

int				ft_printptr_max(va_list ap)
{
	const char		hexa[] = "0123456789ABCDEF";
	int				ret;
	int				len;
	size_t			n;
	void			*ptr;

	ptr = va_arg(ap, void *);
	n = (size_t)ptr;
	ret = ft_getsize(n) + 2;
	g_conf.len += ret;
	len = g_conf.len;
	while (n >= 16)
	{
		g_conf.print[--len] = hexa[n % 16];
		n /= 16;
	}
	g_conf.print[--len] = hexa[n % 16];
	g_conf.print[--len] = 'X';
	g_conf.print[--len] = '0';
	return (ret);
}

int				ft_printptr_min(va_list ap)
{
	const char		hexa[] = "0123456789abcdef";
	int				ret;
	int				len;
	size_t			n;
	void			*ptr;

	ptr = va_arg(ap, void *);
	n = (size_t)ptr;
	ret = ft_getsize(n) + 2;
	g_conf.len += ret;
	len = g_conf.len;
	while (n >= 16)
	{
		g_conf.print[--len] = hexa[n % 16];
		n /= 16;
	}
	g_conf.print[--len] = hexa[n % 16];
	g_conf.print[--len] = 'x';
	g_conf.print[--len] = '0';
	return (ret);
}
