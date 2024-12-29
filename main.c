/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macuesta <macuesta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 15:18:58 by macuesta          #+#    #+#             */
/*   Updated: 2024/12/09 18:09:17 by macuesta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	**splited;
	bool	do_we_free;

	do_we_free = false;
	if (ac == 1)
		return (1);
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
		return (1);
	}
	stack_a = create_stack_a(splited, do_we_free);
	stack_b = NULL;
	push_swap(&stack_a, &stack_b);
	ft_free_stack(&stack_a);
}
