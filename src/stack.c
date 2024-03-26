/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesneux <abesneux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 19:17:56 by abesneux          #+#    #+#             */
/*   Updated: 2024/03/26 17:49:51 by abesneux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	stack_size(t_stack **stack)
{
	t_stack	*tmp;
	int		len;

	tmp = *stack;
	len = 0;
	while (tmp != NULL)
	{
		tmp = tmp->next;
		len++;
	}
	return (len);
}

t_stack	*ft_stacknew(int data)
{
	t_stack	*new;

	new = (t_stack *)malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->data = data;
	new->index = 0;
	new->cost = 0;
	new->above_median = 0;
	new->target = NULL;
	new->next = NULL;
	return (new);
}

void	stack_add_front(t_stack **stack, t_stack *new)
{
	if (!new)
		return ;
	if (!*stack)
	{
		*stack = new;
		return ;
	}
	new->next = *stack;
	*stack = new;
}

void	stack_add_back(t_stack **stack, t_stack *new)
{
	t_stack	*tmp;

	tmp = *stack;
	if (!*stack)
		*stack = new;
	else
	{
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new;
	}
}

t_stack	*init_stack(int ac, char **av)
{
	int		i;
	t_stack	*stack;

	i = 1;
	if (ac == 2)
		i = 0;
	else
	{
		stack = ft_stacknew(ft_atoi(av[i]));
		i = 2;
	}
	while (av[i])
	{
		if (i == 0)
			stack = ft_stacknew(ft_atoi(av[i]));
		else
			stack_add_back(&stack, ft_stacknew(ft_atoi(av[i])));
		i++;
	}
	return (stack);
}
