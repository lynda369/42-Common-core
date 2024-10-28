/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lybey <lybey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 01:54:27 by lybey             #+#    #+#             */
/*   Updated: 2023/11/10 22:57:46 by lybey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	add_end(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\n' && str[i] != '\0')
	{
		i++;
	}
	if (str[i] == '\n')
		str[i + 1] = '\0';
}

int	new_line(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

void	trim_buffer(char *str)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	j = 0;
	while (str[i] != '\n')
		i++;
	i++;
	while (str[i] != '\0')
	{
		tmp = str[i];
		str[j] = tmp;
		i++;
		j++;
	}
	str[j] = '\0';
}

char	*get_next_line(int fd)
{
	static char	buf[BUFFER_SIZE + 1];
	char		*line;
	int			nb_bytes;

	nb_bytes = 1;
	if (fd < 0 || read(fd, buf, 0))
		return (NULL);
	line = ft_strjoin_gnl(NULL, buf);
	if (!line)
		return (NULL);
	while (!new_line(line) && nb_bytes)
	{
		nb_bytes = read(fd, buf, BUFFER_SIZE);
		buf[nb_bytes] = '\0';
		line = ft_strjoin_gnl(line, buf);
		if (!line)
			return (NULL);
	}
	if (line[0] == '\0' && nb_bytes == 0)
		return (free(line), NULL);
	add_end(line);
	if (nb_bytes)
		trim_buffer(buf);
	return (line);
}
