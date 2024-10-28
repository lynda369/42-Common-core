/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lybey <lybey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 04:20:43 by lybey             #+#    #+#             */
/*   Updated: 2024/03/25 01:14:38 by lybey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack	*get_smallest(t_stack *stack)
{
	t_stack	*current;
	t_stack	*smallest;
	long	compare;

	compare = LONG_MAX;
	current = stack;
	while (current)
	{
		if (current->value < compare)
		{
			compare = current->value;
			smallest = current;
		}
		current = current->next;
	}
	return (smallest);
}

void	sort_for_3(t_stack **stack)
{
	int	i;

	i = 0;
	while (i < 2)
	{
		if ((*stack)->value > (*stack)->next->value)
			sa(stack);
		if ((*stack)->value > ft_lstlast(*stack)->value)
			ra(stack);
		if ((*stack)->value > (*stack)->next->value
			&& (*stack)->value > ft_lstlast(*stack)->value)
			ra(stack);
		if ((*stack)->next->value > ft_lstlast(*stack)->value)
			rra(stack);
		i++;
	}
}

void	sort_for_5(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*smallest;

	smallest = get_smallest(*stack_a);
	while (*stack_a != smallest)
		ra(stack_a);
	pb(stack_a, stack_b);
	smallest = get_smallest(*stack_a);
	while (*stack_a != smallest)
		ra(stack_a);
	pb(stack_a, stack_b);
	sort_for_3(stack_a);
	pa(stack_b, stack_a);
	pa(stack_b, stack_a);
}

void	radix(t_stack **stack_a, t_stack **stack_b)
{
	int	shift;
	int	max_nb_bits;
	int	size;

	shift = 0;
	max_nb_bits = get_nb_bits(ft_lstsize(*stack_a) - 1);
	while (shift < max_nb_bits)
	{
		size = ft_lstsize(*stack_a);
		while (size)
		{
			if (!(((*stack_a)->index >> shift) & 1) && !is_sorted(*stack_a))
				pb(stack_a, stack_b);
			else if (!is_sorted(*stack_a))
				ra(stack_a);
			size--;
		}
		radix_b(stack_a, stack_b, ++shift);
	}
	while (ft_lstsize(*stack_b))
		pa(stack_b, stack_a);
}

void	radix_b(t_stack **stack_a, t_stack **stack_b, int shift)
{
	int	size;
	int	max_nb_bits;

	size = ft_lstsize(*stack_b);
	max_nb_bits = get_nb_bits(ft_lstsize(*stack_a) + ft_lstsize(*stack_b) - 2);
	while (size)
	{
		if (((*stack_b)->index >> shift) & 1)
			pa(stack_b, stack_a);
		else if (shift < max_nb_bits)
			rb(stack_b);
		size--;
	}
}
