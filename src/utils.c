/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesneux <abesneux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 19:04:20 by abesneux          #+#    #+#             */
/*   Updated: 2024/02/29 20:23:30 by abesneux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	init_pos(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp_a;
	t_stack	*tmp_b;
	int		i;

	tmp_a = *stack_a;
	tmp_b = *stack_b;
	i = 0;
	while (tmp_a)
	{
		tmp_a->index = i;
		i++;
		tmp_a = tmp_a->next;
	}
	i = 0;
	while (tmp_b)
	{
		tmp_b->index = i;
		i++;
		tmp_b = tmp_b->next;
	}
}

void	init_cost(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp;
	int		i;

	tmp = *stack_a;
	i = 0;
	init_pos(stack_a, stack_b);
	while (tmp != NULL)
	{
		near_value(tmp, stack_b);
		tmp->cost = i;
		if (i > stack_size(stack_a) / 2)
			tmp->cost = stack_size(stack_a) - i;
		if (tmp->target->index > stack_size(stack_b) / 2)
			tmp->cost += stack_size(stack_b) - tmp->target->index;
		else
			tmp->cost += tmp->target->index;
		i++;
		tmp = tmp->next;
	}
}

void	near_value(t_stack *stack, t_stack **stack_b)
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
		else if (stack->target == NULL)
			stack->target = max(stack_b);
		tmp = tmp->next;
	}
}

void	exit_error(char *msg)
{
	write(STDERR_FILENO, msg, ft_strlen(msg));
	write(STDERR_FILENO, "\n", 1);
	exit(EXIT_FAILURE);
}
