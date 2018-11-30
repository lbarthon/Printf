/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_contains.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarthon <lbarthon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 11:49:54 by lbarthon          #+#    #+#             */
/*   Updated: 2018/11/30 13:50:07 by lbarthon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"

int		ft_contains(const char *haystack, const char *needle)
{
	int i;
	int j;

	i = 0;
	if (haystack == needle)
		return (1);
	while (haystack[i] && !ft_isprintf(haystack[i]))
	{
		j = 0;
		while (haystack[i] == needle[j] && haystack[i] &&
				!ft_isprintf(haystack[i]))
		{
			i++;
			j++;
		}
		if (!needle[j])
			return (1);
		i -= j;
		i++;
	}
	return (0);
}

int		ft_has_char(const char *format, const char c)
{
	int i;

	i = 0;
	while (format && *(format + i) && !ft_isprintf(*(format + i)))
	{
		if (*(format + i) == c)
			return (1);
		i++;
	}
	return (0);
}
