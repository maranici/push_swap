/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_b_to_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macuesta <macuesta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 08:55:09 by macuesta          #+#    #+#             */
/*   Updated: 2024/11/29 13:58:14 by macuesta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_b_to_a(t_stack **stack_a, t_stack **stack_b)
{
	reorder_stacks(stack_a, (*stack_b)->target, 'a');
	pa(stack_a, stack_b, true);
}
