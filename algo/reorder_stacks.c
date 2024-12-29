/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reorder_stacks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macuesta <macuesta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 18:26:10 by macuesta          #+#    #+#             */
/*   Updated: 2024/11/29 14:02:19 by macuesta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reorder_stacks(t_stack **stack, t_stack *top_node, char name)
{
	while (*stack != top_node)
	{
		if (name == 'a')
		{
			if (top_node->above_median)
				rra(stack, true);
			else
				ra(stack, true);
		}
		if (name == 'b')
		{
			if (top_node->above_median)
				rrb(stack, true);
			else
				rb(stack, true);
		}
	}
}
