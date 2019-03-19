/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printchars.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeisson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 00:00:45 by mmeisson          #+#    #+#             */
/*   Updated: 2016/05/21 11:23:22 by mmeisson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_printchar(va_list ap)
{
	char		c;

	c = (char)va_arg(ap, int);
	g_conf.print[g_conf.len++] = c;
	return (1);
}

int			ft_printstr(va_list ap)
{
	char		*s;
	char		*tmp;
	const char	def[] = "(null)";

	s = va_arg(ap, char *);
	tmp = s;
	if (s == NULL)
		s = (char*)def;
	while (*s)
	{
		g_conf.print[g_conf.len++] = *(s++);
		if (g_conf.len + 1 >= g_conf.size)
			ft_printflush();
	}
	return (s - tmp);
}
