/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macuesta <macuesta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 16:32:58 by macuesta          #+#    #+#             */
/*   Updated: 2024/12/02 14:55:39 by macuesta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_stack_a(t_stack *stack_a, t_stack *stack_b)
{
	set_node_index(stack_a);
	set_node_index(stack_b);
	target_node_a(stack_a, stack_b);
	ops_calcul(stack_a, stack_b);
	define_cheapest(stack_a);
}
