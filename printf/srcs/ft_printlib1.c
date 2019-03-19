/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printlib1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeisson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 14:10:26 by mmeisson          #+#    #+#             */
/*   Updated: 2016/05/21 12:01:54 by mmeisson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

inline int			ft_printlen(char *str)
{
	char		*tmp;

	tmp = str;
	while (*tmp)
		tmp++;
	return (tmp - str);
}

inline int			ft_printstrnequ(char *s1, char *s2, int size)
{
	int			i;

	i = 0;
	while (i < size)
	{
		if (s1[i] != s2[i])
			return (0);
		else if (!s1[i])
			return (1);
		i++;
	}
	return (1);
}

inline int			ft_printstrequ(char *s1, char *s2)
{
	int		i;

	i = 0;
	while (s1[i] && s1[i] == s2[i])
		i++;
	if (s1[i] == s2[i])
		return (1);
	return (0);
}

inline char			*ft_printstrchr(char *s1, char c)
{
	while (*s1)
	{
		if (*s1 == c)
			return (s1);
		s1++;
	}
	return (NULL);
}
