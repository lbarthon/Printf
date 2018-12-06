/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_conversion.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarthon <lbarthon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 13:20:42 by lbarthon          #+#    #+#             */
/*   Updated: 2018/12/06 15:07:46 by lbarthon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"

int		ft_str_conv(const char *format, va_list *args)
{
	char	*str;
	int		len;
	int		spaces;
	int		min_len;

	len = ft_get_precision(format);
	min_len = ft_get_min_length(format);
	if (!(str = va_arg(*args, char *)))
	{
		str = "(null)";
		if (len == 0 && !ft_has_char(format, '.'))
			len = 6;
		len = len > 6 ? 6 : len;
	}
	else if ((len == 0 && !ft_has_char(format, '.')) ||
			len > ft_strlen_cst(str))
		len = ft_strlen_cst(str);
	if (!ft_has_char(format, '-'))
		spaces = ft_print_chars(min_len - len, ft_has_zero(format) ? '0' : ' ');
	ft_putnstr(str, len);
	if (ft_has_char(format, '-'))
		spaces = ft_print_chars(min_len - len, ft_has_zero(format) ? '0' : ' ');
	return (len + spaces);
}
