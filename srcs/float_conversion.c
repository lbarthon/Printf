/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float_conversion.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarthon <lbarthon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 13:35:20 by lbarthon          #+#    #+#             */
/*   Updated: 2018/12/06 11:51:40 by lbarthon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"

int			ft_float_conv(const char *format, va_list *args)
{
	char	*nbr;
	int		prec;
	int		min_len;
	int		len;

	prec = ft_get_precision(format);
	min_len = ft_get_min_length(format);
	if (!(len = 0) && ft_has_char(format, 'L'))
		nbr = ft_ldtoa(va_arg(*args, long double), prec);
	else
		nbr = ft_ldtoa((double)va_arg(*args, double), prec);
	if (!ft_has_char(format, '-'))
		len += ft_print_chars(min_len - ft_strlen(nbr) - 1,
				ft_has_zero(format) ? '0' : ' ');
	if (ft_has_char(format, '+') && ++len)
		ft_putchar('+');
	else if ((ft_has_char(format, ' ') || len) && ++len)
		ft_putchar(' ');
	ft_putnstr(nbr, ft_strlen(nbr));
	if (ft_has_char(format, '-'))
		len += ft_print_chars(min_len - ft_strlen(nbr)
				- (ft_has_char(format, ' ') || ft_has_char(format, '+')), ' ');
	len += ft_strlen(nbr);
	free(nbr);
	return (len);
}
