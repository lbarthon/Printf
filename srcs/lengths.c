/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strclen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarthon <lbarthon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 09:35:36 by lbarthon          #+#    #+#             */
/*   Updated: 2018/11/28 09:35:37 by lbarthon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strlen_cst(const char *str)
{
	int i;

	i = 0;
	if (str)
		while (str[i])
			i++;
	return (i);
}

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	if (str)
		while (str[i])
			i++;
	return (i);
}

int		ft_strclen(char *str, char c)
{
	int i;

	i = 0;
	if (str)
		while (str[i] > 0 && str[i] != c)
			i++;
	return (i);
}

int		ft_strclen_cst(const char *str, char c)
{
	int i;

	i = 0;
	if (str)
		while (str[i] > 0 && str[i] != c)
			i++;
	return (i);
}
