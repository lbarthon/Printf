/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarthon <lbarthon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 12:10:34 by lbarthon          #+#    #+#             */
/*   Updated: 2018/12/05 09:04:48 by lbarthon         ###   ########.fr       */
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
		prec = min_len;
	if (prec < ft_nbrlength(nb))
		len += ft_print_chars(min_len - ft_nbrlength(nb) -
				(sign % 10 && nb >= 0), ' ');
	else
		len += ft_print_chars(min_len - prec -
				((sign % 10 && nb >= 0) || nb < 0), ' ');
	if (sign % 10 == 2 && nb >= 0 && ++len)
		ft_putchar(' ');
	else if (sign % 10 == 1 && nb >= 0 && ++len)
		ft_putchar('+');
	else if (nb < 0)
		ft_putchar('-');
	if (prec > 0 && min_len >= prec)
		len += ft_print_chars(min_len - ft_nbrlength(nb) - len, 48);
	else if (prec > 0)
		len += ft_print_chars(prec - ft_nbrlength(nb) + (nb < 0), 48);
	len += ft_putnbr_printf(nb);
	return (len);
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
		len += ft_print_chars(prec - ft_nbrlength(nb) - (nb < 0 ? -1 : 0), '0');
		len += ft_putnbr_printf(nb);
		len += ft_print_chars(min_len - len, ' ');
		return (len);
	}
	return (ft_print_two(nb, sign, prec, min_len));
}

int			ft_putnbr_flags(const char *format, long long nb, int min_len)
{
	int sign;
	int prec;

	sign = 0;
	prec = ft_get_precision(format);
	if (ft_has_char(format, ' '))
		sign = 2;
	if (ft_has_char(format, '+'))
		sign = 1;
	if (ft_has_char(format, '-'))
		sign += 10;
	if (ft_has_zero(format) && sign < 10)
		sign += 100;
	if (prec == 0 && nb == 0)
		return (ft_print_chars(min_len, ' '));
	return (ft_print(nb, sign, prec, min_len));
}
