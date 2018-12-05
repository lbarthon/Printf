/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarthon <lbarthon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 09:06:36 by lbarthon          #+#    #+#             */
/*   Updated: 2018/12/04 13:47:52 by lbarthon         ###   ########.fr       */
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
		if (*format == '%')
			return (1);
		while (format[i])
		{
			if (ft_isprintf(format[i]))
				return (i + 1);
			if (!ft_isflag(format[i]) && !ft_isdigit(format[i]) &&
					format[i] != '.')
				return (i);
			i++;
		}
	}
	return (1);
}

int		ft_is_ended(const char *format, int pos)
{
	if (!(format + pos) || !*(format + pos) ||
			pos >= ft_strlen_cst(format))
		return (1);
	return (0);
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
		if (ft_is_ended(format, pos))
			break ;
		len = ft_print_arg(format + pos, &args);
		total_len += len;
		pos += 1 + ft_get_next_pos(format + pos + 1);
		if (ft_is_ended(format, pos))
			break ;
	}
	va_end(args);
	ft_struct(2);
	return (total_len);
}
