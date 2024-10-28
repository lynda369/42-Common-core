/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stock_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lybey <lybey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 18:26:17 by lybey             #+#    #+#             */
/*   Updated: 2024/02/28 17:47:55 by lybey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	count_char_map(int fd)
{
	char	tmp[1024];
	int		len;
	size_t	bytes;

	len = 0;
	bytes = 0;
	if (fd == -1)
		return (0);
	while (1)
	{
		bytes = read(fd, tmp, 1024);
		if (bytes <= 0)
			break ;
		len += bytes;
	}
	return (len);
}

int	check_empty_lines(char *map_line)
{
	int	i;

	i = 0;
	while (map_line[i])
	{
		if (map_line[i] == '\n' && map_line[i + 1] == '\n')
		{
			ft_printf("Error\nEmpty line in map\n");
			return (0);
		}
		i++;
	}
	return (1);
}

int	stock_map(char *path, t_game *game)
{
	int		fd;
	int		nbchar;
	char	*map_line;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (ft_printf("Error\nFile does not exist\n"), 0);
	nbchar = count_char_map(fd);
	close (fd);
	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (0);
	map_line = ft_calloc(sizeof(char), nbchar + 1);
	if (!map_line)
		return (close(fd), 0);
	if (read(fd, map_line, nbchar) == -1)
		return (free(map_line), close(fd), 0);
	close(fd);
	if (!check_empty_lines(map_line))
		return (free(map_line), 0);
	game->map = ft_split(map_line, '\n');
	if (!game->map)
		return (free(map_line), 0);
	return (free(map_line), 1);
}
