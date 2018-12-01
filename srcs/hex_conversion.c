/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_conversion.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarthon <lbarthon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 09:50:57 by lbarthon          #+#    #+#             */
/*   Updated: 2018/12/01 12:00:17 by lbarthon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"

static int	ft_suite(int min_len, int prec, int hex_len)
{
	int len;

	len = ft_print_chars(min_len - prec, ' ');
	len += ft_print_chars(prec - hex_len, '0');
	return (len);
}

int			ft_hex_conv(const char *format, va_list *args)
{
	char	*hex;
	int		len;
	int		min_len;
	int		prec;

	if (!(hex = ft_lltohex((unsigned int)va_arg(*args, unsigned int), 0)))
		return (0);
	min_len = ft_get_min_length(format);
	prec = ft_get_precision(format);
	//if (ft_has_char(format, '-'))
	//	return (ft_has_moins(&hex, prec, min_len));
	if (!(len = 0) && prec < ft_strlen(hex))
		prec = ft_strlen(hex);
	if (ft_has_char(format, '#'))
	{
		len += ft_print_chars(min_len - prec - 2, ' ');
		ft_putnstr("0x", 2);
		len += 2 + ft_print_chars(prec - ft_strlen(hex), '0');
	}
	else
		len += ft_suite(min_len, prec, ft_strlen(hex));
	len += ft_strlen(hex);
	ft_putnstr(hex, ft_strlen(hex));
	free(hex);
	return (len);
}
