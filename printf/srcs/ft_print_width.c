/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_width.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeisson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/21 13:05:08 by mmeisson          #+#    #+#             */
/*   Updated: 2016/05/21 13:26:10 by mmeisson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ft_norme(int *origin, char *c)
{
	*c = '0';
	if (g_conf.print[*origin] == '-' || g_conf.print[*origin] == '+' ||
			g_conf.print[*origin] == ' ')
		(*origin)++;
	else if (ft_printstrnequ(g_conf.print + *origin, "0x", 2))
		*origin += 2;
}

void			ft_apply_width(int origin, t_printdatas *d)
{
	int		move;
	char	c;

	move = d->min_size - (g_conf.len - origin);
	if (move > 0)
	{
		if (d->zero && !d->l_align)
			ft_norme(&origin, &c);
		else
			c = ' ';
		if (d->l_align == 0)
		{
			ft_printstrcpy(g_conf.print + origin + move, g_conf.print + origin);
			g_conf.len += move;
			while (move--)
				g_conf.print[origin + move] = c;
		}
		else
			while (move--)
				g_conf.print[g_conf.len++] = c;
	}
}
