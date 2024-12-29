/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_three_nums.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macuesta <macuesta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 12:56:55 by macuesta          #+#    #+#             */
/*   Updated: 2024/11/26 17:41:19 by macuesta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	algo_three_nums(t_stack **stack_a)
{
	t_stack	*max_node;

	max_node = find_max(*stack_a);
	if (*stack_a == max_node)
		ra(stack_a, true);
	else if ((*stack_a)->next == max_node)
		rra(stack_a, true);
	if ((*stack_a)->n > (*stack_a)->next->n)
		sa(stack_a, true);
}
