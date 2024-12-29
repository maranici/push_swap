/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macuesta <macuesta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 10:02:29 by macuesta          #+#    #+#             */
/*   Updated: 2024/12/09 17:10:22 by macuesta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate(t_stack **stack)
{
	t_stack	*tmp_last;

	if (!*stack || !(*stack)->next)
		return ;
	tmp_last = ft_stacklast(*stack);
	tmp_last->prev->next = NULL;
	tmp_last->prev = NULL;
	tmp_last->next = *stack;
	*stack = tmp_last;
	tmp_last->next->prev = tmp_last;
}

void	rra(t_stack **a, bool print)
{
	if (!a || !*a)
		return ;
	reverse_rotate(a);
	if (print)
		ft_printf("rra\n");
}

void	rrb(t_stack **b, bool print)
{
	if (!b || !*b)
		return ;
	reverse_rotate(b);
	if (print)
		ft_printf("rrb\n");
}

void	rrr(t_stack **a, t_stack **b, bool print)
{
	if (!a || !*a || !b || !*b)
		return ;
	reverse_rotate(a);
	reverse_rotate(b);
	if (print)
		ft_printf("rrr\n");
}
