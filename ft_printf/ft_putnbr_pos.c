/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_pos.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lybey <lybey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 21:48:20 by lybey             #+#    #+#             */
/*   Updated: 2023/07/27 16:14:49 by lybey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_pos(unsigned int nb, int *len)
{
	if (nb >= 10)
	{
		ft_putnbr_pos(nb / 10, len);
	}
	ft_putchar(nb % 10 + '0', len);
}
