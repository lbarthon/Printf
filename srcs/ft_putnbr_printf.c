/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarthon <lbarthon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 12:10:34 by lbarthon          #+#    #+#             */
/*   Updated: 2018/11/29 13:10:26 by lbarthon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"

static void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void		ft_putnbr_printf(long long nb)
{
	unsigned long long nbr;

	if (nb < 0)
		nbr = -nb;
	else
		nbr = nb;
	if (nbr >= 10L)
		ft_putnbr_printf(nbr / 10L);
	ft_putchar((nbr % 10) + 48);
}
