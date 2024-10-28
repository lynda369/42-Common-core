/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lybey <lybey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 23:04:11 by lybey             #+#    #+#             */
/*   Updated: 2023/11/10 23:12:42 by lybey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>

int		ft_printf(const char *str, ...);
void	ft_format(va_list args, const char *str, int *len);
void	pf_putchar(char c, int *len);
void	pf_putstr(char *str, int *len);
void	pf_putnbr(int nb, int *len);
void	ft_convert_base(unsigned long nb, char k, int *len);
void	pf_putnbr_pos(unsigned int nb, int *len);
// int		ft_check(const char *str);

#endif