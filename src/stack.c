/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesneux <abesneux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 19:17:56 by abesneux          #+#    #+#             */
/*   Updated: 2024/02/29 20:23:34 by abesneux         ###   ########.fr       */
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
	new->next = NULL;
	return (new);
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
	while (i < ac)
	{
		if (i == 1)
			stack = ft_stacknew(ft_atoi(av[1]));
		else
			stack_add_back(&stack, ft_stacknew(ft_atoi(av[i])));
		i++;
	}
	return (stack);
}
