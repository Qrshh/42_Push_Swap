/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotates.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesneux <abesneux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 19:34:04 by abesneux          #+#    #+#             */
/*   Updated: 2024/03/26 17:48:55 by abesneux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	rotate(t_stack **stack)
{
	t_stack	*temp;
	t_stack	*head;

	temp = *stack;
	head = *stack;
	*stack = (*stack)->next;
	while (head && head->next)
		head = head->next;
	temp->next = NULL;
	head->next = temp;
}

void	rotate_stack_b(t_stack **stack)
{
	rotate(stack);
	ft_printf("rb\n");
}

void	rotate_stack_a(t_stack **stack)
{
	rotate(stack);
	ft_printf("ra\n");
}

void	rotate_a_and_b(t_stack **stack_a, t_stack **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	ft_printf("rr\n");
}

void	do_rr(t_stack **stack_a, t_stack **stack_b, t_stack *cheap)
{
	while ((*stack_b)->data != cheap->target->data
		&& (*stack_a)->data != cheap->data)
	{
		rotate_a_and_b(stack_a, stack_b);
	}
	init_pos(stack_a);
	init_pos(stack_b);
}
