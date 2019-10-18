/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_internal.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarthon <lbarthon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 10:10:22 by lbarthon          #+#    #+#             */
/*   Updated: 2019/10/18 13:33:33 by lbarthon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_INTERNAL_H
# define PRINTF_INTERNAL_H

# include "libft.h"
# include <stdarg.h>

typedef struct s_printf	t_printf;

typedef struct	s_flags {
	size_t	minlen;
	char	dot : 1;
	char	space : 1;
	char	zero : 1;
}				t_flags;

typedef struct	s_pfmodule {
	void	(*exec)(t_printf *, t_flags *);
	char	c;
}				t_pfmodule;

struct			s_printf {
	const char	*format;
	size_t		index;
	va_list		*args;
	char		buffer[2048];
	char		*sprintf;
	short		buff_len;
	size_t		total_len;
	int			fd;
	t_pfmodule	modules[16];
	char		modules_len;
};

/*
** Includes for file routine.c
*/

int				printf_routine(t_printf *data);
void			init_printf(t_printf *data, const char *format, va_list *args);

/*
** Includes for file flags.c
*/

void			add_flags(t_printf *data, t_flags *flags, size_t end);

/*
** Includes for different modules
*/

void			string_handler(t_printf *data, t_flags *flags);
void			int_handler(t_printf *data, t_flags *flags);
void			pointer_handler(t_printf *data, t_flags *flags);
void			char_handler(t_printf *data, t_flags *flags);

/*
** Includes for file buffer.c
*/

void			print_buffer(t_printf *data, char force);
void			buffer_add_char(t_printf *data, char c);
void			buffer_add_str(t_printf *data, char *str, size_t end);
void			buffer_add_format(t_printf *data, size_t end);

/*
** Includes for file modules.c
*/

void			modules_handler(t_printf *data);
void			add_with_flags(t_printf *data, t_flags *flags, char *ret
		, char zero);

#endif
