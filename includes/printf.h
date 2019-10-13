/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarthon <lbarthon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 13:45:17 by lbarthon          #+#    #+#             */
/*   Updated: 2019/10/13 15:01:26 by lbarthon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include "libft.h"
# include <stdarg.h>

typedef struct s_pfmodule	t_pfmodule;

typedef struct	s_printf {
	const char	*format;
	size_t		index;
	char		buffer[2048];
	short		buff_len;
	size_t		total_len;
	int			fd;
	t_pfmodule	*modules[16];
}				t_printf;

struct			s_pfmodule {
	int		(*exec)(t_printf *);
	char	c;
};

/*
** Includes for file ft_printf.c
*/

int				ft_printf(const char *restrict format, ...);

/*
** Includes for file buffer.c
*/

void			print_buffer(t_printf *data, char force);
void			buffer_add_str(t_printf *data, char *str, size_t end);
void			buffer_add_format(t_printf *data, size_t end);

/*
** Includes for file modules.c
*/

void			modules_handler(t_printf *data);

#endif
