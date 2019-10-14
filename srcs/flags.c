/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarthon <lbarthon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 09:22:51 by lbarthon          #+#    #+#             */
/*   Updated: 2019/10/14 11:50:16 by lbarthon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf_internal.h"

void	add_flags(t_printf *data, t_flags *flags, size_t end)
{
	size_t	i;

	i = data->index + 1;
	while (i <= end)
	{
		if (*(data->format + i) == '.')
			flags->dot = 0x1;
		else if (*(data->format + i) == ' ')
			flags->space = 0x1;
		else if (*(data->format + i) == '0')
			flags->zero = 0x1;
		else
		{
			flags->minlen = (size_t)ft_atoi(data->format + i);
			return ;
		}
		i++;
	}
	flags->minlen = 0;
}
