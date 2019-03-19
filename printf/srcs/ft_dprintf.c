/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeisson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/10 23:56:01 by mmeisson          #+#    #+#             */
/*   Updated: 2016/05/30 08:52:27 by mmeisson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int			ft_printparse(char **format, va_list ap)
{
	char	*f;
	int		ret;

	f = *format + 1;
	ret = ft_printparsing(&f, ap);
	*format = f;
	return (ret);
}

static int			ft_print_init(int fd)
{
	if (fd > 0)
	{
		g_conf.len = 0;
		g_conf.ret = 0;
		g_conf.fd = fd;
		g_conf.size = PRINT_BUFF_SIZE;
		ft_printbzero(g_conf.print, g_conf.size);
		return (0);
	}
	return (-1);
}

int					ft_dprintf(int fd, char *format, ...)
{
	va_list		ap;
	int			parse;

	ft_print_init(fd);
	va_start(ap, format);
	while (*format)
	{
		if (*format == '%')
		{
			parse = ft_printparse(&format, ap);
			if (parse == -1)
			{
				va_end(ap);
				return (-1);
			}
		}
		else
			g_conf.print[g_conf.len++] = *(format++);
		if (g_conf.len >= g_conf.size - 30)
			ft_printflush();
	}
	write(g_conf.fd, g_conf.print, g_conf.len);
	g_conf.ret += g_conf.len;
	va_end(ap);
	return (g_conf.ret);
}
