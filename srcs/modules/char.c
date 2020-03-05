/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarthon <lbarthon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 11:36:32 by lbarthon          #+#    #+#             */
/*   Updated: 2019/11/27 12:39:04 by lbarthon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf_internal.h"

void	char_handler(t_printf *data, t_flags *flags)
{
	char	s[2];

	(void)flags;
	s[0] = va_arg(*data->args, int);
	s[1] = 0;
	add_with_flags(data, flags, s, flags->zero);
}
