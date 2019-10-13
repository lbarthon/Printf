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

void	string_handler(t_printf *data);
void	int_handler(t_printf *data);

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
	data->modules_len = 2;
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
