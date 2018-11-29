/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_conversion.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarthon <lbarthon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 13:20:42 by lbarthon          #+#    #+#             */
/*   Updated: 2018/11/29 11:37:54 by lbarthon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"

int		ft_str_conv(const char *format, va_list *args)
{
	char	*str;
	int		len;

	str = va_arg(*args, char *);
	len = ft_get_precision(format);
	if (len == 0 || len > ft_strlen_cst(str))
		len = ft_strlen_cst(str);
	ft_putnstr(str, len);
	return (len);
}
