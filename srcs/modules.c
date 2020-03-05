/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modules.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarthon <lbarthon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 13:41:13 by lbarthon          #+#    #+#             */
/*   Updated: 2019/11/27 12:51:31 by lbarthon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf_internal.h"

void		modules_handler(t_printf *data)
{
	t_flags	flags;
	char	m;
	int		i;
	int		j;

	i = 0;
	ft_bzero(&flags, sizeof(flags));
	while ((m = *(data->format + data->index + i)))
	{
		j = -1;
		while (++j < data->modules_len)
			if (data->modules[j].c == m)
			{
				parse_flags(data, &flags, i + 1);
				data->modules[j].exec(data, &flags);
				data->index += i + 1;
				return ;
			}
		i++;
	}
	buffer_add_format(data, i);
}

static void	add_spaces(t_printf *data, char c[32], int len)
{
	while (len > 0)
	{
		if (len < 32)
			buffer_add_str(data, c, len);
		else
			buffer_add_str(data, c, 32);
		if (len < 32)
			break ;
		len -= 32;
	}
}

void		add_with_flags(t_printf *data, t_flags *flags, char *ret, char zero)
{
	char	c[32];
	size_t	l;

	l = (size_t)ft_strlen(ret);
	if (flags->minlen > l)
	{
		if (zero)
			ft_fill(c, 32, '0');
		else
			ft_fill(c, 32, ' ');
	}
	if (!flags->minus)
		add_spaces(data, c, flags->minlen - l);
	buffer_add_str(data, ret, l);
	if (flags->minus)
		add_spaces(data, c, flags->minlen - l);
}
