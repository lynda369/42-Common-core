/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lybey <lybey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 01:55:38 by lybey             #+#    #+#             */
/*   Updated: 2023/11/10 18:36:33 by lybey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 7
# endif
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

void	add_end(char *str);
int		new_line(char *str);
void	trim_buffer(char *str);
char	*get_next_line(int fd);
size_t	ft_strlen_gnl(const char *str);
size_t	ft_strlcat_gnl(char *dst, const char *src, size_t size);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
char	*ft_strdup_gnl(const char *s);
char	*ft_strjoin_gnl(char *s1, char *s2);

#endif
