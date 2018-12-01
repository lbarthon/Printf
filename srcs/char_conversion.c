/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_conversion.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarthon <lbarthon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 15:15:17 by lbarthon          #+#    #+#             */
/*   Updated: 2018/12/01 12:03:29 by lbarthon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"

int		ft_char_conv(const char *format, va_list *args)
{
	unsigned char	c;
	int				min_len;
	int				len;

	c = va_arg(*args, int);
	min_len = ft_get_min_length(format) - 1;
	len = ft_print_chars(min_len, ' ');
	if (c)
		ft_putchar(c);
	else
		ft_putchar(' ');
	return (len + 1);
}
