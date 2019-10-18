/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarthon <lbarthon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 13:45:17 by lbarthon          #+#    #+#             */
/*   Updated: 2019/10/18 12:31:03 by lbarthon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include <stdarg.h>

int		ft_printf(const char *restrict format, ...);
int		ft_dprintf(int fd, const char *restrict format, ...);
int		ft_sprintf(char *buff, const char *restrict format, ...);

#endif
