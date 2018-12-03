/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lltooctal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarthon <lbarthon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 09:31:34 by lbarthon          #+#    #+#             */
/*   Updated: 2018/12/03 09:45:51 by lbarthon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"

static int	ft_get_octal_len(unsigned long long nbr)
{
	int len;

	len = 1;
	while (nbr >= 8)
	{
		nbr /= 8;
		len++;
	}
	return (len);
}

char		*ft_lltooctal(unsigned long long nbr)
{
	char	*str;
	int		len;

	len = ft_get_octal_len(nbr);
	if (!(str = (char*)malloc(len + 1)))
		return (NULL);
	str[len] = '\0';
	while (len--)
	{
		str[len] = (nbr % 8) + 48;
		nbr /= 8;
	}
	return (str);
}
