/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesneux <abesneux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 17:32:30 by abesneux          #+#    #+#             */
/*   Updated: 2024/03/27 13:45:42 by abesneux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	push_swap(t_stack **stack_a, t_stack **stack_b)
{
	if (stack_size(stack_a) > 3 && !stack_is_sorted(stack_a))
		push_stack_b(stack_a, stack_b);
	if (stack_size(stack_a) > 3 && !stack_is_sorted(stack_a))
		push_stack_b(stack_a, stack_b);
	while (stack_size(stack_a) > 3 && !stack_is_sorted(stack_a))
	{
		init_pos(stack_a);
		init_pos(stack_b);
		move_a_to_b(stack_a, stack_b);
		clear_near(stack_a);
	}
	simple_sort(stack_a, stack_b);
	while (*stack_b)
	{
		init_pos(stack_a);
		init_pos(stack_b);
		clear_near(stack_b);
		target_value_b(*stack_b, stack_a);
		move_b_to_a(stack_a, stack_b);
		clear_near(stack_b);
	}
	min_on_top(stack_a);
}

void	move_a_to_b(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*cheap;

	init_cost(stack_a, stack_b);
	cheap = cheapest(stack_a);
	if (cheap->above_median && cheap->target->above_median)
		do_rr(stack_a, stack_b, cheap);
	else if (!(cheap->above_median) && !(cheap->target->above_median))
		do_rrr(stack_a, stack_b, cheap);
	go_top(stack_a, cheap, 'a');
	go_top(stack_b, cheap->target, 'b');
	push_stack_b(stack_a, stack_b);
}

void	go_top(t_stack **stack, t_stack *cheap, char stack_name)
{
	while ((*stack)->data != cheap->data)
	{
		if (stack_name == 'a')
		{
			if (cheap->above_median)
				rotate_stack_a(stack);
			else
				reverse_rotate_a(stack);
		}
		else if (stack_name == 'b')
		{
			if (cheap->above_median)
				rotate_stack_b(stack);
			else
				reverse_rotate_b(stack);
		}
	}
}

void	move_b_to_a(t_stack **stack_a, t_stack **stack_b)
{
	go_top(stack_a, (*stack_b)->target, 'a');
	push_stack_a(stack_a, stack_b);
}

void	clear_near(t_stack **stack)
{
	t_stack	*tmp;

	tmp = *stack;
	while (tmp)
	{
		tmp->target = NULL;
		tmp = tmp->next;
	}
}
