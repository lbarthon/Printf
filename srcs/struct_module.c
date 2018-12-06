/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_module.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarthon <lbarthon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 11:57:10 by lbarthon          #+#    #+#             */
/*   Updated: 2018/12/05 13:36:12 by lbarthon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"

static void	ft_add_new(t_printf **list, char *str,
		int (*fct)(const char *, va_list *))
{
	t_printf *new;

	if (!(new = (t_printf*)malloc(sizeof(t_printf))))
		return ;
	new->next = *list;
	new->str = ft_strdup(str);
	new->fct = fct;
	*list = new;
}

static void	ft_init(t_printf **list)
{
	*list = NULL;
	ft_add_new(list, "c", &ft_char_conv);
	ft_add_new(list, "s", &ft_str_conv);
	ft_add_new(list, "p", &ft_ptr_conv);
	ft_add_new(list, "d", &ft_int_conv);
	ft_add_new(list, "i", &ft_int_conv);
	ft_add_new(list, "o", &ft_octal_conv);
	ft_add_new(list, "u", &ft_unsigned_conv);
	ft_add_new(list, "x", &ft_hex_conv);
	ft_add_new(list, "X", &ft_hex_maj_conv);
	ft_add_new(list, "f", &ft_float_conv);
	ft_add_new(list, "%", &ft_percent_conv);
}

static void	ft_cyalist(t_printf **list)
{
	t_printf *tmp;

	while ((*list))
	{
		tmp = (*list)->next;
		free((*list)->str);
		free((*list));
		(*list) = tmp;
	}
}

t_printf	*ft_struct(int i)
{
	static t_printf	*list;

	if (i == 0)
		ft_init(&list);
	if (i == 0 || i == 1)
		return (list);
	if (i == 2)
		ft_cyalist(&list);
	return (NULL);
}
