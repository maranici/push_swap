/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macuesta <macuesta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 17:29:50 by macuesta          #+#    #+#             */
/*   Updated: 2024/12/09 17:03:58 by macuesta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include "ft_printf.h"
# include <limits.h>
# include <stdbool.h>

typedef struct s_stack
{
	int				n;
	int				index;
	int				nb_ops;
	bool			is_cheapest;
	bool			above_median;
	struct s_stack	*target;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

// push_swap
void	push_swap(t_stack **stack_a, t_stack **stack_b);

// algo/
bool	check_if_sorted(t_stack *stack);

void	algo_two_nums(t_stack **stack_a);
void	algo_three_nums(t_stack **stack_a);
void	algo_more_nums(t_stack **stack_a, t_stack **stack_b);
void	set_node_index(t_stack *stack);
void	target_node_a(t_stack *stack_a, t_stack *stack_b);
void	target_node_b(t_stack *stack_a, t_stack *stack_b);
void	init_stack_a(t_stack *stack_a, t_stack *stack_b);
void	ops_calcul(t_stack *s_a, t_stack *s_b);
void	push_a_to_b(t_stack **stack_a, t_stack **stack_b);
void	push_b_to_a(t_stack **stack_a, t_stack **stack_b);
void	reorder_stacks(t_stack **stack, t_stack *top_node, char name);
void	order_a(t_stack **stack_a);

// utils/
int		check_errors(char **splited);

t_stack	*find_max(t_stack *stack_a);
t_stack	*find_min(t_stack *stack);
t_stack	*create_stack_a(char **splited, bool do_we_free);
t_stack	*ft_stacklast(t_stack *stack);
t_stack	*create_node_a(int n);
t_stack	*get_cheapest(t_stack *stack);

int		stack_len(t_stack *stack);

void	ft_free_stack(t_stack **stack);
void	ft_free_splited(char **splited, bool do_we_free);
void	ft_stackadd_back(t_stack **stack, t_stack *new);
void	define_cheapest(t_stack *stack);

// moves/
void	push(t_stack **dst, t_stack **src);
void	pa(t_stack **a, t_stack **b, bool print);
void	pb(t_stack **b, t_stack **a, bool print);

void	rotate(t_stack **stack);
void	ra(t_stack **a, bool print);
void	rb(t_stack **b, bool print);
void	rr(t_stack **a, t_stack **b, bool print);

void	reverse_rotate(t_stack **stack);
void	rra(t_stack **a, bool print);
void	rrb(t_stack **b, bool print);
void	rrr(t_stack **a, t_stack **b, bool print);

void	swap(t_stack **stack);
void	sa(t_stack **a, bool print);
void	sb(t_stack **b, bool print);
void	ss(t_stack **a, t_stack **b, bool print);

// BONUS
bool	is_endl(char c);
int		which_instruction_b(t_stack **a, t_stack **b, char *s, bool *bad_inst);
int		which_instruction(t_stack **a, t_stack **b, char *s, bool *bad_inst);
void	checker(t_stack **a, t_stack **b, char **s);

t_stack	*init_splited_and_stack_a(int ac, char **av);
void	free_all_checker(t_stack **a, t_stack **b, char **s);

#endif // !PUSH_SWAP_H
