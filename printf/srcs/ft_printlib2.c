/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printlib2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeisson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/21 12:01:31 by mmeisson          #+#    #+#             */
/*   Updated: 2016/05/21 12:03:37 by mmeisson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

inline void			ft_printbzero(void *ptr, int size)
{
	unsigned char		*p;

	p = (unsigned char*)ptr;
	while (size--)
	{
		p[size] = 0;
	}
}

inline void			ft_printstrcpy(char *dst, char *src)
{
	int		i;

	i = 0;
	if (dst < src)
	{
		while ((dst[i] = src[i]))
			i++;
	}
	else
	{
		while (src[i])
			i++;
		dst[i] = '\0';
		while (i--)
			dst[i] = src[i];
	}
}

inline char			*ft_printstrnover(char *origin, char *str, size_t size)
{
	char		*ret;
	size_t		len;

	len = (origin) ? ft_printlen(origin) : 0;
	if (!(ret = malloc(sizeof(char) * (len + size + 1))))
		return (NULL);
	if (origin)
		ft_printstrcpy(ret, origin);
	ft_printstrcpy(ret + len, str);
	return (ret);
}
