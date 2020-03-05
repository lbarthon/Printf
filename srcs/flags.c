/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarthon <lbarthon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 09:22:51 by lbarthon          #+#    #+#             */
/*   Updated: 2019/11/27 12:45:02 by lbarthon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf_internal.h"

static char	flags(t_flags *flags, const char *str)
{
	char ret;

	ret = 0;
	if (*str == '#' && (ret = 1))
		flags->hash = 0x1;
	else if (*str == '0' && !flags->minus && (ret = 1))
		flags->zero = 0x1;
	else if (*str == ' ' && !flags->plus && (ret = 1))
		flags->space = 0x1;
	else if (*str == '-' && (ret = 1))
	{
		flags->zero = 0x0;
		flags->minus = 0x1;
	}
	else if (*str == '+' && (ret = 1))
	{
		flags->space = 0x0;
		flags->plus = 0x1;
	}
	return (ret);
}

static char	all(t_flags *f, const char *str)
{
	if (flags(f, str))
		return (1);
	return (0);
}

void		parse_flags(t_printf *data, t_flags *flags, size_t end)
{
	size_t	i;

	i = data->index;
	while (++i <= end)
		if (!all(flags, data->format + i))
			break ;
	flags->minlen = (size_t)ft_atoi(data->format + i);
}
