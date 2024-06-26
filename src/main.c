/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesneux <abesneux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 17:43:13 by abesneux          #+#    #+#             */
/*   Updated: 2024/03/27 13:52:04 by abesneux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_stack(t_stack **stack_a, t_stack **stack_b)
{
	if (stack_size(stack_a) <= 3)
		simple_sort(stack_a, stack_b);
	else
		push_swap(stack_a, stack_b);
}

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (ac == 2)
		av = ft_split(av[1], ' ');
	args_check(ac, av);
	stack_a = init_stack(ac, av);
	stack_b = NULL;
	if (stack_is_sorted(&stack_a))
	{
		if (ac == 2)
			free_tab_av(av);
		free_stack(&stack_a);
		return (0);
	}
	sort_stack(&stack_a, &stack_b);
	free_stack(&stack_a);
	free_stack(&stack_b);
	if (ac == 2)
		free_tab_av(av);
	return (0);
}
