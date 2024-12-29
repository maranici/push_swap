/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   target_node.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macuesta <macuesta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 10:59:19 by macuesta          #+#    #+#             */
/*   Updated: 2024/12/01 11:04:57 by macuesta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*	This function aims to initialize the t_stack *target of every node
 *	of our struct stack_a.
 *	With this idea we can now know where every node of stack_a needs
 *	to be in stack_b.
*/
void	target_node_a(t_stack *stack_a, t_stack *stack_b)
{
	t_stack		*target;
	t_stack		*current_b;
	long int	target_index;

	while (stack_a)
	{
		target_index = LONG_MIN;
		current_b = stack_b;
		while (current_b)
		{
			if (current_b->n < stack_a->n && current_b->n > target_index)
			{
				target_index = current_b->n;
				target = current_b;
			}
			current_b = current_b->next;
		}
		if (target_index == LONG_MIN)
			stack_a->target = find_max(stack_b);
		else
			stack_a->target = target;
		stack_a = stack_a->next;
	}
}

void	target_node_b(t_stack *stack_a, t_stack *stack_b)
{
	t_stack		*target;
	t_stack		*current_a;
	long int	target_index;

	while (stack_b)
	{
		target_index = LONG_MAX;
		current_a = stack_a;
		while (current_a)
		{
			if (current_a->n > stack_b->n && current_a->n < target_index)
			{
				target_index = current_a->n;
				target = current_a;
			}
			current_a = current_a->next;
		}
		if (target_index == LONG_MAX)
			stack_b->target = find_min(stack_a);
		else
			stack_b->target = target;
		stack_b = stack_b->next;
	}
}
