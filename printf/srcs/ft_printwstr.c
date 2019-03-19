/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printwstr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeisson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/14 17:54:52 by mmeisson          #+#    #+#             */
/*   Updated: 2016/05/21 11:05:13 by mmeisson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_printwstr(va_list ap, t_printdatas *d)
{
	wchar_t			*tmp;
	wchar_t			*str;
	const wchar_t	def[] = L"(null)";
	int				ret;

	str = va_arg(ap, wchar_t *);
	if (str == NULL)
		str = (wchar_t *)def;
	tmp = str;
	while (*str)
	{
		ret = ft_printwchar_intern(*str, d);
		if (d->precision == 0 || ret == -1)
			break ;
		str++;
		if (g_conf.len + 8 >= g_conf.size)
			ft_printflush();
	}
	return (str - tmp);
}
