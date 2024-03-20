/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesneux <abesneux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 17:45:20 by abesneux          #+#    #+#             */
/*   Updated: 2024/03/20 19:19:06 by abesneux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "Libft/inc/libft.h"

typedef struct s_stack
{
	int				data;
	int				index;
	int				cost;
	int				above_median;
	struct s_stack	*target;
	struct s_stack	*next;
}					t_stack;

// ARGS CHECKERS
void				args_check(char **av);

// EXIT
void				exit_error(char *msg);

// UTILS
t_stack				*max(t_stack **stack);
t_stack				*min(t_stack **stack);
void				init_pos(t_stack **stack);
void				init_cost(t_stack **stack_a, t_stack **stack_b);
void				target_value_a(t_stack *stack, t_stack **stack_b);
void				target_value_b(t_stack *stack, t_stack **stack_a);
t_stack				*cheapest(t_stack **stack);
void				min_on_top(t_stack **stack);

// STACK
t_stack				*ft_stacknew(int data);
void				stack_add_back(t_stack **stack, t_stack *new);
void				stack_add_front(t_stack **stack, t_stack *new);
t_stack				*init_stack(int ac, char **av);
int					stack_size(t_stack **stack);
int					stack_is_sorted(t_stack **stack);
void				free_stack(t_stack **stack);

// SORT
void				simple_sort(t_stack **stack_a, t_stack **stack_b);
void				sort_three(t_stack **stack);
void				push_swap(t_stack **stack_a, t_stack **stack_b);

// SORT UTILS
void				move_a_to_b(t_stack **stack_a, t_stack **stack_b);
void				go_top(t_stack **stack, t_stack *cheap, char stack_name);
void				move_b_to_a(t_stack **stack_a, t_stack **stack_b);
void				clear_near(t_stack **stack);

// MOVES
void				rotate(t_stack **stack);
void				rotate_stack_a(t_stack **stack);
void				rotate_stack_b(t_stack **stack);
void				rotate_a_and_b(t_stack **stack_a, t_stack **stack_b);
void				do_rr(t_stack **stack_a, t_stack **stack_b, t_stack *cheap);

void				swap(t_stack **stack);
void				swap_stack_a(t_stack **stack);
void				swap_stack_b(t_stack **stack);
void				swap_a_and_b(t_stack **stack_a, t_stack **stack_b);

void				push_stack_a(t_stack **stack_a, t_stack **stack_b);
void				push_stack_b(t_stack **stack_a, t_stack **stack_b);

void				reverse_rotate_a(t_stack **stack);
void				reverse_rotate_b(t_stack **stack);
void				reverse_rotate(t_stack **stack);
void				reverse_rotate_a_and_b(t_stack **stack_a,
						t_stack **stack_b);
void				do_rrr(t_stack **stack_a, t_stack **stack_b,
						t_stack *cheap);

#endif