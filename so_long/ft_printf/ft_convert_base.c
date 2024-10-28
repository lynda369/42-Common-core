/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lybey <lybey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 01:15:34 by lybey             #+#    #+#             */
/*   Updated: 2023/11/10 23:12:24 by lybey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	pf_putnbr_base(unsigned long nbr, char *base, int *len)
{
	unsigned long	nb;

	nb = nbr;
	if (nb >= 16)
	{
		pf_putnbr_base(nb / 16, base, len);
		pf_putnbr_base(nb % 16, base, len);
	}
	if (nb < 16)
		pf_putchar(base[nb], len);
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
		pf_putnbr_base(nb, base_min, len);
	else if (k == 'X')
		pf_putnbr_base(nb, base_maj, len);
	else if (k == 'p')
	{
		if (nb == 0)
		{
			pf_putstr("(nil)", len);
			return ;
		}
		else
		{
			pf_putstr("0x", len);
			pf_putnbr_base(nb, base_min, len);
		}
	}
}
