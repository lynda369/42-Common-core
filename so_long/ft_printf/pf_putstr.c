/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lybey <lybey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 01:10:17 by lybey             #+#    #+#             */
/*   Updated: 2023/11/10 23:10:11 by lybey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	pf_putstr(char *str, int *len)
{
	int	i;

	i = 0;
	if (!str)
	{
		pf_putstr("(null)", len);
		return ;
	}
	while (str[i] != '\0')
	{
		pf_putchar(str[i], len);
		i++;
	}
}
