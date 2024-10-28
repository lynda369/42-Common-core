/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lybey <lybey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 18:54:11 by lybey             #+#    #+#             */
/*   Updated: 2023/05/31 19:06:17 by lybey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t element_size)
{
	void	*cal;

	if (nmemb != 0 && ((nmemb * element_size) / nmemb != element_size))
		return (NULL);
	cal = malloc(nmemb * element_size);
	if (!cal)
		return (NULL);
	ft_memset(cal, 0, nmemb * element_size);
	return (cal);
}
