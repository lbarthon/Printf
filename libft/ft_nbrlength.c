/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrlength.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarthon <lbarthon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 13:02:27 by lbarthon          #+#    #+#             */
/*   Updated: 2018/11/30 07:33:37 by lbarthon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int		ft_nbrlength(long long n)
{
	int					size;
	unsigned long long	nb;

	size = 1;
	if (n < 0)
	{
		size++;
		nb = -n;
	}
	else
		nb = n;
	while (nb >= 10L)
	{
		size++;
		nb /= 10L;
	}
	return (size);
}
