/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarthon <lbarthon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 09:06:36 by lbarthon          #+#    #+#             */
/*   Updated: 2018/12/01 11:39:34 by lbarthon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"

int		ft_print_chars(int times, int c)
{
	char	buff[32];
	int		i;

	i = 0;
	while (i < 32)
		buff[i++] = c;
	i = times;
	while (i >= 32)
	{
		write(1, buff, 32);
		i -= 32;
	}
	if (i != 0)
		write(1, buff, i);
	return ((times > 0 ? times : 0));
}

int		ft_get_next_pos(const char *format)
{
	int i;

	i = 0;
	if (format)
	{
		if (ft_starts_with(format, "%%"))
			return (2);
		while (format[i])
		{
			if (ft_isprintf(format[i]))
				return (i + 1);
			i++;
		}
	}
	return (1);
}

int		ft_printf(const char *restrict format, ...)
{
	va_list	args;
	int		pos;
	int		len;
	int		total_len;

	va_start(args, format);
	pos = 0;
	total_len = 0;
	ft_struct(0);
	while (format)
	{
		len = ft_print_till_next(format + pos);
		total_len += len;
		pos += len;
		if (!(format + pos) || !*(format + pos) ||
				pos >= ft_strlen_cst(format))
			break ;
		len = ft_print_arg(format + pos, &args);
		total_len += len;
		pos += ft_get_next_pos(format + pos);
	}
	va_end(args);
	ft_struct(2);
	return (total_len);
}
