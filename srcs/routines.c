/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarthon <lbarthon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 09:06:36 by lbarthon          #+#    #+#             */
/*   Updated: 2020/02/04 12:25:21 by lbarthon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf_internal.h"

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

void			init_printf(t_printf *data, const char *format, va_list *args)
{
	ft_bzero(data->buffer, 2048);
	data->format = format;
	data->args = args;
	data->index = 0;
	data->total_len = 0;
	data->buff_len = 0;
	data->fd = 1;
	data->sprintf = 0;
	data->modules[0] = (t_pfmodule) {&string_handler, 's'};
	data->modules[1] = (t_pfmodule) {&int_handler, 'd'};
	data->modules[2] = (t_pfmodule) {&int_handler, 'i'};
	data->modules[3] = (t_pfmodule) {&pointer_handler, 'p'};
	data->modules[4] = (t_pfmodule) {&char_handler, 'c'};
	data->modules[5] = (t_pfmodule) {&hex_handler, 'x'};
	data->modules[6] = (t_pfmodule) {&hex_maj_handler, 'X'};
	data->modules_len = 6;
}

int				printf_routine(t_printf *data)
{
	while (*(data->format + data->index))
	{
		prep_next_flag(data);
		if (*(data->format + data->index))
			modules_handler(data);
	}
	if (data->buff_len > 0)
		print_buffer(data, 1);
	if (data->args != NULL)
		va_end(*data->args);
	return (data->total_len);
}
