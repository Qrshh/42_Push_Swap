/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesneux <abesneux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 13:20:07 by abesneux          #+#    #+#             */
/*   Updated: 2024/03/28 13:42:49 by abesneux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	functions(char *cmd, t_stack **stack_a, t_stack **stack_b)
{
	if (!(ft_strcmp(cmd, "sa\n")))
		swap(stack_a);
	else if (!(ft_strcmp(cmd, "sb\n")))
		swap(stack_b);
	else if (!(ft_strcmp(cmd, "ss\n")))
		swap_a_and_b(stack_a, stack_b);
	else if (!(ft_strcmp(cmd, "pa\n")))
		push(stack_a, stack_b, 'a');
	else if (!(ft_strcmp(cmd, "pb\n")))
		push(stack_a, stack_b, 'b');
	else if (!(ft_strcmp(cmd, "rra\n")))
		reverse_rotate(stack_a);
	else if (!(ft_strcmp(cmd, "rrb\n")))
		reverse_rotate(stack_b);
	else if (!(ft_strcmp(cmd, "rrr\n")))
		reverse_rotate_a_and_b(stack_a, stack_b);
	else if (!(ft_strcmp(cmd, "ra\n")))
		rotate(stack_a);
	else if (!(ft_strcmp(cmd, "rb\n")))
		rotate(stack_b);
	else if (!(ft_strcmp(cmd, "rr\n")))
		rotate_a_and_b(stack_a, stack_b);
}

void	print_result(t_stack **stack_a, t_stack **stack_b)
{
	if (stack_is_sorted(stack_a) && (*stack_b) == NULL)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
}

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	*cmd;

	if (ac == 2)
		av = ft_split(av[1], ' ');
	args_check(ac, av);
	stack_a = init_stack(ac, av);
	stack_b = NULL;
	cmd = get_next_line(0);
	while (cmd != NULL)
	{
		functions(cmd, &stack_a, &stack_b);
		free(cmd);
		cmd = get_next_line(0);
	}
	if (stack_is_sorted(&stack_a) && stack_b == NULL)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	if (ac == 2)
		free_tab_av(av);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
