/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lybey <lybey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 22:42:21 by lybey             #+#    #+#             */
/*   Updated: 2023/05/23 18:03:51 by lybey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *destina, const void *source, size_t n)
{
	unsigned char		*dest;
	const unsigned char	*src;
	size_t				i;

	if (destina == NULL && source == NULL)
		return (0);
	i = 0;
	dest = (unsigned char *)destina;
	src = (const unsigned char *)source;
	if (src < dest)
	{
		while (n--)
		{
			dest[n] = src[n];
		}
	}
	else
	{
		while (n > i)
		{
			dest[i] = src[i];
			i++;
		}
	}
	return (dest);
}
