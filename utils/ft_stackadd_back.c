/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stackadd_back.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macuesta <macuesta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 15:09:32 by macuesta          #+#    #+#             */
/*   Updated: 2024/11/29 13:53:19 by macuesta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_stackadd_back(t_stack **stack, t_stack *new)
{
	t_stack	*last_node;

	if (stack)
	{
		if (*stack)
		{
			last_node = ft_stacklast(*stack);
			last_node->next = new;
			new->prev = last_node;
		}
		else
		{
			*stack = new;
			new->prev = NULL;
		}
	}
}
