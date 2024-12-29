/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order_a.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macuesta <macuesta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 09:12:48 by macuesta          #+#    #+#             */
/*   Updated: 2024/12/02 12:50:40 by macuesta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	order_a(t_stack **stack_a)
{
	while ((*stack_a)->n != find_min(*stack_a)->n)
	{
		set_node_index(*stack_a);
		if (find_min(*stack_a)->above_median)
			rra(stack_a, true);
		else
			ra(stack_a, true);
	}
}
