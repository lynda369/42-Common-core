/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lybey <lybey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 20:32:35 by lybey             #+#    #+#             */
/*   Updated: 2023/05/22 20:49:41 by lybey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*s1;
	const unsigned char	*s2;

	i = 0;
	s1 = (unsigned char *)dest;
	s2 = (const unsigned char *)src;
	if (s1 == NULL && s2 == NULL)
		return (s1);
	while (i < n)
	{
		s1[i] = s2[i];
		i++;
	}
	return (dest);
}

/*
int main ()
{
	char	str[];
	char	dst[];

	str[] = "Bonjour";
	dst[] = "";
	printf("DEST AVANT QUE JE FASSE APPEL A LA FONCTION MEMCPY""%s\n", dst);
	ft_memcpy(dst, str, 7);
	printf("%s\n", dst);
	return (0);
}
*/