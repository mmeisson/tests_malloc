/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mask_first.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeisson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/20 10:52:49 by mmeisson          #+#    #+#             */
/*   Updated: 2016/05/20 10:59:08 by mmeisson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_mask_one(wchar_t c)
{
	g_conf.print[g_conf.len++] = c;
}

void		ft_mask_two(wchar_t c)
{
	g_conf.print[g_conf.len++] = 0xc0 | (c >> 6);
	g_conf.print[g_conf.len++] = 0x80 | (c & 0x3f);
}

void		ft_mask_three(wchar_t c)
{
	g_conf.print[g_conf.len++] = 0xe0 | (c >> 12);
	g_conf.print[g_conf.len++] = 0x80 | ((c >> 6) & 0x3f);
	g_conf.print[g_conf.len++] = 0x80 | (c & 0x3f);
}

void		ft_mask_four(wchar_t c)
{
	g_conf.print[g_conf.len++] = 0xf0 | (c >> 18);
	g_conf.print[g_conf.len++] = 0x80 | ((c >> 12) & 0x3f);
	g_conf.print[g_conf.len++] = 0x80 | ((c >> 6) & 0x3f);
	g_conf.print[g_conf.len++] = 0x80 | (c & 0x3f);
}

void		ft_mask_five(wchar_t c)
{
	g_conf.print[g_conf.len++] = 0xf8 | (c >> 24);
	g_conf.print[g_conf.len++] = 0x80 | ((c >> 18) & 0x3f);
	g_conf.print[g_conf.len++] = 0x80 | ((c >> 12) & 0x3f);
	g_conf.print[g_conf.len++] = 0x80 | ((c >> 6) & 0x3f);
	g_conf.print[g_conf.len++] = 0x80 | (c & 0x3f);
}
