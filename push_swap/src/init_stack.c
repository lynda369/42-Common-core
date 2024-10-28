/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lybey <lybey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 04:08:30 by lybey             #+#    #+#             */
/*   Updated: 2024/03/25 03:08:14 by lybey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	init_stack_a(char **av, t_stack **head)
{
	int	i;

	i = 1;
	while (av[i])
	{
		ft_lstadd_end((head), ft_lstnew(ft_atoi(av[i])));
		i++;
	}
}

void	print_stack(t_stack *stack, char c)
{
	t_stack	*current;

	ft_printf("\nPrinting Stack: %c\n\n", c);
	current = stack;
	while (current)
	{
		ft_printf("value : %d ", current->value);
		ft_printf("index : %d\n", current->index);
		current = current->next;
	}
}
