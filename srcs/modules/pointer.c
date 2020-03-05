/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pointer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarthon <lbarthon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 11:14:48 by lbarthon          #+#    #+#             */
/*   Updated: 2019/11/27 12:32:05 by lbarthon         ###   ########.fr       */
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

static void		pointer_end(t_printf *data, t_flags *flags, char hex[32])
{
	if (!flags->space && flags->zero)
	{
		buffer_add_str(data, "0x", 2);
		add_with_flags(data, flags, hex + 2, 1);
	}
	else
		add_with_flags(data, flags, hex, 0);
}

void			pointer_handler(t_printf *data, t_flags *flags)
{
	char	hex[32];
	size_t	addr;
	size_t	pow;
	int		i;

	i = 0;
	hex[i++] = '0';
	hex[i++] = 'x';
	addr = (size_t)va_arg(*data->args, void *);
	pow = get_pow(addr);
	while (pow > 0)
	{
		hex[i] = (addr / pow) % 16;
		if (hex[i] >= 10)
			hex[i] += 'a' - 10;
		else
			hex[i] += 48;
		pow = pow == 1 ? 0 : pow / 16;
		i++;
	}
	hex[i] = 0;
	pointer_end(data, flags, hex);
}
