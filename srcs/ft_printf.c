/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarthon <lbarthon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 09:06:36 by lbarthon          #+#    #+#             */
/*   Updated: 2018/11/28 09:52:46 by lbarthon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"

int		ft_printf(const char *restrict format, ...)
{
	va_list	args;
	int		pos;

	va_start(args, format);
	pos = 0;
	if (format)
		while ((pos += ft_print_till_next(format + pos)))
			ft_print_arg(format + pos, &args);
	va_end(args);
	return (0);
}
