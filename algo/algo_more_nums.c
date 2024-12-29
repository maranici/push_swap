/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_more_nums.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macuesta <macuesta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 15:36:45 by macuesta          #+#    #+#             */
/*   Updated: 2024/12/12 11:53:19 by macuesta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	algo_more_nums(t_stack **stack_a, t_stack **stack_b)
{
	int	len_stack;

	len_stack = stack_len(*stack_a);
	if (len_stack-- > 3 && !check_if_sorted(*stack_a))
		pb(stack_a, stack_b, true);
	if (len_stack-- > 3 && !check_if_sorted(*stack_a))
		pb(stack_a, stack_b, true);
	while (len_stack-- > 3)
	{
		init_stack_a(*stack_a, *stack_b);
		push_a_to_b(stack_a, stack_b);
	}
	algo_three_nums(stack_a);
	while (*stack_b)
	{
		set_node_index(*stack_a);
		set_node_index(*stack_b);
		target_node_b(*stack_a, *stack_b);
		push_b_to_a(stack_a, stack_b);
	}
	set_node_index(*stack_a);
	order_a(stack_a);
}
