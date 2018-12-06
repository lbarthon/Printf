/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_module.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarthon <lbarthon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 12:59:22 by lbarthon          #+#    #+#             */
/*   Updated: 2018/12/05 11:20:21 by lbarthon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"

int					ft_get_precision(const char *format)
{
	int i;

	i = 0;
	while (format[i] && (ft_isdigit(format[i]) || ft_isflag(format[i]) ||
				format[i] == '.'))
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

int					ft_get_min_length(const char *format)
{
	int i;

	i = 0;
	while (format[i] && (ft_isdigit(format[i]) || ft_isflag(format[i]) ||
				format[i] == '.'))
	{
		if (*(format + i) == '0')
			i++;
		if (*(format + i) == '.')
			break ;
		if (!ft_isflag(*(format + i)) && *(format + i) != '%')
			return (ft_atoi(format + i));
		i++;
	}
	return (0);
}

int					ft_has_zero(const char *format)
{
	while (format && *format)
	{
		if ((*format) == '0')
			return (1);
		if (ft_isdigit(*format) || ft_isprintf(*format))
			return (0);
		format++;
	}
	return (0);
}

static const char	*ft_check_char(const char *format)
{
	int i;

	i = 1;
	if (!format[i])
		return (NULL);
	while (format[i] && (ft_isdigit(format[i]) || ft_isflag(format[i]) ||
				format[i] == '.'))
		i++;
	return (format + i);
}

int					ft_print_arg(const char *format, va_list *args)
{
	const char	*c;
	t_printf	*list;
	int			i;

	c = ft_check_char(format);
	list = ft_struct(1);
	i = 1;
	while (c && list)
	{
		if (ft_starts_with(c, list->str))
			return (list->fct(format + 1, args));
		list = list->next;
	}
	if (!c)
		return (0);
	if (!ft_has_char(format + 1, '-'))
		i += ft_print_chars(ft_get_min_length(format + 1) - 1,
				ft_has_zero(format + 1) ? '0' : ' ');
	ft_putchar(*c);
	if (ft_has_char(format + 1, '-'))
		i += ft_print_chars(ft_get_min_length(format + 1) - 1,
				ft_has_zero(format + 1) ? '0' : ' ');
	return (i);
}
