/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lybey <lybey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 16:40:43 by lybey             #+#    #+#             */
/*   Updated: 2023/05/23 19:49:44 by lybey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*ptr;
	int		i;

	ptr = (char *)s;
	i = 0;
	while (s[i])
	{
		if (ptr[i] == (char)c)
			return (&ptr[i]);
		i++;
	}
	if (ptr[i] == (char)c)
		return (&ptr[i]);
	return (NULL);
}
