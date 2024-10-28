/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lybey <lybey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 19:02:48 by lybey             #+#    #+#             */
/*   Updated: 2023/05/23 19:46:15 by lybey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*ptr;

	i = 0;
	ptr = (char *)s;
	while (ptr[i])
		i++;
	while (i > 0)
	{
		if (ptr[i] == (char)c)
			return (&ptr[i]);
		i--;
	}
	if (ptr[i] == (char)c)
		return (&ptr[i]);
	return (NULL);
}
