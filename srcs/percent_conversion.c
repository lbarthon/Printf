/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   percent_conversion.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarthon <lbarthon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 10:35:20 by lbarthon          #+#    #+#             */
/*   Updated: 2018/12/03 10:59:02 by lbarthon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"

int		ft_percent_conv(const char *format, va_list *args)
{
	int len;
	int prec;
	int min_len;

	min_len = ft_get_min_length(format);
	prec = ft_get_precision(format);
	if (ft_has_char(format, '-'))
	{
		ft_putchar('%');
		if (min_len > prec)
			len = 1 + ft_print_chars(min_len - 1, ' ');
		else
			len = 1 + ft_print_chars(prec - 1, ' ');
	}
	else
	{
		if (min_len > prec)
			len = 1 + ft_print_chars(min_len - 1, ' ');
		else
			len = 1 + ft_print_chars(prec - 1, ' ');
		ft_putchar('%');
	}
	return (args ? len : len);
}
