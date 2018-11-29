/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_conversion.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarthon <lbarthon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 15:15:17 by lbarthon          #+#    #+#             */
/*   Updated: 2018/11/29 11:58:19 by lbarthon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"

int		ft_char_conv(const char *format, va_list *args)
{
	unsigned char	c;

	c = va_arg(*args, int);
	write(1, &c, 1);
	return (!format ? 0 : 1);
}
