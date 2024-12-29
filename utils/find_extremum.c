/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_extremum.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macuesta <macuesta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 10:04:31 by macuesta          #+#    #+#             */
/*   Updated: 2024/12/01 10:57:21 by macuesta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*find_min(t_stack *stack)
{
	long int	min;
	t_stack		*tmp;

	if (!stack)
		return (NULL);
	tmp = NULL;
	min = LONG_MAX;
	while (stack)
	{
		if (stack->n < min)
		{
			min = stack->n;
			tmp = stack;
		}
		stack = stack->next;
	}
	return (tmp);
}

t_stack	*find_max(t_stack *stack)
{
	long int	max;
	t_stack		*tmp;

	if (!stack)
		return (NULL);
	tmp = NULL;
	max = LONG_MIN;
	while (stack)
	{
		if (stack->n > max)
		{
			max = stack->n;
			tmp = stack;
		}
		stack = stack->next;
	}
	return (tmp);
}
