/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lltohex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarthon <lbarthon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 08:27:09 by lbarthon          #+#    #+#             */
/*   Updated: 2018/12/04 09:21:39 by lbarthon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Warning, this function uses malloc, the char* need to be free to avoid leaks
*/

#include "includes.h"

static int	ft_hex_size(unsigned long long nbr)
{
	int size;

	size = 0;
	while (nbr > 15)
	{
		size++;
		nbr /= 16;
	}
	return (size);
}

char		*ft_lltohex(unsigned long long nbr, int addr)
{
	char	*hex;
	int		i;
	int		pos;

	pos = ft_hex_size(nbr);
	if (addr)
		pos += 2;
	if (!(hex = ft_strnew(pos + 1)))
		return (NULL);
	if (addr)
		ft_strcat(hex, "0x");
	while (nbr > 15)
	{
		i = nbr % 16;
		if (i < 10)
			hex[pos--] = 48 + i;
		else
			hex[pos--] = 'a' - 10 + i;
		nbr /= 16;
	}
	if (nbr < 10)
		hex[pos--] = 48 + nbr;
	else
		hex[pos--] = 'a' - 10 + nbr;
	return (hex);
}
