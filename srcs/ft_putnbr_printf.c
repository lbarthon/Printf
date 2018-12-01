/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarthon <lbarthon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 12:10:34 by lbarthon          #+#    #+#             */
/*   Updated: 2018/12/01 07:24:51 by lbarthon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"

static int	ft_putnbr_printf(long long nb)
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

static int	ft_print_two(long long nb, int sign, int prec, int min_len)
{
	int len;

	len = 0;
	if (sign / 100 == 1 && prec == 1)
	{
		prec = min_len;
		min_len = 0;
	}
	while (--min_len > prec)
	{
		ft_putchar(' ');
		len++;
	}
	if (sign == 2 && nb >= 0 && ++len)
		ft_putchar(' ');
	else if (sign == 1 && nb >= 0 && ++len)
		ft_putchar('+');
	else if (nb < 0)
		ft_putchar('-');
	while (prec-- > (nb < 0 ? ft_nbrlength(nb) - 1 : ft_nbrlength(nb)))
	{
		ft_putchar('0');
		len++;
	}
	return (len + ft_putnbr_printf(nb));
}

static int	ft_print(long long nb, int sign, int prec, int min_len)
{
	int len;

	len = 0;
	if (sign / 10 == 1)
	{
		if (sign % 10 == 2 && nb >= 0 && ++len)
			ft_putchar(' ');
		else if (sign % 10 == 1 && nb >= 0 && ++len)
			ft_putchar('+');
		else if (nb < 0)
			ft_putchar('-');
		while (prec-- > (nb < 0 ? ft_nbrlength(nb) - 1 : ft_nbrlength(nb)))
		{
			ft_putchar('0');
			len++;
		}
		len += ft_putnbr_printf(nb);
		while (len < min_len)
		{
			ft_putchar(' ');
			len++;
		}
		return (len);
	}
	return (ft_print_two(nb, sign, prec, min_len));
}

int			ft_putnbr_flags(const char *format, long long nb, int min_len)
{
	int sign;

	sign = 0;
	if (ft_has_char(format, ' '))
		sign = 2;
	if (ft_has_char(format, '+'))
		sign = 1;
	if (ft_has_char(format, '-'))
		sign += 10;
	if (ft_has_char(format, '0') && sign < 10)
		sign += 100;
	return (ft_print(nb, sign, ft_get_precision(format), min_len));
}
