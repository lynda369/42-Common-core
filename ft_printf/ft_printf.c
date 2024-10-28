/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ntf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lybey <lybey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 23:02:04 by lybey             #+#    #+#             */
/*   Updated: 2023/07/26 16:44:15 by lybey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

void	ft_format(va_list args, const char *str, int *len)
{
	int	i;

	i = -1;
	while (str[++i] != '\0')
	{
		if (str[i] == '%')
		{
			if (str[++i] == 'c')
				ft_putchar(va_arg(args, int), len);
			else if (str[i] == 's')
				ft_putstr(va_arg(args, char *), len);
			else if (str[i] == 'x' || str[i] == 'X')
				ft_convert_base(va_arg(args, unsigned int), str[i], len);
			else if (str[i] == 'd' || str[i] == 'i')
				ft_putnbr(va_arg(args, int), len);
			else if (str[i] == 'p')
				ft_convert_base(va_arg(args, unsigned long), str[i], len);
			else if (str[i] == 'u')
				ft_putnbr_pos(va_arg(args, unsigned int), len);
			else if (str[i] == '%')
				ft_putchar('%', len);
		}
		else
			ft_putchar(str[i], len);
	}
}

int	ft_printf(const char *str, ...)
{
	int		len;
	va_list	args;

	len = 0;
	va_start(args, str);
	if (!str)
		return (-1);
	ft_format(args, str, &len);
	va_end(args);
	return (len);
}
