/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesneux <abesneux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 16:31:43 by abesneux          #+#    #+#             */
/*   Updated: 2024/03/26 17:49:46 by abesneux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack	*max(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*max;

	tmp = *stack;
	max = *stack;
	while (tmp)
	{
		if (tmp->data > max->data)
			max = tmp;
		tmp = tmp->next;
	}
	return (max);
}

int	stack_is_sorted(t_stack **stack)
{
	t_stack	*tmp;

	tmp = *stack;
	while (tmp && tmp->next)
	{
		if (tmp->data > tmp->next->data)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

void	free_stack(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*head;

	head = *stack;
	while (head)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
}

t_stack	*cheapest(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*cheapest;

	tmp = *stack;
	cheapest = NULL;
	while (tmp)
	{
		if (cheapest == NULL)
			cheapest = tmp;
		else if (tmp->cost < cheapest->cost)
			cheapest = tmp;
		tmp = tmp->next;
	}
	return (cheapest);
}
