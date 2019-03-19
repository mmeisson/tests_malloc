/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeisson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 00:05:37 by mmeisson          #+#    #+#             */
/*   Updated: 2016/05/20 19:34:21 by mmeisson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ft_getsize(unsigned int nb)
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

int				ft_printint(va_list ap, t_printdatas *d)
{
	unsigned int		n;
	int					ret;
	int					len;
	int					nb;

	if (ft_printstrnequ("hh", d->flags, 2))
		nb = (char)va_arg(ap, int);
	else if (ft_printstrnequ("h", d->flags, 1))
		nb = (short)va_arg(ap, int);
	else
		nb = va_arg(ap, int);
	ret = (nb < 0) ? 1 : 0;
	n = (nb < 0) ? (unsigned int)-nb : (unsigned int)nb;
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

int				ft_printuint(va_list ap, t_printdatas *d)
{
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
	while (n >= 10)
	{
		g_conf.print[--len] = (n % 10) + '0';
		n /= 10;
	}
	g_conf.print[--len] = n % 10 + '0';
	return (ret);
}
