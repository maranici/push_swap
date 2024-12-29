/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_if_sorted.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macuesta <macuesta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 11:12:38 by macuesta          #+#    #+#             */
/*   Updated: 2024/11/26 11:12:38 by macuesta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	check_if_sorted(t_stack *stack)
{
	if (!stack)
		return (false);
	while (stack)
	{
		if (stack->next && stack->n > stack->next->n)
			return (false);
		stack = stack->next;
	}
	return (true);
}
