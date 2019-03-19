/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printflush.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeisson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/21 10:57:44 by mmeisson          #+#    #+#             */
/*   Updated: 2016/05/21 11:23:20 by mmeisson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			ft_printflush(void)
{
	write(g_conf.fd, g_conf.print, g_conf.len);
	g_conf.ret += g_conf.len;
	ft_printbzero(g_conf.print, g_conf.size);
	g_conf.len = 0;
}
