/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_conversion.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarthon <lbarthon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 14:58:02 by lbarthon          #+#    #+#             */
/*   Updated: 2018/12/05 10:38:45 by lbarthon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"

static int	ft_short_short_conv(const char *format, va_list *args)
{
	char nbr;

	if (!ft_contains(format, "hh"))
		return (0);
	nbr = va_arg(*args, int);
	return (ft_putnbr_flags(format, nbr, ft_get_min_length(format)));
}

static int	ft_short_conv(const char *format, va_list *args)
{
	short nbr;

	if (!ft_contains(format, "h"))
		return (0);
	nbr = va_arg(*args, int);
	return (ft_putnbr_flags(format, nbr, ft_get_min_length(format)));
}

static int	ft_long_conv(const char *format, va_list *args)
{
	long nbr;

	if (!ft_contains(format, "l"))
		return (0);
	nbr = va_arg(*args, long);
	return (ft_putnbr_flags(format, nbr, ft_get_min_length(format)));
}

static int	ft_long_long_conv(const char *format, va_list *args)
{
	long long nbr;

	if (!ft_contains(format, "ll"))
		return (0);
	nbr = va_arg(*args, long long);
	return (ft_putnbr_flags(format, nbr, ft_get_min_length(format)));
}

int			ft_int_conv(const char *format, va_list *args)
{
	int nbr;
	int len;

	if ((len = ft_long_long_conv(format, args)))
		return (len);
	if ((len = ft_long_conv(format, args)))
		return (len);
	if ((len = ft_short_short_conv(format, args)))
		return (len);
	if ((len = ft_short_conv(format, args)))
		return (len);
	nbr = va_arg(*args, int);
	return (ft_putnbr_flags(format, nbr, ft_get_min_length(format)));
}
