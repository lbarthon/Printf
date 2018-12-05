/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_conversion.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarthon <lbarthon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 09:50:57 by lbarthon          #+#    #+#             */
/*   Updated: 2018/12/04 12:49:41 by lbarthon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"
#include <stdio.h>

static int	ft_suite(int min_len, int prec, int hex_len, char *hex)
{
	int len;

	len = ft_print_chars(min_len - prec, ' ');
	len += ft_print_chars(prec - hex_len, '0');
	if (*hex != '0' || prec != 0)
		ft_putnstr(hex, prec);
	else if (prec == 0)
		return (len - 1);
	else
		ft_putchar(' ');
	return (len);
}

static int	ft_has_moins(const char *format, char **hex, int prec, int min_len)
{
	int len;

	len = ft_strlen(*hex);
	if (ft_has_char(format, '#'))
	{
		ft_putnstr("0x", 2);
		len += 2 + ft_print_chars(prec - ft_strlen(*hex), '0');
	}
	else
		len += ft_print_chars(prec - ft_strlen(*hex), '0');
	ft_putnstr(*hex, ft_strlen(*hex));
	len += ft_print_chars(min_len - len, ' ');
	return (len);
}

static char	*ft_get_good_arg(const char *format, va_list *args)
{
	if (ft_contains(format, "hh"))
		return (ft_lltohex((unsigned char)va_arg(*args, unsigned int), 0));
	if (ft_contains(format, "ll"))
		return (ft_lltohex(va_arg(*args, unsigned long long), 0));
	if (ft_has_char(format, 'h'))
		return (ft_lltohex((unsigned short)va_arg(*args, unsigned int), 0));
	if (ft_has_char(format, 'l'))
		return (ft_lltohex((unsigned long)va_arg(*args, unsigned long), 0));
	return (ft_lltohex((unsigned int)va_arg(*args, unsigned int), 0));
}

static int	ft_get_custom_precision(const char *format, int min_len, char *hex)
{
	int prec;

	prec = ft_get_precision(format);
	if (ft_has_zero(format) && min_len > prec && !ft_has_char(format, '-'))
		return (ft_has_char(format, '#') ? min_len - 2 : min_len);
	if (prec < ft_strlen(hex) && prec != 0)
		return (ft_strlen(hex));
	return (prec);
}

int			ft_hex_conv(const char *format, va_list *args)
{
	char	*hex;
	int		len;
	int		min_len;
	int		prec;

	if (!(hex = ft_get_good_arg(format, args)))
		return (0);
	min_len = ft_get_min_length(format);
	prec = ft_get_custom_precision(format, min_len, hex);
	if (ft_has_char(format, '-'))
		return (ft_has_moins(format, &hex, prec, min_len));
	len = 0;
	if (ft_has_char(format, '#') && *hex != '0' && prec != 0)
	{
		len += ft_print_chars(min_len - prec - 2, ' ');
		ft_putnstr("0x", 2);
		len += 2 + ft_print_chars(prec - ft_strlen(hex), '0');
		ft_putnstr(hex, prec);
	}
	else
		len += ft_suite(min_len, prec, ft_strlen(hex), hex);
	len += ft_strlen(hex);
	free(hex);
	return (len);
}
