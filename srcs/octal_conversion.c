/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   octal_conversion.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarthon <lbarthon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 09:46:46 by lbarthon          #+#    #+#             */
/*   Updated: 2018/12/03 12:00:47 by lbarthon         ###   ########.fr       */
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

int			ft_octal_conv(const char *format, va_list *args)
{
	char	*octal;
	int		len;
	int		min_len;
	int		prec;

	if (!(octal = ft_get_good_arg(format, args)))
		return (0);
	min_len = ft_get_min_length(format);
	prec = ft_get_precision(format);
	if (ft_has_char(format, '#') && prec <= ft_strlen(octal))
		prec = ft_strlen(octal) + 1;
	if (prec < ft_strlen(octal))
		prec = ft_strlen(octal);
	if (ft_has_char(format, '-'))
	{
		len = ft_print_chars(prec - ft_strlen(octal), '0');
		ft_putnstr(octal, ft_strlen(octal));
		len += ft_print_chars(min_len - prec, ' ');
	}
	else
	{
		len = ft_print_chars(min_len - prec, ' ');
		len += ft_print_chars(prec - ft_strlen(octal), '0');
		ft_putnstr(octal, ft_strlen(octal));
	}
	free(octal);
	return (len + ft_strlen(octal));
}
