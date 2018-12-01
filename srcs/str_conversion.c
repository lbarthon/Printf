/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_conversion.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarthon <lbarthon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 13:20:42 by lbarthon          #+#    #+#             */
/*   Updated: 2018/12/01 08:21:29 by lbarthon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"

int		ft_str_conv(const char *format, va_list *args)
{
	char	*str;
	int		len;
	int		spaces;
	int		min_len;

	str = va_arg(*args, char *);
	len = ft_get_precision(format);
	min_len = ft_get_min_length(format);
	spaces = 0;
	if (len == 0 || len > ft_strlen_cst(str))
		len = ft_strlen_cst(str);
	while (min_len-- > len)
	{
		ft_putchar(' ');
		spaces++;
	}
	ft_putnstr(str, len);
	return (len + spaces);
}
