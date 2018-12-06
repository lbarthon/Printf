/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   octal_conversion.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarthon <lbarthon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 09:46:46 by lbarthon          #+#    #+#             */
/*   Updated: 2018/12/06 14:56:28 by lbarthon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"

static char	*ft_get_good_arg(const char *format, va_list *args)
{
	if (ft_contains(format, "hh"))
		return (ft_lltooctal((unsigned char)va_arg(*args, unsigned int)));
	if (ft_contains(format, "ll"))
		return (ft_lltooctal(va_arg(*args, unsigned long long)));
	if (ft_has_char(format, 'h'))
		return (ft_lltooctal((unsigned short)va_arg(*args, unsigned int)));
	if (ft_has_char(format, 'l'))
		return (ft_lltooctal((unsigned long)va_arg(*args, unsigned long)));
	return (ft_lltooctal((unsigned int)va_arg(*args, unsigned int)));
}

static int	ft_get_custom_precision(const char *format, int min_len, char *oct)
{
	int prec;

	prec = ft_get_precision(format);
	if (ft_has_zero(format) && min_len > prec && !ft_has_char(format, '-'))
		return (min_len);
	else if (prec < ft_strlen(oct) && prec)
		return ((ft_has_char(format, '#') && ft_atoi(oct)) ?
				ft_strlen(oct) + 1 : ft_strlen(oct));
	else if (!prec && !ft_atoi(oct) && ft_has_char(format, '#'))
		return (prec + 1);
	return (ft_has_char(format, '#') && ft_atoi(oct) && prec <= ft_strlen(oct) ?
			prec + 1 : prec);
}

int			ft_octal_conv(const char *format, va_list *args)
{
	char	*octal;
	int		len;
	int		min_len;
	int		prec;

	if (!(octal = ft_get_good_arg(format, args)))
		return (0);
	min_len = ft_get_min_length(format);
	prec = ft_get_custom_precision(format, min_len, octal);
	if (ft_has_char(format, '-'))
	{
		len = ft_print_chars(prec - ft_strlen(octal), '0');
		if (prec != 0)
			ft_putnstr(octal, ft_strlen(octal));
		len += ft_print_chars(min_len - prec, ' ');
	}
	else
	{
		len = ft_print_chars(min_len - prec, ' ');
		len += ft_print_chars(prec - ft_strlen(octal), '0');
		if (prec != 0)
			ft_putnstr(octal, ft_strlen(octal));
	}
	free(octal);
	return (prec == 0 ? len : len + ft_strlen(octal));
}
