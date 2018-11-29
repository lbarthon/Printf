/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarthon <lbarthon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 09:59:47 by lbarthon          #+#    #+#             */
/*   Updated: 2018/11/29 10:02:41 by lbarthon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnstr(char *str, int n)
{
	if ((int)ft_strlen(str) < n)
		n = (int)ft_strlen(str);
	write(1, str, n);
}
