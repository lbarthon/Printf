/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modules.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarthon <lbarthon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 13:41:13 by lbarthon          #+#    #+#             */
/*   Updated: 2019/10/14 12:14:43 by lbarthon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf_internal.h" 
#include "stdio.h"

void	modules_handler(t_printf *data)
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
				add_flags(data, &flags, i + 1);
				data->modules[j].exec(data, &flags);
				data->index += i + 1;
				return ;
			}
		i++;
	}
	buffer_add_format(data, i);
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
		while (flags->minlen > l)
		{
			if (flags->minlen - l < 32)
				buffer_add_str(data, c, flags->minlen - l);
			else
				buffer_add_str(data, c, 32);
			if (flags->minlen < 32)
				break ;
			flags->minlen -= 32;
		}
	}
	buffer_add_str(data, ret, l);
}
