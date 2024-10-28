/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lybey <lybey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 01:15:34 by lybey             #+#    #+#             */
/*   Updated: 2023/11/10 23:01:59 by lybey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_putnbr_base(unsigned long nbr, char *base, int *len)
{
	unsigned long	nb;

	nb = nbr;
	if (nb >= 16)
	{
		ft_putnbr_base(nb / 16, base, len);
		ft_putnbr_base(nb % 16, base, len);
	}
	if (nb < 16)
		ft_putchar(base[nb], len);
}

void	ft_convert_base(unsigned long nbr, char k, int *len)
{
	char			*base_maj;
	unsigned long	nb;
	char			*base_min;

	base_min = "0123456789abcdef";
	base_maj = "0123456789ABCDEF";
	nb = nbr;
	if (k == 'x')
		ft_putnbr_base(nb, base_min, len);
	else if (k == 'X')
		ft_putnbr_base(nb, base_maj, len);
	else if (k == 'p')
	{
		if (nb == 0)
		{
			ft_putstr("(nil)", len);
			return ;
		}
		else
		{
			ft_putstr("0x", len);
			ft_putnbr_base(nb, base_min, len);
		}
	}
}
