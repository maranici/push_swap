/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_calcul.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macuesta <macuesta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 11:30:08 by macuesta          #+#    #+#             */
/*   Updated: 2024/12/06 11:46:50 by macuesta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
	set nb_ops of every node of s_a based on their position.
*/
int	biggest_one(int a, int b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

void	ops_calcul(t_stack *s_a, t_stack *s_b)
{
	int	len_a;
	int	len_b;
	int	va_under;
	int	va_above;

	len_a = stack_len(s_a);
	len_b = stack_len(s_b);
	while (s_a)
	{
		va_under = biggest_one(s_a->index, s_a->target->index);
		va_above = biggest_one(len_a - s_a->index, len_b - s_a->target->index);
		s_a->nb_ops = s_a->index;
		if (s_a->above_median)
			s_a->nb_ops = len_a - (s_a->index);
		if (!(s_a->target->above_median))
			s_a->nb_ops += (s_a->target->index);
		else
			s_a->nb_ops += len_b - (s_a->target->index);
		if (s_a->above_median && s_a->target->above_median)
			s_a->nb_ops = va_above;
		else if (!(s_a->above_median) && !(s_a->target->above_median))
			s_a->nb_ops = va_under;
		s_a = s_a->next;
	}
}
