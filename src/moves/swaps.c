/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swaps.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesneux <abesneux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 19:42:50 by abesneux          #+#    #+#             */
/*   Updated: 2024/02/29 20:23:45 by abesneux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	swap(t_stack **stack)
{
	int	tmp;

	tmp = (*stack)->data;
	(*stack)->data = (*stack)->next->data;
	(*stack)->next->data = tmp;
}

void	swap_stack_b(t_stack **stack)
{
	swap(stack);
	ft_printf("sb\n");
}

void	swap_stack_a(t_stack **stack)
{
	swap(stack);
	ft_printf("sa\n");
}

void	swap_a_and_b(t_stack **stack_a, t_stack **stack_b)
{
	swap_stack_a(stack_a);
	swap_stack_b(stack_b);
	ft_printf("ss\n");
}
