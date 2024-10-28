/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lybey <lybey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 21:02:15 by lybey             #+#    #+#             */
/*   Updated: 2023/11/10 23:10:25 by lybey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	pf_putnbr(int n, int *len)
{
	long long int	nb;

	nb = n;
	if (nb < 0)
	{
		pf_putchar('-', len);
		nb = -nb;
	}
	if (nb >= 10)
	{
		pf_putnbr(nb / 10, len);
	}
	pf_putchar(nb % 10 + '0', len);
}
