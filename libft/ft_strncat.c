/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarthon <lbarthon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 10:29:17 by lbarthon          #+#    #+#             */
/*   Updated: 2019/10/13 11:36:07 by lbarthon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strncat(char *dest, const char *src, size_t n)
{
	size_t i;
	size_t j;

	i = ft_strlen(dest);
	j = 0;
	while (src[j] != '\0' && j < n)
		dest[i++] = src[j++];
	dest[i] = '\0';
	return (dest);
}
