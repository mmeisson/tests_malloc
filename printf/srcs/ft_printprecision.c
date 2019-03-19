/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printprecision.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeisson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 21:51:05 by mmeisson          #+#    #+#             */
/*   Updated: 2016/05/21 12:06:45 by mmeisson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void			ft_precision_dioux(int origin, t_printdatas *d)
{
	int		move;
	char	c;

	c = '0';
	if (d->precision == 0 && g_conf.print[origin] == '0')
	{
		g_conf.print[origin] = '\0';
		g_conf.len = origin;
	}
	else if (g_conf.print[origin] == '-' || g_conf.print[origin] == '+')
		origin++;
	move = d->precision - (g_conf.len - origin);
	if ((d->conversion == 'O' || d->conversion == 'o') && d->alternate)
		move--;
	if (move > 0)
	{
		ft_printstrcpy(g_conf.print + origin + move, g_conf.print + origin);
		g_conf.len += move;
		while (move--)
			g_conf.print[origin + move] = c;
	}
}

static void			ft_precision_aef(int origin, t_printdatas *d)
{
	while (g_conf.print[origin] && g_conf.print[origin] != '.')
		origin++;
	if (!g_conf.print[origin++])
		return ;
	while (g_conf.print[origin] && d->precision--)
		origin++;
	g_conf.print[origin] = '\0';
	g_conf.len = origin;
}

static void			ft_precision_s(int origin, t_printdatas *d)
{
	while (g_conf.print[origin] && d->precision--)
		origin++;
	g_conf.print[origin] = '\0';
	g_conf.len = origin;
}

static void			ft_precision_p(int origin, t_printdatas *d)
{
	origin += 2;
	if (d->precision == 0)
	{
		if (g_conf.print[g_conf.len - 1] == '0')
			g_conf.print[--g_conf.len] = 0;
	}
	else if (d->precision <= g_conf.len - origin)
	{
		while (d->precision--)
		{
			if (g_conf.print[origin++] == '\0')
				g_conf.print[origin - 1] = '0';
		}
		if (g_conf.print[origin] == 0)
			g_conf.len = origin;
	}
	else
	{
		d->precision -= g_conf.len - origin;
		ft_printstrcpy(g_conf.print + origin + d->precision,
				g_conf.print + origin);
		g_conf.len += d->precision;
		while (d->precision--)
			g_conf.print[origin + d->precision] = '0';
	}
}

void				ft_apply_precision(int origin, t_printdatas *d)
{
	const char		*masks[5] = {
		"dioOuUxX",
		"aAeEfF",
		"s",
		"p",
	};

	if (ft_printstrchr((char*)masks[0], d->conversion))
		ft_precision_dioux(origin, d);
	else if (ft_printstrchr((char*)masks[1], d->conversion))
		ft_precision_aef(origin, d);
	else if (ft_printstrchr((char*)masks[2], d->conversion))
		ft_precision_s(origin, d);
	else if (ft_printstrchr((char*)masks[3], d->conversion))
		ft_precision_p(origin, d);
}
