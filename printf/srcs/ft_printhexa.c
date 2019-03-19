/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhexa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeisson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 00:19:51 by mmeisson          #+#    #+#             */
/*   Updated: 2016/05/20 17:10:29 by mmeisson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ft_getsize(unsigned int nb)
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

int				ft_printhexa_max(va_list ap, t_printdatas *d)
{
	const char			hexa[] = "0123456789ABCDEF";
	int					ret;
	int					len;
	unsigned int		n;

	if (ft_printstrnequ("hh", d->flags, 2))
		n = (unsigned char)va_arg(ap, unsigned int);
	else if (ft_printstrnequ("h", d->flags, 1))
		n = (unsigned short)va_arg(ap, unsigned int);
	else
		n = va_arg(ap, unsigned int);
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

int				ft_printhexa_min(va_list ap, t_printdatas *d)
{
	const char			hexa[] = "0123456789abcdef";
	int					ret;
	int					len;
	unsigned int		n;

	if (ft_printstrnequ("hh", d->flags, 2))
		n = (unsigned char)va_arg(ap, unsigned int);
	else if (ft_printstrnequ("h", d->flags, 1))
		n = (unsigned short)va_arg(ap, unsigned int);
	else
		n = va_arg(ap, unsigned int);
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
