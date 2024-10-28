/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lybey <lybey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 23:55:01 by lybey             #+#    #+#             */
/*   Updated: 2024/03/26 00:48:29 by lybey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	is_sorted(t_stack *stack)
{
	t_stack	*current;

	current = stack;
	while (current->next != NULL)
	{
		if (current->value > current->next->value)
			return (0);
		current = current->next;
	}
	return (1);
}

int	get_nb_bits(int max)
{
	int	i;

	i = 0;
	while (max >= 2)
	{
		max = max / 2;
		i++;
	}
	i++;
	return (i);
}

void	normalize(t_stack **stack)
{
	t_stack	*current;
	t_stack	*buf;

	current = *stack;
	while (current)
	{
		buf = *stack;
		while (buf)
		{
			if (current->value > buf->value)
			{
				current->index++;
			}
			buf = buf->next;
		}
		current = current->next;
	}
}

void	choose_sort(t_stack **stack_a, t_stack **stack_b)
{
	int	size;

	size = ft_lstsize(*stack_a);
	if (size == 3 || size == 2)
		sort_for_3(stack_a);
	else if (size == 4 || size == 5)
		sort_for_5(stack_a, stack_b);
	else
		radix(stack_a, stack_b);
}

int	main(int ac, char **av)
{
	static t_data	data = {0};

	data.stack_a = NULL;
	data.stack_a = NULL;
	if (ac < 3)
		return (ft_printf("Error\n"), 0);
	if (!check_error(av))
		return (0);
	init_stack_a(av, &(data.stack_a));
	if (is_sorted(data.stack_a))
	{
		ft_lstclear(data.stack_a);
		return (0);
	}
	normalize(&data.stack_a);
	choose_sort(&data.stack_a, &data.stack_b);
	ft_lstclear(data.stack_a);
	return (0);
}
