/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lybey <lybey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 00:07:39 by lybey             #+#    #+#             */
/*   Updated: 2024/03/25 01:17:18 by lybey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack	*ft_lstlast(t_stack *lst)
{
	t_stack	*current;

	current = lst;
	if (!lst)
		return (0);
	while (current->next != NULL)
		current = current->next;
	return (current);
}
