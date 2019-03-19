/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printoctal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeisson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 00:16:59 by mmeisson          #+#    #+#             */
/*   Updated: 2016/05/20 17:01:50 by mmeisson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ft_getsize(unsigned int nb)
{
	int		ret;

	ret = 1;
	while (nb >= 8)
	{
		ret++;
		nb /= 8;
	}
	return (ret);
}

int				ft_printoctal(va_list ap, t_printdatas *d)
{
	int				ret;
	int				len;
	unsigned int	n;

	if (ft_printstrnequ("hh", d->flags, 2))
		n = (unsigned char)va_arg(ap, unsigned int);
	else if (ft_printstrnequ("h", d->flags, 1))
		n = (unsigned short)va_arg(ap, unsigned int);
	else
		n = va_arg(ap, unsigned int);
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
