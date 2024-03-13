/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotates.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesneux <abesneux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 20:06:34 by abesneux          #+#    #+#             */
/*   Updated: 2024/02/29 20:23:38 by abesneux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	reverse_rotate(t_stack **stack)
{
	t_stack	*temp;

	temp = *stack;
	while (temp->next->next)
		temp = temp->next;
	stack_add_back(stack, ft_stacknew(temp->next->data));
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
	reverse_rotate_a(stack_a);
	reverse_rotate_b(stack_b);
	ft_printf("rrr\n");
}
