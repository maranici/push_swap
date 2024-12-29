/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macuesta <macuesta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 08:49:57 by macuesta          #+#    #+#             */
/*   Updated: 2024/12/09 08:57:44 by macuesta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	is_endl(char c)
{
	if (c == '\n' || c == '\0')
		return (1);
	return (0);
}

int	which_instruction_b(t_stack **a, t_stack **b, char *s, bool *bad_inst)
{
	if (!b || !*b)
		*bad_inst = true;
	if (s[0] == 's' && s[1] == 'b' && is_endl(s[2]))
		sb(b, false);
	else if (s[0] == 'r' && s[1] == 'b' && is_endl(s[2]))
		rb(b, false);
	else if (s[0] == 'r' && s[1] == 'r' && is_endl(s[2]))
		rr(a, b, false);
	else if (s[0] == 'r' && s[1] == 'r' && s[2] == 'b' && is_endl(s[3]))
		rrb(b, false);
	else if (s[0] == 'r' && s[1] == 'r' && s[2] == 'r' && is_endl(s[3]))
		rrr(a, b, false);
	else
		return (-1);
	return (0);
}

int	which_instruction(t_stack **a, t_stack **b, char *s, bool *bad_inst)
{
	if (!s)
		return (-1);
	if (!ft_strchr(s, 'b') && (!a || !*a))
		*bad_inst = true;
	if (s[0] == 's' && s[1] == 'a' && is_endl(s[2]))
		sa(a, false);
	else if (s[0] == 's' && s[1] == 's' && is_endl(s[2]))
		ss(a, b, false);
	else if (s[0] == 'p' && s[1] == 'a' && is_endl(s[2]))
		pa(a, b, false);
	else if (s[0] == 'p' && s[1] == 'b' && is_endl(s[2]))
		pb(a, b, false);
	else if (s[0] == 'r' && s[1] == 'a' && is_endl(s[2]))
		ra(a, false);
	else if (s[0] == 'r' && s[1] == 'r' && s[2] == 'a' && is_endl(s[3]))
		rra(a, false);
	else if (ft_strchr(s, 'b') || ft_strchr(s, 'r'))
		return (which_instruction_b(a, b, s, bad_inst));
	else
		return (-1);
	return (0);
}

void	checker(t_stack **a, t_stack **b, char **s)
{
	int		ret;
	char	*tmp;
	bool	bad_inst;

	bad_inst = false;
	while (*s)
	{
		ret = which_instruction(a, b, *s, &bad_inst);
		if (ret == -1)
		{
			ft_putstr_fd("Error\n", 2);
			return ;
		}
		tmp = *s;
		free(tmp);
		*s = get_next_line(0);
	}
	if (check_if_sorted(*a) && !*b && !bad_inst)
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
}

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	*s;

	stack_a = init_splited_and_stack_a(ac, av);
	if (!stack_a)
		return (1);
	stack_b = NULL;
	s = get_next_line(0);
	checker(&stack_a, &stack_b, &s);
	free_all_checker(&stack_a, &stack_b, &s);
	return (0);
}
