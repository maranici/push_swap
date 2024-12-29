/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macuesta <macuesta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 09:39:45 by macuesta          #+#    #+#             */
/*   Updated: 2024/12/09 17:10:40 by macuesta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_stack **stack)
{
	t_stack	*tmp_last;

	if (!(*stack || (*stack)->next))
		return ;
	tmp_last = ft_stacklast(*stack);
	tmp_last->next = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	tmp_last->next->prev = tmp_last;
	tmp_last->next->next = NULL;
}

void	ra(t_stack **a, bool print)
{
	if (!a || !*a)
		return ;
	rotate(a);
	if (print)
		ft_printf("ra\n");
}

void	rb(t_stack **b, bool print)
{
	if (!b || !*b)
		return ;
	rotate(b);
	if (print)
		ft_printf("rb\n");
}

void	rr(t_stack **a, t_stack **b, bool print)
{
	if (!a || !*a || !b || !*b)
		return ;
	rotate(a);
	rotate(b);
	if (print)
		ft_printf("rr\n");
}
