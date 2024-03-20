/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesneux <abesneux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 18:58:32 by abesneux          #+#    #+#             */
/*   Updated: 2024/03/20 19:14:26 by abesneux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

t_stack	*min(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*min;

	tmp = *stack;
	min = NULL;
	while (tmp)
	{
		if (min == NULL)
			min = tmp;
		else if (tmp->data < min->data)
			min = tmp;
		tmp = tmp->next;
	}
	return (min);
}

void min_on_top(t_stack **stack)
{
    init_pos(stack);
    while((*stack)->data != min(stack)->data)
    {
        if(min(stack)->above_median)
            rotate_stack_a(stack);
        else
        {
            reverse_rotate_a(stack);
        }
    }
}