/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lybey <lybey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 01:56:06 by lybey             #+#    #+#             */
/*   Updated: 2023/11/10 22:57:31 by lybey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen_gnl(const char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		i++;
	}
	return (i);
}

size_t	ft_strlcat_gnl(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	d_len;
	size_t	s_len;

	s_len = ft_strlen_gnl((char *)src);
	if (!size)
		return (s_len);
	d_len = ft_strlen_gnl(dst);
	i = 0;
	if (d_len < size - 1 && size > 0)
	{
		while (src[i] && d_len + i < size - 1)
		{
			dst[d_len + i] = src[i];
			i++;
		}
		dst[d_len + i] = 0;
	}
	if (d_len >= size)
		d_len = size;
	return (d_len + s_len);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size - 1 && size != 0 && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	if (size != 0)
		dst[i] = '\0';
	while (src[i])
		i++;
	return (i);
}

char	*ft_strdup_gnl(const char *s)
{
	char	*new;

	new = malloc(sizeof(char) * (ft_strlen_gnl((char *)s) + 1));
	if (!new)
		return (NULL);
	ft_strlcpy(new, s, ft_strlen((char *)s) + 1);
	return (new);
}

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	char	*new;
	int		len;

	if (!s1 && s2)
		return (ft_strdup_gnl(s2));
	len = ft_strlen_gnl(s1) + ft_strlen_gnl(s2);
	new = malloc(sizeof(char) * (len + 1));
	if (!new)
		return (NULL);
	ft_strlcpy(new, (char *)s1, ft_strlen_gnl(s1) + 1);
	ft_strlcat_gnl(new, (char *)s2, len + 1);
	free(s1);
	return (new);
}
