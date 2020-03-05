/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarthon <lbarthon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 09:59:40 by lbarthon          #+#    #+#             */
/*   Updated: 2019/11/27 12:31:45 by lbarthon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf_internal.h"

static size_t	get_pow(long long nbr)
{
	size_t	pow;

	pow = 10;
	while (pow <= (size_t)nbr)
		pow *= 10;
	return (pow / 10);
}

void			int_handler(t_printf *data, t_flags *flags)
{
	char		ret[64];
	long long	nbr;
	size_t		pow;
	int			i;

	i = 0;
	ft_bzero(ret, 64);
	nbr = va_arg(*data->args, int);
	if (nbr < 0)
	{
		ret[i++] = '-';
		nbr = -nbr;
	}
	pow = get_pow(nbr);
	while (pow > 0)
	{
		ret[i++] = ((int)(nbr / pow) % 10) + 48;
		pow = pow == 1 ? 0 : pow / 10;
	}
	add_with_flags(data, flags, ret, flags->zero);
}
