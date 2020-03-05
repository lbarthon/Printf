/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarthon <lbarthon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 13:48:03 by lbarthon          #+#    #+#             */
/*   Updated: 2019/11/27 12:32:18 by lbarthon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf_internal.h"

static size_t	get_pow(size_t nbr)
{
	size_t	pow;

	pow = 16;
	while (pow <= nbr)
		pow *= 16;
	return (pow / 16);
}

static void		main_handler(t_printf *data, t_flags *flags, char maj)
{
	char	hex[33];
	size_t	nbr;
	size_t	pow;
	int		i;

	i = 0;
	ft_bzero(hex, 33);
	nbr = (size_t)va_arg(*data->args, unsigned int);
	pow = get_pow(nbr);
	while (pow > 0)
	{
		hex[i] = (nbr / pow) % 16;
		if (hex[i] >= 10)
			hex[i] += (maj ? 'A' : 'a') - 10;
		else
			hex[i] += 48;
		pow = pow == 1 ? 0 : pow / 16;
		i++;
	}
	hex[i] = 0;
	add_with_flags(data, flags, hex, flags->zero);
}

void			hex_maj_handler(t_printf *data, t_flags *flags)
{
	main_handler(data, flags, 1);
}

void			hex_handler(t_printf *data, t_flags *flags)
{
	main_handler(data, flags, 0);
}
