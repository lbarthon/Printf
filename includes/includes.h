/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   includes.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarthon <lbarthon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 09:11:12 by lbarthon          #+#    #+#             */
/*   Updated: 2018/11/30 12:58:50 by lbarthon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INCLUDES_H
# define INCLUDES_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include <string.h>

typedef struct		s_printf {

	char			*str;
	int				(*fct)(const char *, va_list *);
	struct s_printf	*next;

}					t_printf;

t_printf			*ft_struct(int i);

int					ft_get_precision(const char *format);
int					ft_has_char(const char *format, const char c);

/*
** Different conversions
*/

int					ft_str_conv(const char *format, va_list *args);
int					ft_int_conv(const char *format, va_list *args);
int					ft_char_conv(const char *format, va_list *args);

/*
** Lib functions
*/

int					ft_atoi(const char *str);
int					ft_nbrlength(long long n);
int					ft_print_till_next(const char *format);
int					ft_print_arg(const char *format, va_list *args);
int					ft_strlen(char *str);
int					ft_strclen(char *str, char c);
int					ft_strlen_cst(const char *str);
int					ft_strclen_cst(const char *str, char c);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
char				*ft_strdup(const char *str);

/*
** More functions
*/

int					ft_starts_with(const char *s1, char *s2);
int					ft_isprintf(int c);
int					ft_isflag(int c);
int					ft_contains(const char *str, const char *to_find);

/*
** Print functions
*/

void				ft_putnstr(const char *s, int n);
void				ft_putchar(char c);
int					ft_print_chars(int nbr_len, int c);
int					ft_putnbr_printf(long long nb);

#endif
