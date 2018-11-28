/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_module.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarthon <lbarthon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 12:59:22 by lbarthon          #+#    #+#             */
/*   Updated: 2018/11/28 13:53:15 by lbarthon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"
#include <stdio.h>

static const char	*ft_check_char(const char *format)
{
	int i;

	i = 1;
	if (!format[i])
		return (NULL);
	if (format[i] == '%' || ft_isalpha(format[i]))
		return (format + i);
	if (format[i] == '.')
	{
		while (ft_isdigit(format[i + 1]))
			i++;
		return (ft_check_char(format + i));
	}
	return (NULL);
}

int					ft_print_arg(const char *format, va_list *args)
{
	const char	*c;
	t_printf	*list;
	int			len;

	c = ft_check_char(format);
	list = ft_struct(1);
	len = 0;
	while (c && list)
	{
		if (ft_starts_with(c, list->str))
		{
			len = list->fct(c, args);
			break;
		}
		list = list->next;
	}
	return (!c ? 0 : len);
}
