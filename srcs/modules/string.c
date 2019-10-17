/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarthon <lbarthon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 09:52:43 by lbarthon          #+#    #+#             */
/*   Updated: 2019/10/17 18:46:14 by lbarthon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf_internal.h"
#include <stdio.h>

void	string_handler(t_printf *data, t_flags *flags)
{
	char	*str;
	size_t	len;

	if (!(str = va_arg(*data->args, char *)))
		str = "(null)";
	len = ft_strlen(str);
	add_with_flags(data, flags, str, flags->zero);
}
