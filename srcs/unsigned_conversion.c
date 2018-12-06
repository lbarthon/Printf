/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsigned_conversion.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarthon <lbarthon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 10:20:31 by lbarthon          #+#    #+#             */
/*   Updated: 2018/12/06 11:02:24 by lbarthon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"

static int					ft_ulen(unsigned long long nbr)
{
	int size;

	size = 1;
	while (nbr >= 10)
	{
		nbr /= 10;
		size++;
	}
	return (size);
}

static unsigned long long	ft_get_good_arg(const char *format, va_list *args)
{
	if (ft_contains(format, "ll"))
		return (va_arg(*args, unsigned long long));
	if (ft_has_char(format, 'l'))
		return ((unsigned long)va_arg(*args, unsigned long));
	if (ft_contains(format, "hh"))
		return ((unsigned char)va_arg(*args, unsigned int));
	if (ft_has_char(format, 'h'))
		return ((unsigned short)va_arg(*args, unsigned int));
	return ((unsigned int)va_arg(*args, unsigned int));
}

static int					ft_uprint(unsigned long long nbr, int prec)
{
	if (prec == 0)
		return (0);
	if (nbr >= 10)
		ft_uprint(nbr / 10, 1);
	ft_putchar((nbr % 10) + 48);
	return (ft_ulen(nbr));
}

int							ft_unsigned_conv(const char *format, va_list *args)
{
	unsigned long long	nbr;
	int					prec;
	int					min_len;
	int					len;

	nbr = ft_get_good_arg(format, args);
	prec = ft_get_precision(format);
	min_len = ft_get_min_length(format);
	if (ft_has_zero(format) && prec == 1 && !ft_has_char(format, '-'))
		prec = min_len;
	if (prec < ft_ulen(nbr) && prec != 0)
		prec = ft_ulen(nbr);
	if (!ft_has_char(format, '-'))
	{
		len = ft_print_chars(min_len - prec, ' ');
		len += ft_print_chars(prec - ft_ulen(nbr), '0');
		len += ft_uprint(nbr, prec);
	}
	else
	{
		len = ft_print_chars(prec - ft_ulen(nbr), '0');
		len += ft_uprint(nbr, prec);
		len += ft_print_chars(min_len - prec, ' ');
	}
	return (len);
}
