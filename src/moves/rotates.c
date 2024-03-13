/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotates.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesneux <abesneux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 19:34:04 by abesneux          #+#    #+#             */
/*   Updated: 2024/02/29 20:23:41 by abesneux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	rotate(t_stack **stack)
{
	t_stack	*temp;

	temp = *stack;
	while (temp->next)
		temp = temp->next;
	temp->next = ft_stacknew((*stack)->data);
	*stack = (*stack)->next;
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
	rotate_stack_a(stack_a);
	rotate_stack_b(stack_b);
	ft_printf("rr\n");
}
