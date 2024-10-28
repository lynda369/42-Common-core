/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lybey <lybey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 02:50:45 by lybey             #+#    #+#             */
/*   Updated: 2024/03/25 02:50:48 by lybey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_lstclear(t_stack *lst)
{
	t_stack	*t;
	t_stack	*buf;

	if (!lst)
		return ;
	t = lst;
	while (t)
	{
		buf = t->next;
		free(t);
		t = buf;
	}
	lst = NULL;
}
