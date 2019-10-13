/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modules.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarthon <lbarthon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 13:41:13 by lbarthon          #+#    #+#             */
/*   Updated: 2019/10/13 15:01:25 by lbarthon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h" 

void	modules_handler(t_printf *data)
{
	char	m;
	int		i;
	int		j;

	i = 0;
	while ((m = *(data->format + data->index + i)))
	{
		j = -1;
		while (++j < data->modules_len)
			if (data->modules[j].c == m)
			{
				data->modules[j].exec(data);
				data->index += i + 1;
				return ;
			}
		i++;
	}
	buffer_add_format(data, i);
}
