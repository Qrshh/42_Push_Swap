/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotates.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesneux <abesneux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 20:06:34 by abesneux          #+#    #+#             */
/*   Updated: 2024/03/26 17:48:52 by abesneux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	reverse_rotate(t_stack **stack)
{
	t_stack	*temp;
	t_stack	*tail;
	t_stack	*before_tail;

	tail = *stack;
	before_tail = *stack;
	while (tail->next)
		tail = tail->next;
	temp = *stack;
	while (before_tail && before_tail->next->next)
		before_tail = before_tail->next;
	*stack = tail;
	(*stack)->next = temp;
	before_tail->next = NULL;
}

void	reverse_rotate_b(t_stack **stack)
{
	reverse_rotate(stack);
	ft_printf("rrb\n");
}

void	reverse_rotate_a(t_stack **stack)
{
	reverse_rotate(stack);
	ft_printf("rra\n");
}

void	reverse_rotate_a_and_b(t_stack **stack_a, t_stack **stack_b)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	ft_printf("rrr\n");
}

void	do_rrr(t_stack **stack_a, t_stack **stack_b, t_stack *cheap)
{
	while ((*stack_a)->data != cheap->data
		&& (*stack_b)->data != cheap->target->data)
	{
		reverse_rotate_a_and_b(stack_a, stack_b);
	}
	init_pos(stack_a);
	init_pos(stack_b);
}
