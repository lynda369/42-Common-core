/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lybey <lybey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 23:55:05 by lybey             #+#    #+#             */
/*   Updated: 2024/03/25 03:42:31 by lybey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../ft_printf/ft_printf.h"
# include "../libft/libft.h"
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
}					t_stack;

typedef struct s_data
{
	t_stack			*stack_a;
	t_stack			*stack_b;
}					t_data;

int					check_error(char **av);
int					is_duplicate(char **av);
int					ft_strcmp(const char *s1, const char *s2);
int					check_is_int(char *num);
int					is_max_min(char **av);
t_stack				*ft_lstnew(int nbr);
void				ft_lstclear(t_stack *lst);
int					ft_lstsize(t_stack *lst);
t_stack				*ft_lstlast(t_stack *lst);
void				ft_lstadd_end(t_stack **lst, t_stack *new);
void				init_stack_a(char **av, t_stack **head);
void				print_stack(t_stack *stack, char c);
void				swap(t_stack **head);
t_stack				*ft_lstlast(t_stack *lst);
void				rotate(t_stack **head);
void				push(t_stack **stack_a, t_stack **stack_b);
void				reverse_rotate(t_stack **head);
void				pa(t_stack **stack_b, t_stack **stack_a);
void				pb(t_stack **stack_a, t_stack **stack_b);
void				sa(t_stack **head);
void				sb(t_stack **head);
void				ss(t_stack **stack_a, t_stack **stack_b);
void				ra(t_stack **stack_a);
void				rb(t_stack **stack_b);
void				rr(t_stack **stack_a, t_stack **stack_b);
void				rra(t_stack **stack_a);
void				rrb(t_stack **stack_b);
void				rrr(t_stack **stack_a, t_stack **stack_b);
void				ss(t_stack **stack_a, t_stack **stack_b);
int					is_sorted(t_stack *stack);
void				sort_for_3(t_stack **stack);
void				sort_for_5(t_stack **stack_a, t_stack **stack_b);
void				normalize(t_stack **stack);
void				radix(t_stack **stack_a, t_stack **stack_b);
int					get_nb_bits(int max);
void				radix_b(t_stack **stack_a, t_stack **stack_b, int shift);
void				choose_sort(t_stack **stack_a, t_stack **stack_b);

#endif