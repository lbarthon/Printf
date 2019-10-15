/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarthon <lbarthon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 11:36:32 by lbarthon          #+#    #+#             */
/*   Updated: 2019/10/15 11:57:30 by lbarthon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf_internal.h"

void	char_handler(t_printf *data, t_flags *flags)
{
	(void)flags;
	buffer_add_char(data, va_arg(*data->args, int));
}
