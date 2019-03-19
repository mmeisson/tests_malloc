/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mask_sec.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeisson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/20 10:53:04 by mmeisson          #+#    #+#             */
/*   Updated: 2016/05/20 10:58:49 by mmeisson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_mask_six(wchar_t c)
{
	g_conf.print[g_conf.len++] = 0xfc | (c >> 30);
	g_conf.print[g_conf.len++] = 0x80 | ((c >> 24) & 0x3f);
	g_conf.print[g_conf.len++] = 0x80 | ((c >> 18) & 0x3f);
	g_conf.print[g_conf.len++] = 0x80 | ((c >> 12) & 0x3f);
	g_conf.print[g_conf.len++] = 0x80 | ((c >> 6) & 0x3f);
	g_conf.print[g_conf.len++] = 0x80 | (c & 0x3f);
}
