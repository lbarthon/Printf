/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarthon <lbarthon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 10:14:24 by lbarthon          #+#    #+#             */
/*   Updated: 2018/12/01 08:45:18 by lbarthon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"

int		ft_isprintf(int c)
{
	if (c == 'd' || c == 'i')
		return (1);
	if (c == 'c' || c == 's' || c == 'p')
		return (1);
	return (0);
}
