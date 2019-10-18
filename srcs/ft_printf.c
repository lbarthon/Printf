/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarthon <lbarthon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 18:29:25 by lbarthon          #+#    #+#             */
/*   Updated: 2019/10/18 13:38:08 by lbarthon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf_internal.h"

int				ft_printf(const char *restrict format, ...)
{
	va_list		args;
	t_printf	data;

	va_start(args, format);
	init_printf(&data, format, &args);
	return (printf_routine(&data));
}

int				ft_dprintf(int fd, const char *restrict format, ...)
{
	va_list		args;
	t_printf	data;

	va_start(args, format);
	init_printf(&data, format, &args);
	data.fd = fd;
	return (printf_routine(&data));
}

int				ft_sprintf(char *buff, const char *restrict format, ...)
{
	va_list		args;
	t_printf	data;
	int			ret;

	va_start(args, format);
	init_printf(&data, format, &args);
	data.sprintf = buff;
	ret = printf_routine(&data);
	buff[data.buff_len] = 0;
	return (ret);
}
