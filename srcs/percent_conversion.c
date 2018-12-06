/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   percent_conversion.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarthon <lbarthon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 10:35:20 by lbarthon          #+#    #+#             */
/*   Updated: 2018/12/05 10:21:24 by lbarthon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"

int		ft_percent_conv(const char *format, va_list *args)
{
	int len;
	int min_len;

	min_len = ft_get_min_length(format) - 1;
	len = 1;
	if (ft_has_char(format, '-'))
		ft_putchar('%');
	if (min_len > 0 || ft_has_zero(format))
		len += ft_print_chars(min_len, (ft_has_zero(format) ? '0' : ' '));
	if (!ft_has_char(format, '-'))
		ft_putchar('%');
	return (args ? len : len);
}
