/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printget.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeisson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 16:23:33 by mmeisson          #+#    #+#             */
/*   Updated: 2016/05/21 08:42:09 by mmeisson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_get_width(char **format, t_printdatas *d)
{
	char		*str;

	str = *format;
	while (*str >= '0' && *str <= '9')
		d->min_size = (d->min_size * 10) + (*(str++) - '0');
	*format = str;
	return (0);
}

int			ft_get_modif(char **format, t_printdatas *d)
{
	const char		*flags[] = {"hh", "h", "ll", "l", "j", "z"};
	int				i;
	int				len;

	i = 0;
	while (i < 6)
	{
		len = ft_printlen((char *)(flags[i]));
		if (ft_printstrnequ((char *)(flags[i]), *format, len))
		{
			ft_printstrcpy(d->flags, (char *)(flags[i]));
			(*format) += len;
			break ;
		}
		i++;
	}
	return (0);
}

int			ft_get_precision(char **format, t_printdatas *d)
{
	char		*str;

	str = *format;
	if (*str == '.')
	{
		d->precision = 0;
		str++;
		while (*str >= '0' && *str <= '9')
			d->precision = (d->precision * 10) + (*(str++) - '0');
	}
	*format = str;
	return (0);
}

int			ft_get_flags(char **format, t_printdatas *d)
{
	char		*str;

	str = *format;
	while (*str)
	{
		if (*str == '#')
			d->alternate = 1;
		else if (*str == '0')
			d->zero = 1;
		else if (*str == '-')
			d->l_align = 1;
		else if (*str == '+')
			d->positiv = 1;
		else if (*str == ' ')
			d->blank = 1;
		else
			break ;
		str++;
	}
	*format = str;
	return (0);
}

int			ft_get_conversion(char **format, t_printdatas *d)
{
	const char		*conversion = "sSpdDioOuUxXcC%";
	const char		*nonzero = "sScC%";
	char			*f;

	f = *format;
	if (!ft_printstrchr((char *)conversion, *f))
		return (-1);
	if (d->precision != -1 && !ft_printstrchr((char *)nonzero, *f))
		d->zero = 0;
	d->conversion = *(f++);
	*format = f;
	return (0);
}
