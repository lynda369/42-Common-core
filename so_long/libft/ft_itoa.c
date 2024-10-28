/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lybey <lybey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 18:04:07 by lybey             #+#    #+#             */
/*   Updated: 2023/06/20 19:27:02 by lybey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	len(int n)
{
	int	i;

	i = 0;
	if (n < 0)
		i++;
	if (!n)
		return (1);
	if (n == 1)
	{
		i++;
		return (i);
	}
	while (n)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char		*s;
	long int	nbr;
	int			i;

	nbr = n;
	if (!n)
		return (s = malloc(sizeof(char) * 2), s[0] = '0', s[1] = '\0', s);
	i = len(n);
	s = (char *)malloc(sizeof(char) * (i + 1));
	if (!s)
		return (NULL);
	s[i] = '\0';
	i--;
	if (n < 0)
	{
		nbr *= -1;
		s[0] = '-';
	}
	while (nbr > 0)
	{
		s[i] = (nbr % 10) + '0';
		nbr /= 10;
		i--;
	}
	return (s);
}
