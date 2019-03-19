/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printparsing.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeisson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 15:09:25 by mmeisson          #+#    #+#             */
/*   Updated: 2016/05/30 08:53:09 by mmeisson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Format acceptes :
** %s : string
** %S : string wchar_t
** %c : char
** %C : wchar_t
** %d : int
** %D : long
** %o : int in octal
** %u : unsigned int
** %x : int in min-hexa
** %X : int in MAJ-hexa
** %p : addr
** %P : addr in MAJ
*/

static int		ft_getformat(char **format, t_printdatas *d)
{
	char		*str;

	str = *format;
	if (ft_get_flags(&str, d) == -1)
		return (-1);
	if (ft_get_width(&str, d) == -1)
		return (-1);
	if (ft_get_precision(&str, d) == -1)
		return (-1);
	ft_get_modif(&str, d);
	if (ft_get_conversion(&str, d) == -1)
		return (-1);
	*format = str;
	return (0);
}

const t_conv_function		g_fct_tab[] = {
	{ 's', ft_printstr },
	{ 'd', ft_printint },
	{ 'D', ft_printlong },
	{ 'i', ft_printint },
	{ 'c', ft_printchar },
	{ 'C', ft_printwchar },
	{ 'S', ft_printwstr },
	{ 'u', ft_printuint },
	{ 'U', ft_printulong },
	{ 'o', ft_printoctal },
	{ 'O', ft_printlongoctal },
	{ 'x', ft_printhexa_min },
	{ 'X', ft_printhexa_max },
	{ 'p', ft_printptr_min },
	{ 'P', ft_printptr_max },
};

const t_modif_function		g_fct_conv[] = {
	{ 'd', "hh", ft_printint },
	{ 'i', "hh", ft_printint },
	{ 'd', "h", ft_printint },
	{ 'i', "h", ft_printint },
	{ 'd', "l", ft_printlong },
	{ 'i', "l", ft_printlong },
	{ 'd', "z", ft_printlong },
	{ 'i', "z", ft_printlong },
	{ 'd', "ll", ft_printlonglong },
	{ 'i', "ll", ft_printlonglong },
	{ 'd', "j", ft_printlonglong },
	{ 'i', "j", ft_printlong },
	{ 'u', "hh", ft_printuint },
	{ 'o', "hh", ft_printoctal },
	{ 'x', "hh", ft_printhexa_min },
	{ 'X', "hh", ft_printhexa_max },
	{ 'u', "h", ft_printuint },
	{ 'o', "h", ft_printoctal },
	{ 'x', "h", ft_printhexa_min },
	{ 'X', "h", ft_printhexa_max },
	{ 'u', "l", ft_printulong },
	{ 'o', "l", ft_printlongoctal },
	{ 'x', "l", ft_printlonghexa_min },
	{ 'X', "l", ft_printlonghexa_max },
	{ 'u', "ll", ft_printulonglong },
	{ 'o', "ll", ft_printlonglongoctal },
	{ 'x', "ll", ft_printlonglonghexa_min },
	{ 'X', "ll", ft_printlonglonghexa_max },
	{ 'u', "z", ft_printulong },
	{ 'o', "z", ft_printlongoctal },
	{ 'x', "z", ft_printlonghexa_min },
	{ 'X', "z", ft_printlonghexa_max },
	{ 'u', "j", ft_printulonglong },
	{ 'o', "j", ft_printlonglongoctal },
	{ 'x', "j", ft_printlonglonghexa_min },
	{ 'X', "j", ft_printlonglonghexa_max },
	{ 'c', "l", ft_printwchar },
	{ 's', "l", ft_printwstr },
};

static int		ft_apply_conversion(va_list ap, t_printdatas *d)
{
	size_t		i;
	int			origin;

	origin = g_conf.len;
	i = 0;
	if ((d->flags)[i])
	{
		while (i < 39 && (g_fct_conv[i].conversion != d->conversion ||
				!ft_printstrequ(d->flags, (char *)(g_fct_conv[i].modifier))))
			i++;
		if (i < 39)
		{
			(g_fct_conv[i].fct)(ap, d);
			return (origin);
		}
	}
	i = 0;
	while (i < 15 && g_fct_tab[i].conversion != d->conversion)
		i++;
	if (i < 15)
		(g_fct_tab[i].fct)(ap, d);
	else
		g_conf.print[g_conf.len++] = '%';
	return (origin);
}

static void		ft_apply_flags(int origin, t_printdatas *d)
{
	const char		strpos[] = "aAdeEfFgGi";

	if (d->positiv)
	{
		if (ft_printstrchr((char*)strpos, d->conversion) &&
				g_conf.print[origin] != '-')
		{
			ft_printstrcpy(g_conf.print + origin + 1, g_conf.print + origin);
			g_conf.print[origin] = '+';
			g_conf.len++;
		}
	}
	else if (d->blank && g_conf.print[origin] != '-')
	{
		if (ft_printstrchr((char*)strpos, d->conversion))
		{
			ft_printstrcpy(g_conf.print + origin + 1, g_conf.print + origin);
			g_conf.print[origin] = ' ';
			g_conf.len++;
		}
	}
}

static int		ft_apply_alternate(int origin, t_printdatas *d)
{
	const char		min[] = "0x";
	const char		max[] = "0X";
	int				len;
	int				i;
	char			*str;

	if (ft_printstrequ(g_conf.print + origin, "0"))
		return (0);
	if (d->precision == 0 && (d->conversion == 'x' || d->conversion == 'X')
			&& g_conf.print[origin] == 0)
		return (0);
	str = (d->conversion >= 'a' && d->conversion <= 'z') ?
		(char *)min : (char *)max;
	if (d->conversion == 'x' || d->conversion == 'X')
		len = 2;
	else if (d->conversion == 'o' || d->conversion == 'O')
		len = 1;
	else
		return (0);
	ft_printstrcpy(g_conf.print + origin + len, g_conf.print + origin);
	g_conf.len += len;
	i = 0;
	while (i < len)
		g_conf.print[origin++] = str[i++];
	return (2);
}

int				ft_printparsing(char **format, va_list ap)
{
	t_printdatas	d;
	int				origin;

	ft_printbzero(&d, sizeof(d));
	d.precision = -1;
	if (!**format)
		return (0);
	if (ft_getformat(format, &d) == -1)
		return (-1);
	origin = ft_apply_conversion(ap, &d);
	if (d.precision + origin > g_conf.size || d.min_size + origin > g_conf.size)
		ft_printflush();
	if (origin == -1)
		return (-1);
	if (d.precision != -1)
		ft_apply_precision(origin, &d);
	ft_apply_flags(origin, &d);
	if (d.alternate)
		ft_apply_alternate(origin, &d);
	if (d.min_size)
		ft_apply_width(origin, &d);
	return (0);
}
