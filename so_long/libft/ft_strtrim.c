/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lybey <lybey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 11:35:57 by lybey             #+#    #+#             */
/*   Updated: 2023/06/13 14:24:59 by lybey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*new;
	size_t	start;
	size_t	end;

	start = 0;
	if (!s1)
		return (NULL);
	while (ft_strchr(set, s1[start]))
		start++;
	end = ft_strlen(s1);
	while (ft_strchr(set, s1[end]))
		end--;
	new = ft_substr(s1, start, end - start + 1);
	return (new);
}

// strlen len--
// chsrcher set i++
// chercher set len--
// malloc str new len -i
// new str commence a i jusqu a len
