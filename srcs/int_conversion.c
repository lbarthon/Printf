/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_conversion.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarthon <lbarthon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 14:58:02 by lbarthon          #+#    #+#             */
/*   Updated: 2018/11/29 14:01:39 by lbarthon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"

static int	ft_is_short(const char *format, va_list *args)
{
	short	nbr;
	int		len;
	int		nbr_len;

	if (!ft_has_char(format, 'h'))
		return (0);
	nbr = va_arg(*args, int);
	len = ft_get_precision(format);
	nbr_len = ft_nbrlength(nbr);
	if (nbr < 0)
	{
		write(1, "-", 1);
		nbr_len--;
	}
	while (len > nbr_len++)
		write(1, "0", 1);
	ft_putnbr_printf(nbr);
	return (len != 0 ? len : ft_nbrlength(nbr));
}

static int	ft_is_short_short(const char *format, va_list *args)
{
	char	nbr;
	int		len;
	int		nbr_len;

	if (!ft_contains(format + 1, "hh"))
		return (0);
	nbr = va_arg(*args, int);
	len = ft_get_precision(format);
	nbr_len = ft_nbrlength(nbr);
	if (nbr < 0)
	{
		write(1, "-", 1);
		nbr_len--;
	}
	while (len > nbr_len++)
		write(1, "0", 1);
	ft_putnbr_printf(nbr);
	return (len != 0 ? len : ft_nbrlength(nbr));
}

static int	ft_is_long(const char *format, va_list *args)
{
	long	nbr;
	int		len;
	int		nbr_len;

	if (!ft_has_char(format, 'l'))
		return (0);
	nbr = va_arg(*args, long);
	len = ft_get_precision(format);
	nbr_len = ft_nbrlength(nbr);
	if (nbr < 0)
	{
		write(1, "-", 1);
		nbr_len--;
	}
	while (len > nbr_len++)
		write(1, "0", 1);
	ft_putnbr_printf(nbr);
	return (len != 0 ? len : ft_nbrlength(nbr));
}

static int	ft_is_long_long(const char *format, va_list *args)
{
	long long	nbr;
	int			len;
	int			nbr_len;

	if (!ft_contains(format + 1, "ll"))
		return (0);
	nbr = va_arg(*args, long long);
	len = ft_get_precision(format);
	nbr_len = ft_nbrlength(nbr);
	if (nbr < 0)
	{
		write(1, "-", 1);
		nbr_len--;
	}
	while (len > nbr_len++)
		write(1, "0", 1);
	ft_putnbr_printf(nbr);
	return (len != 0 ? len : ft_nbrlength(nbr));
}

int			ft_int_conv(const char *format, va_list *args)
{
	int nbr;
	int len;
	int nbr_len;

	if ((len = ft_is_short_short(format, args)))
		return (len);
	if ((len = ft_is_long_long(format, args)))
		return (len);
	if ((len = ft_is_short(format, args)))
		return (len);
	if ((len = ft_is_long(format, args)))
		return (len);
	nbr = va_arg(*args, int);
	len = ft_get_precision(format);
	nbr_len = ft_nbrlength(nbr);
	if (nbr < 0)
	{
		write(1, "-", 1);
		nbr_len--;
	}
	while (len > nbr_len++)
		write(1, "0", 1);
	ft_putnbr_printf(nbr);
	return (len != 0 ? len : ft_nbrlength(nbr));
}
