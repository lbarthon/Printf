/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarthon <lbarthon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 10:45:28 by lbarthon          #+#    #+#             */
/*   Updated: 2019/10/13 11:35:29 by lbarthon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strmap(char const *s, char (*f)(char))
{
	int		size;
	int		i;
	char	*new;

	size = ft_strlen(s);
	if (!(new = (char*)malloc(size + 1)))
		return (NULL);
	i = -1;
	while (++i < size)
		if (s && f)
			new[i] = f(s[i]);
	new[i] = '\0';
	return (new);
}
