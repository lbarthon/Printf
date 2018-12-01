/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_starts_with.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarthon <lbarthon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 13:03:09 by lbarthon          #+#    #+#             */
/*   Updated: 2018/12/01 08:09:20 by lbarthon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_starts_with(const char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1 && s2 && s1[i] && s2[i])
	{
		if (s2[i] != s1[i])
			return (0);
		i++;
	}
	if (!s1 || !s1[i])
		return (0);
	return (1);
}
