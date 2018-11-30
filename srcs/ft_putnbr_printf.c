/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarthon <lbarthon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 12:10:34 by lbarthon          #+#    #+#             */
/*   Updated: 2018/11/30 12:59:58 by lbarthon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"

int			ft_putnbr_printf(long long nb)
{
	unsigned long long	nbr;

	if (nb < 0)
		nbr = -nb;
	else
		nbr = nb;
	if (nbr >= 10L)
		ft_putnbr_printf(nbr / 10L);
	ft_putchar((nbr % 10) + 48);
	return (ft_nbrlength(nb));
}
