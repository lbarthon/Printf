/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarthon <lbarthon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 09:06:36 by lbarthon          #+#    #+#             */
/*   Updated: 2019/10/13 15:00:26 by lbarthon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static void		init_printf(t_printf *data, const char *format)
{
	ft_bzero(data->buffer, 2048);
	data->format = format;
	data->index = 0;
	data->total_len = 0;
	data->buff_len = 0;
	data->fd = 1;
}

static void		end_printf(t_printf *data)
{
	if (data->buff_len > 0)
		print_buffer(data, 1);
}

static void		prep_next_flag(t_printf *data)
{
	size_t	i;

	i = data->index;
	while (*(data->format + data->index + i)
			&& *(data->format + data->index + i) != '%')
		i++;
	buffer_add_format(data, i);
}

int				ft_printf(const char *restrict format, ...)
{
	va_list		args;
	t_printf	data;

	va_start(args, format);
	init_printf(&data, format);
	while (*(format + data.index))
	{
		prep_next_flag(&data);
		if (*(data->format + data->index))
			modules_handler(&data);
	}
	end_printf(&data);
	va_end(args);
	return (data.total_len);
}
