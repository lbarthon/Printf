/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarthon <lbarthon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 14:53:13 by lbarthon          #+#    #+#             */
/*   Updated: 2019/10/14 10:53:29 by lbarthon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf_internal.h"

void	print_buffer(t_printf *data, char force)
{
	if ((!force && data->buff_len != 2048) || data->buff_len == 0)
		return ;
	write(data->fd, data->buffer, data->buff_len);
	data->total_len += data->buff_len;
	data->buff_len = 0;
}

void	buffer_add_char(t_printf *data, char c)
{
	data->buffer[data->buff_len++] = c;
	print_buffer(data, 0);
}

void	buffer_add_str(t_printf *data, char *str, size_t end)
{
	short	copy_len;
	size_t	i;

	i = 0;
	while (end > i)
	{
		if (end - i <= (size_t)(2048 - data->buff_len))
			copy_len = end - i;
		else
			copy_len = 2048 - data->buff_len;
		ft_memcpy(data->buffer + data->buff_len, str + i, copy_len);
		data->buff_len += copy_len;
		print_buffer(data, 0);
		i += copy_len;
	}
}

void	buffer_add_format(t_printf *data, size_t end)
{
	buffer_add_str(data, (char*)data->format + data->index, end - data->index);
	data->index = end;
}
