/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_conversion.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarthon <lbarthon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 14:58:02 by lbarthon          #+#    #+#             */
/*   Updated: 2018/11/30 13:54:07 by lbarthon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"

int			ft_print_chars(int nbr_len, int c)
{
	int n;

	n = 0;
	while (n < nbr_len)
	{
		ft_putchar(c);
		n++;
	}
	return (nbr_len);
}

int			ft_int_conv(const char *format, va_list *args)
{
	int nbr;

	nbr = va_arg(*args, int);
	format = NULL;
	return (0);
}
