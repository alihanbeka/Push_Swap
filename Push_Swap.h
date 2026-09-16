/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   Push_Swap.h                                       :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: masik <masik@student.42istanbul.com.tr>   #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/09/10 17:41:29 by masik            #+#    #+#              */
/*   Updated: 2026/09/17 00:51:29 by masik           ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "Libft/libft.h"
# include <unistd.h>
# include <stdlib.h>

typedef struct s_stack
{
	int				index;
	int				value;
	struct s_stack	*next;
}	t_stack;

void	index_assignment(t_stack *stack);
void	sa(t_stack **a);
void	sb(t_stack **b);
void	ss(t_stack **a, t_stack **b);
void	pb(t_stack **a, t_stack **b);
void	pa(t_stack **a, t_stack **b);
void	ra(t_stack **a);
void	rb(t_stack **b);
void	rr(t_stack **a, t_stack **b);
void	rra(t_stack **a);
void	rrb(t_stack **b);
void	rrr(t_stack **a, t_stack **b);
void	stack_add_back(t_stack **stack, t_stack *new_stack);
t_stack	*stack_new(int value);
void	stack_clear(t_stack **stack);
int		ft_atoi_check(const char *str, int *out);
int		check_duplicate(t_stack *stack, int value);
int		parse_arguments(int ac, char **av, t_stack **a, int *flag);
int		stack_size(t_stack *stack);
int		is_sorted(t_stack *stack);
void	sort_simple(t_stack **a, t_stack **b);
void	basic_sort(t_stack **a, t_stack **b);
double	compute_disorder(t_stack **a);
#endif
