/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarthon <lbarthon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 10:52:30 by lbarthon          #+#    #+#             */
/*   Updated: 2019/10/14 10:53:09 by lbarthon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_fill(char *str, int len, char c)
{
	int	i;

	i = 0;
	while (i < len)
		str[i++] = c;
}
