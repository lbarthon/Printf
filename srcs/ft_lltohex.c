/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lltohex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarthon <lbarthon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 08:27:09 by lbarthon          #+#    #+#             */
/*   Updated: 2018/12/01 09:56:34 by lbarthon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Warning, this function uses malloc, the char* need to be free to avoid leaks
*/

#include "includes.h"

static int	ft_hex_size(long long nb)
{
	unsigned long long	nbr;
	int					size;

	size = 0;
	if (nb < 0)
		nbr = -nb;
	else
		nbr = nb;
	while (nbr > 15)
	{
		size++;
		nbr /= 16;
	}
	return (size);
}

char		*ft_lltohex(long long nbr, int addr)
{
	char	*hex;
	int		i;
	int		pos;

	pos = ft_hex_size(nbr);
	if (addr)
		pos += 2;
	if (!(hex = ft_strnew(pos + 3)))
		return (NULL);
	if (addr)
		ft_strcat(hex, "0x");
	while (nbr > 0)
	{
		i = nbr % 16;
		if (i < 10)
			hex[pos--] = 48 + i;
		else
			hex[pos--] = 'a' - 10 + i;
		nbr /= 16;
	}
	return (hex);
}
