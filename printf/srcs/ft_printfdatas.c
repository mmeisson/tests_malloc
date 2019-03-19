/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfdatas.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeisson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/21 11:50:30 by mmeisson          #+#    #+#             */
/*   Updated: 2016/05/21 11:52:55 by mmeisson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_get_other_flags(char **form, t_printdatas *d)
{
	const char	*other_flags[] = {
		"hh",
		"h",
		"l",
		"ll",
		"j",
		"z",
		NULL,
	};
	int			i;
	int			len;

	i = 0;
	while (other_flags[i])
	{
		len = ft_printstrlen(other_flags[i]);
		if (ft_printstrnequ(*form, other_flags[i], len))
		{
			ft_printstrcpy(d->other_flags, other_flags[i]);
			*form += len;
		}
		i++;
	}
}

static int	ft_get_precision(char **form, t_printdatas *d)
{
	char		*str;

	str = *form;
	if (*str == '.')
	{
		str++;
		if (*str == '*')
			d->precision_args = 1;
		else if (*str >= '0' && *str <= '9')
			while (*str >= '0' && *str <= '9')
			{
				d->precision *= 10 + (*str - '0');
				str++;
			}
		else
			return (-1);
	}
	return (0);
}

int			ft_print_getdatas(char **form, t_printdatas *d)
{
	const char		*flags = " #0-+";
	const char		conv[] = "sSpdDioOuUxXcC";
	char			*str;

	str = *form;
	str++;
	while (ft_printstrchr(flags, *str))
		ft_printstrccat(d->flags, *(str++));
	while (*str >= '0' && *str <= '9')
	{
		d->min_size *= 10 + (*str - '0');
		(*form)++;
	}
	if (ft_get_precision(&str, d) == -1)
		return (-1);
	ft_get_other_flags(&str, d);
	if (ft_printstrchr(conv, *str))
	{
		d->conversion = *(str++);
		*form = str;
		return (0);
	}
	*form = str;
	return (-1);
}

int			ft_security_control(t_printdatas *d, int len)
{
	if (d->conversion == 's' || d->conversion == 'S')
	{
		if (len > 3072)
			return (-1);
		return (0);
	}
	if (len > 3839)
		return (-1);
	return (0);
}
