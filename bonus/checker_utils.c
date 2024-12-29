/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macuesta <macuesta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 08:55:15 by macuesta          #+#    #+#             */
/*   Updated: 2024/12/09 17:06:55 by macuesta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*init_splited_and_stack_a(int ac, char **av)
{
	bool	do_we_free;
	char	**splited;
	t_stack	*stack_a;

	do_we_free = false;
	if (ac == 1)
		return (NULL);
	if (ac == 2 && av[1][0])
	{
		splited = ft_split(av[1], ' ');
		do_we_free = true;
	}
	else
		splited = av + 1;
	if (!splited || !splited[0] || !splited[0][0] || check_errors(splited))
	{
		ft_free_splited(splited, do_we_free);
		ft_putstr_fd("Error\n", 2);
		return (NULL);
	}
	stack_a = create_stack_a(splited, do_we_free);
	return (stack_a);
}

void	free_all_checker(t_stack **a, t_stack **b, char **s)
{
	t_stack	*tmp;

	if (a)
	{
		while (*a)
		{
			tmp = (*a)->next;
			free(*a);
			*a = tmp;
		}
	}
	if (b)
	{
		while (*b)
		{
			tmp = (*b)->next;
			free(*b);
			*b = tmp;
		}
	}
	if (s && *s)
		free(*s);
	get_next_line(-1);
}
