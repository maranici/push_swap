/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack_a.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macuesta <macuesta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 17:27:28 by macuesta          #+#    #+#             */
/*   Updated: 2024/12/07 13:24:42 by macuesta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*create_node_a(int n)
{
	t_stack	*new;

	new = (t_stack *)ft_calloc(1, sizeof(t_stack));
	if (!new)
		return (NULL);
	new->n = n;
	new->index = 0;
	new->nb_ops = 0;
	new->is_cheapest = false;
	new->above_median = false;
	new->target = NULL;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

t_stack	*create_stack_a(char **splited, bool do_we_free)
{
	int		i;
	t_stack	*stack_a;
	t_stack	*new;

	i = 0;
	stack_a = NULL;
	while (splited && splited[i])
	{
		new = create_node_a(ft_atoi(splited[i]));
		if (!new)
		{
			ft_free_stack(&stack_a);
			return (NULL);
		}
		ft_stackadd_back(&stack_a, new);
		i++;
	}
	i = 0;
	while (do_we_free && splited && splited[i])
		free(splited[i++]);
	if (do_we_free && splited)
		free(splited);
	return (stack_a);
}
