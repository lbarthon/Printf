/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_module.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarthon <lbarthon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 09:31:27 by lbarthon          #+#    #+#             */
/*   Updated: 2018/12/01 09:08:03 by lbarthon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"

int		ft_print_till_next(const char *format)
{
	int len;

	len = ft_strclen_cst(format, '%');
	ft_putnstr(format, len);
	return (len);
}
