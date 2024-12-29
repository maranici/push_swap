/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macuesta <macuesta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 09:25:06 by macuesta          #+#    #+#             */
/*   Updated: 2024/12/09 08:36:01 by macuesta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(t_stack **stack_a, t_stack **stack_b)
{
	unsigned int	chain_len;

	if (!stack_a)
		return ;
	chain_len = stack_len(*stack_a);
	if (!check_if_sorted(*stack_a))
	{
		if (chain_len == 2)
			algo_two_nums(stack_a);
		else if (chain_len == 3)
			algo_three_nums(stack_a);
		else
			algo_more_nums(stack_a, stack_b);
	}
}
