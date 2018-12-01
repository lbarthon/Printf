/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_maj_conversion.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarthon <lbarthon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 12:42:19 by lbarthon          #+#    #+#             */
/*   Updated: 2018/12/01 12:47:43 by lbarthon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"

static int	ft_suite(int min_len, int prec, int hex_len)
{
	int len;

	len = ft_print_chars(min_len - prec, ' ');
	len += ft_print_chars(prec - hex_len, '0');
	return (len);
}

static char	*ft_upcase(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 97 && str[i] <= 122)
			str[i] -= 32;
		i++;
	}
	return (str);
}

static int	ft_has_moins(const char *format, char **hex, int prec, int min_len)
{
	int len;

	len = ft_strlen(*hex);
	if (ft_has_char(format, '#'))
	{
		ft_putnstr("0X", 2);
		len += 2 + ft_print_chars(prec - ft_strlen(*hex), '0');
	}
	else
		len += ft_print_chars(prec - ft_strlen(*hex), '0');
	ft_putnstr(ft_upcase(*hex), ft_strlen(*hex));
	len += ft_print_chars(min_len - len, ' ');
	return (len);
}

int			ft_hex_maj_conv(const char *format, va_list *args)
{
	char	*hex;
	int		len;
	int		min_len;
	int		prec;

	if (!(hex = ft_lltohex((unsigned int)va_arg(*args, unsigned int), 0)))
		return (0);
	min_len = ft_get_min_length(format);
	prec = ft_get_precision(format);
	if (ft_has_char(format, '-'))
		return (ft_has_moins(format, &hex, prec, min_len));
	if (!(len = 0) && prec < ft_strlen(hex))
		prec = ft_strlen(hex);
	if (ft_has_char(format, '#'))
	{
		len += ft_print_chars(min_len - prec - 2, ' ');
		ft_putnstr("0X", 2);
		len += 2 + ft_print_chars(prec - ft_strlen(hex), '0');
	}
	else
		len += ft_suite(min_len, prec, ft_strlen(hex));
	len += ft_strlen(hex);
	ft_putnstr(ft_upcase(hex), ft_strlen(hex));
	free(hex);
	return (len);
}
