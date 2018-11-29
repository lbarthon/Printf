/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarthon <lbarthon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 09:06:36 by lbarthon          #+#    #+#             */
/*   Updated: 2018/11/29 11:44:55 by lbarthon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"
#include <stdio.h>

int		ft_get_next_pos(const char *format)
{
	int i;

	i = 0;
	if (format)
		while (!ft_isprintf(format[i]))
			i++;
	return (i + 1);
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
			break;
		len = ft_print_arg(format + pos, &args);
		total_len += len;
		pos += ft_get_next_pos(format + pos);
	}
	va_end(args);
	ft_struct(2);
	return (total_len);
}
