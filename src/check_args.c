/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesneux <abesneux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 19:02:21 by abesneux          #+#    #+#             */
/*   Updated: 2024/03/28 19:24:12 by abesneux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	is_num(char *str)
{
	int	i;

	i = 0;
	if ((str[i] == '+' || str[i] == '-') && str[i])
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	if (ft_atoi(str) > INT_MAX || ft_atoi(str) < INT_MIN)
		return (0);
	return (1);
}

int	is_dup(int ac, char **str)
{
	int	i;
	int	j;

	i = 1;
	if (ac == 2)
		i = 0;
	while (str[i])
	{
		j = 1;
		while (str[j])
		{
			if (j != i && (ft_atoi(str[i]) == ft_atoi(str[j])))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

void	verif_av(int ac, char **av)
{
	if (ac == 2)
	{
		if (!av[0])
		{
			free_tab_av(av);
			exit(EXIT_FAILURE);
		}
	}
}

void	args_check(int ac, char **av)
{
	int	i;

	i = 1;
	if (ac == 2)
		i = 0;
	verif_av(ac, av);
	while (av[i])
	{
		if (!is_num(av[i]))
		{
			if (ac == 2)
				free_tab_av(av);
			exit_error("Error \n");
		}
		i++;
	}
	if (is_dup(ac, av) || !av[1])
	{
		if (!is_dup(ac, av))
			ft_printf("Error\n");
		if (ac == 2)
			free_tab_av(av);
		exit(EXIT_FAILURE);
	}
}

void	free_tab_av(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}
