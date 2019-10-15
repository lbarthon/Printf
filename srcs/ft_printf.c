/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarthon <lbarthon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 09:06:36 by lbarthon          #+#    #+#             */
/*   Updated: 2019/10/15 11:40:45 by lbarthon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf_internal.h"

static void		init_printf(t_printf *data, const char *format, va_list *args)
{
	ft_bzero(data->buffer, 2048);
	data->format = format;
	data->args = args;
	data->index = 0;
	data->total_len = 0;
	data->buff_len = 0;
	data->fd = 1;
	data->modules[0] = (t_pfmodule) {&string_handler, 's'};
	data->modules[1] = (t_pfmodule) {&int_handler, 'd'};
	data->modules[2] = (t_pfmodule) {&pointer_handler, 'p'};
	data->modules[3] = (t_pfmodule) {&char_handler, 'c'};
	data->modules_len = 4;
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
	while (*(data->format + i))
		if (*(data->format + i) == '%')
			break ;
		else
			i++;
	buffer_add_format(data, i);
}

int				ft_printf(const char *restrict format, ...)
{
	va_list		args;
	t_printf	data;

	va_start(args, format);
	init_printf(&data, format, &args);
	while (*(format + data.index))
	{
		prep_next_flag(&data);
		if (*(data.format + data.index))
			modules_handler(&data);
	}
	end_printf(&data);
	va_end(args);
	return (data.total_len);
}
