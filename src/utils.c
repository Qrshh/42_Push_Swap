/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesneux <abesneux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 19:04:20 by abesneux          #+#    #+#             */
/*   Updated: 2024/03/21 11:30:58 by abesneux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	init_pos(t_stack **stack)
{
	t_stack	*tmp;
	int		i;

	tmp = *stack;
	i = 0;
	while (tmp)
	{
		tmp->index = i;
		if (i < (stack_size(stack) / 2))
			tmp->above_median = 1;
		else
			tmp->above_median = 0;
		i++;
		tmp = tmp->next;
	}
}

void	init_cost(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp;

	tmp = *stack_a;
	init_pos(stack_a);
	init_pos(stack_b);
	while (tmp != NULL)
	{
		target_value_a(tmp, stack_b);
		tmp->cost = tmp->index;
		if (tmp->index > stack_size(stack_a) / 2)
			tmp->cost = stack_size(stack_a) - tmp->index;
		if (!tmp->target->above_median)
			tmp->cost += stack_size(stack_b) - tmp->target->index;
		else
			tmp->cost += tmp->target->index;
		tmp = tmp->next;
	}
}

void	target_value_a(t_stack *stack, t_stack **stack_b)
{
	t_stack	*tmp;

	tmp = *stack_b;
	while (tmp != NULL)
	{
		if (stack->data > tmp->data)
		{
			if (stack->target == NULL)
				stack->target = tmp;
			else if (stack->target->data < tmp->data)
				stack->target = tmp;
		}
		tmp = tmp->next;
	}
	if (stack->target == NULL)
	{
		stack->target = max(stack_b);
	}
}

void	target_value_b(t_stack *stack, t_stack **stack_a)
{
	t_stack	*tmp;

	tmp = *stack_a;
	while (tmp != NULL)
	
	{
		if (stack->data < tmp->data)
		{
			if (stack->target == NULL)
				stack->target = tmp;
			else if (stack->target->data > tmp->data)
				stack->target = tmp;
		}
		tmp = tmp->next;
	}
	if (stack->target == NULL)
	{
		stack->target = min(stack_a);
	}
}

void	exit_error(char *msg)
{
	write(STDERR_FILENO, msg, ft_strlen(msg));
	write(STDERR_FILENO, "\n", 1);
	exit(EXIT_FAILURE);
}
