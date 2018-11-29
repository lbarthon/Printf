/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_contains.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarthon <lbarthon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 11:49:54 by lbarthon          #+#    #+#             */
/*   Updated: 2018/11/29 13:32:04 by lbarthon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_contains(const char *str, const char *to_find)
{
	int i;

	i = 0;
	if (str && to_find)
	{
		while (str[i] && to_find[i])
		{
			if (str[i] != to_find[i])
				return (0);
			i++;
		}
		if (!to_find[i])
			return (1);
	}
	return (0);
}
