/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_conversion.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarthon <lbarthon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 13:20:42 by lbarthon          #+#    #+#             */
/*   Updated: 2018/12/04 13:45:26 by lbarthon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"

int		ft_str_conv(const char *format, va_list *args)
{
	char	*str;
	int		len;
	int		spaces;
	int		min_len;

	if (!(str = va_arg(*args, char *)))
	{
		ft_putnstr("(null)", 6);
		return (6);
	}
	len = ft_get_precision(format);
	min_len = ft_get_min_length(format);
	if (len == 0 || len > ft_strlen_cst(str))
		len = ft_strlen_cst(str);
	if (ft_has_char(format, '-'))
	{
		ft_putnstr(str, len);
		spaces = ft_print_chars(min_len - len, ' ');
		return (len + spaces);
	}
	spaces = ft_print_chars(min_len - len, ' ');
	ft_putnstr(str, len);
	return (len + spaces);
}
