/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ptr_conversion.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarthon <lbarthon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 08:24:41 by lbarthon          #+#    #+#             */
/*   Updated: 2018/12/01 08:56:15 by lbarthon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"

int		ft_ptr_conv(const char *format, va_list *args)
{
	char		*hex;
	int			len;
	int			min_len;
	int			spaces;

	hex = ft_lltohex((long long)va_arg(*args, void *));
	if (!hex)
		return (0);
	min_len = ft_get_min_length(format);
	len = ft_strlen(hex);
	spaces = 0;
	if (!ft_has_char(format, '-'))
		while (min_len-- > len)
		{
			ft_putchar(' ');
			spaces++;
		}
	ft_putnstr(hex, len);
	free(hex);
	if (ft_has_char(format, '-'))
		while (min_len-- > len)
		{
			ft_putchar(' ');
			spaces++;
		}
	return (len + spaces);
}
