/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotates.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesneux <abesneux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 20:06:34 by abesneux          #+#    #+#             */
/*   Updated: 2024/03/21 11:36:06 by abesneux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	reverse_rotate(t_stack **stack)
{
	t_stack	*temp;

	temp = *stack;
	while (temp->next->next)
		temp = temp->next;
	stack_add_front(stack, ft_stacknew(temp->next->data));
	temp->next = NULL;
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
