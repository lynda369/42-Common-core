/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lybey <lybey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 23:19:59 by lybey             #+#    #+#             */
/*   Updated: 2024/04/17 21:05:19 by lybey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <fcntl.h>
# include <limits.h>
# include <signal.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

void	char_to_bin(int pid, char c);
void	ft_build_string(char c, siginfo_t *info);
int		ft_atoi(const char *str);
char	*ft_strjoin(char *s1, char const s2);
void	ft_putstr_fd(char *s, int fd);
size_t	ft_strlen(const char *s);
void	ft_putnbr(int n);

#endif