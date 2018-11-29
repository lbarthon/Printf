/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_module.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarthon <lbarthon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 12:59:22 by lbarthon          #+#    #+#             */
/*   Updated: 2018/11/29 11:43:53 by lbarthon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"
#include <stdio.h>

int					ft_get_precision(const char *format)
{
	int i;

	i = 0;
	while (format && *(format + i) && !ft_isprintf(*(format + i)))
	{
		if (*(format + i) == '.')
			return (ft_atoi(format + i + 1));
		i++;
	}
	if (*(format + i) == 'f')
		return (6);
	if (*(format + i) == 's')
		return (0);
	return (1);
}

int					ft_has_char(const char *format, const char c)
{
	int i;

	i = 0;
	while (format &&  *(format + i) && !ft_isprintf(*(format + i)))
	{
		if (*(format + i) == c)
			return (1);
		i++;
	}
	return (0);
}

static const char	*ft_check_char(const char *format)
{
	int i;

	i = 1;
	if (!format[i])
		return (NULL);
	if (format[i] == '%')
		return (format + i);
	while (format[i] && !ft_isprintf(format[i]))
		i++;
	if (format[i] && ft_isprintf(format[i]))
		return (format + i);
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
			len = list->fct(format, args);
			break;
		}
		list = list->next;
	}
	return (!c ? 0 : len);
}
