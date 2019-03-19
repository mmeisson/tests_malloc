/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printwchar.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeisson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 19:21:12 by mmeisson          #+#    #+#             */
/*   Updated: 2016/05/21 12:00:49 by mmeisson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				ft_printwchar_intern(wchar_t c, t_printdatas *d)
{
	static void		(*fct[6])(wchar_t) = {
		ft_mask_one,
		ft_mask_two,
		ft_mask_three,
		ft_mask_four,
		ft_mask_five,
		ft_mask_six,
	};
	const int		max[6] = {0x80, 0x800, 0x10000, 0x200000, 0x4000000,
		0x80000000};
	int				i;

	i = 0;
	while (i < 6 && c > max[i])
		if (++i == 5)
			break ;
	if (d->precision != -1 && i + 1 > d->precision && c)
		return (-1);
	if (d->precision != -1)
		d->precision -= (i + 1);
	fct[i](c);
	return (i);
}

int				ft_printwchar(va_list ap, t_printdatas *d)
{
	static void		(*fct[6])(wchar_t) = {
		ft_mask_one,
		ft_mask_two,
		ft_mask_three,
		ft_mask_four,
		ft_mask_five,
		ft_mask_six,
	};
	const int		max[6] = {0x80, 0x800, 0x10000, 0x200000, 0x4000000,
		0x80000000};
	int				i;
	wchar_t			c;

	c = va_arg(ap, wchar_t);
	i = 0;
	while (i < 6 && c > max[i])
		if (++i == 5)
			break ;
	if (d->precision != -1 && i + 1 > d->precision && c)
		return (0);
	fct[i](c);
	return (i);
}
