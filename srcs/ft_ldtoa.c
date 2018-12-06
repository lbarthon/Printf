/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ldtoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarthon <lbarthon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 14:54:30 by lbarthon          #+#    #+#             */
/*   Updated: 2018/12/06 11:54:09 by lbarthon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"

int			ft_ldlen(long double nbr, int prec)
{
	int		size;
	int		sign;
	int		i;

	sign = nbr < 0;
	size = 1;
	if (nbr < 0)
		nbr = -nbr;
	i = -1;
	while (nbr >= 10)
	{
		nbr /= 10;
		size++;
	}
	if (prec == 0)
		return (size + sign);
	return (size + sign + prec + 1);
}

static char	*ft_re_create(char *str)
{
	char *new;

	if (!(new = (char*)ft_strnew(ft_strlen(str) + 2)))
		return (NULL);
	*new = '1';
	ft_strcat(new, str);
	free(str);
	return (new);
}

static char	*ft_round(char *str, int len)
{
	int l;

	l = len;
	if (str[len] >= '5')
	{
		while (str[len] == '9')
		{
			str[len--] = '0';
			if (str[len] == '.')
				len--;
		}
		if (str[len] == '.')
			len--;
		str[len]++;
	}
	str[l] = '\0';
	if (*str == '0')
		return (ft_re_create(str));
	return (str);
}

char		*ft_ldtoa(long double nbr, int prec)
{
	char		*str;
	int			i;
	int			len;

	len = ft_ldlen(nbr, prec);
	if (!(str = (char*)ft_strnew(len + 2)))
		return (NULL);
	i = 0;
	if (nbr < 0 && (nbr = -nbr))
		str[i++] = '-';
	while (nbr >= 10)
		nbr /= 10;
	while (i <= len)
	{
		str[i++] = (int)nbr + 48;
		nbr -= (int)nbr;
		nbr *= 10;
		if (i == len - prec - 1 && prec != 0)
			str[i++] = '.';
	}
	str[i++] = '\0';
	return (ft_round(str, len));
}
