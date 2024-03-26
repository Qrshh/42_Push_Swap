/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesneux <abesneux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 16:54:14 by abesneux          #+#    #+#             */
/*   Updated: 2024/03/26 17:49:05 by abesneux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	swap_rotate_swap(t_stack **stack)
{
	swap_stack_a(stack);
	rotate_stack_a(stack);
	swap_stack_a(stack);
}

void	pick_functions(t_stack *top, t_stack *middle, t_stack **stack)
{
	if ((*stack)->data < middle->data && middle->data > top->data
		&& top->data < (*stack)->data)
		swap_rotate_swap(stack);
	else if ((*stack)->data < middle->data && middle->data < top->data)
	{
		swap_stack_a(stack);
		reverse_rotate_a(stack);
	}
	else if (middle->data < top->data && (*stack)->data > top->data)
		rotate_stack_a(stack);
	else if (middle->data > top->data && (*stack)->data < top->data)
	{
		reverse_rotate_a(stack);
		swap_stack_a(stack);
	}
	else if (middle->data < top->data && (*stack)->data < top->data)
		swap_stack_a(stack);
	else if ((*stack)->data > middle->data && middle->data > top->data)
	{
		rotate_stack_a(stack);
		swap_stack_a(stack);
	}
}

void	sort_three(t_stack **stack)
{
	t_stack	*top;
	t_stack	*middle;

	top = (*stack)->next->next;
	middle = (*stack)->next;
	pick_functions(top, middle, stack);
}

void	simple_sort(t_stack **stack_a, t_stack **stack_b)
{
	int	size;

	(void)stack_b;
	if (stack_is_sorted(stack_a) || stack_size(stack_a) == 0
		|| stack_size(stack_a) == 1)
		return ;
	size = stack_size(stack_a);
	if (size == 2)
		swap_stack_a(stack_a);
	else if (size == 3)
		sort_three(stack_a);
}
