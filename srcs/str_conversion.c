/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_conversion.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarthon <lbarthon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 13:20:42 by lbarthon          #+#    #+#             */
/*   Updated: 2018/11/28 14:01:19 by lbarthon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"
#include <stdio.h>

int		ft_str_conv(const char *format, va_list *args)
{
	char	*str;
	int		len;

	str = va_arg(*args, char *);
	if (*format == '.')
		len = ft_atoi(format + 1);
	else
		len = ft_strlen_cst(str);
	ft_putnstr(str, len);
	return (len);
}
