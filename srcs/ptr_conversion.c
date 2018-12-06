/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ptr_conversion.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarthon <lbarthon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 08:24:41 by lbarthon          #+#    #+#             */
/*   Updated: 2018/12/05 11:28:35 by lbarthon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"

int		ft_ptr_conv(const char *format, va_list *args)
{
	char	*hex;
	int		len;
	int		min_len;
	int		spaces;
	int		prec;

	hex = ft_lltohex((long long)va_arg(*args, void *), 1);
	if (!hex)
		return (0);
	min_len = ft_get_min_length(format);
	prec = ft_get_precision(format);
	len = ft_strlen(hex);
	if (!ft_has_char(format, '-'))
		spaces = ft_print_chars(min_len - len, ' ');
	if (!(*(hex + 1) == 'x' && *(hex + 2) == '0' && prec == 0))
		ft_putnstr(hex, len);
	else
		ft_putnstr(hex, --len);
	free(hex);
	if (ft_has_char(format, '-'))
		spaces = ft_print_chars(min_len - len, ' ');
	return (len + spaces);
}
