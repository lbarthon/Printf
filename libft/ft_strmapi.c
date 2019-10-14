/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarthon <lbarthon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 10:49:58 by lbarthon          #+#    #+#             */
/*   Updated: 2019/10/13 11:35:57 by lbarthon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	size;
	unsigned int	i;
	char			*new;

	size = ft_strlen(s);
	if (!(new = (char*)malloc(size + 1)))
		return (NULL);
	i = -1;
	while (++i < size)
		if (s && f)
			new[i] = f(i, s[i]);
	new[i] = '\0';
	return (new);
}
