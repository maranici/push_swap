/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_a_to_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macuesta <macuesta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 18:09:54 by macuesta          #+#    #+#             */
/*   Updated: 2024/12/02 13:57:14 by macuesta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_a_to_b(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*cheapest;

	cheapest = get_cheapest(*stack_a);
	if (!(cheapest->above_median) && !(cheapest->target->above_median))
	{
		while (*stack_b != cheapest->target && *stack_a != cheapest)
			rr(stack_a, stack_b, true);
		set_node_index(*stack_a);
		set_node_index(*stack_b);
	}
	else if (cheapest->above_median && cheapest->target->above_median)
	{
		while (*stack_b != cheapest->target && *stack_a != cheapest)
			rrr(stack_a, stack_b, true);
		set_node_index(*stack_a);
		set_node_index(*stack_b);
	}
	reorder_stacks(stack_a, cheapest, 'a');
	reorder_stacks(stack_b, cheapest->target, 'b');
	pb(stack_a, stack_b, true);
}
