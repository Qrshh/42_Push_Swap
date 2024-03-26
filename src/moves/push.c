/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesneux <abesneux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 19:46:10 by abesneux          #+#    #+#             */
/*   Updated: 2024/03/26 20:23:10 by abesneux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	push(t_stack **stack_a, t_stack **stack_b, char name)
{
	t_stack	*tmp;

	if (name == 'a')
	{
		if (*stack_b == NULL)
			return ;
		tmp = (*stack_b)->next;
		(*stack_b)->next = *stack_a;
		*stack_a = *stack_b;
		*stack_b = tmp;
	}
	else if (name == 'b')
	{
		if (*stack_a == NULL)
			return ;
		tmp = (*stack_a)->next;
		(*stack_a)->next = *stack_b;
		*stack_b = *stack_a;
		*stack_a = tmp;
	}
}

void	push_stack_b(t_stack **stack_a, t_stack **stack_b)
{
	push(stack_a, stack_b, 'b');
	ft_printf("pb\n");
}

void	push_stack_a(t_stack **stack_a, t_stack **stack_b)
{
	push(stack_a, stack_b, 'a');
	ft_printf("pa\n");
}
