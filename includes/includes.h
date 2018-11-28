/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   includes.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarthon <lbarthon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 09:11:12 by lbarthon          #+#    #+#             */
/*   Updated: 2018/11/28 09:46:59 by lbarthon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INCLUDES_H
# define INCLUDES_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include <string.h>

int		ft_print_till_next(const char *format);
void	ft_print_arg(const char *format, va_list *args);
int		ft_strlen(char *str, char c);
int		ft_strclen(char *str);
int		ft_strlen_cst(const char *str);
int		ft_strclen_cst(const char *str, char c);

#endif
