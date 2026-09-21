/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   Push_Swap.h                                       :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: masik <masik@student.42istanbul.com.tr>   #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/09/10 17:41:29 by masik            #+#    #+#              */
/*   Updated: 2026/09/21 18:14:38 by masik           ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"

typedef struct s_stack
{
	int				index;
	int				value;
	struct s_stack	*next;
}	t_stack;

typedef struct s_bench
{
	int	sa;
	int	sb;
	int	ss;
	int	pa;
	int	pb;
	int	ra;
	int	rb;
	int	rr;
	int	rra;
	int	rrb;
	int	rrr;
	int	total;
	int	is_bench;
}	t_bench;

void	sa(t_stack **a, t_bench *bench);
void	sb(t_stack **b, t_bench *bench);
void	ss(t_stack **a, t_stack **b, t_bench *bench);
void	pa(t_stack **a, t_stack **b, t_bench *bench);
void	pb(t_stack **a, t_stack **b, t_bench *bench);
void	ra(t_stack **a, t_bench *bench);
void	rb(t_stack **b, t_bench *bench);
void	rr(t_stack **a, t_stack **b, t_bench *bench);
void	rra(t_stack **a, t_bench *bench);
void	rrb(t_stack **b, t_bench *bench);
void	rrr(t_stack **a, t_stack **b, t_bench *bench);
void	stack_add_back(t_stack **stack, t_stack *new_stack);
t_stack	*stack_new(int value);
void	stack_clear(t_stack **stack);
int		ft_atoi_check(const char *str, int *out);
int		check_duplicate(t_stack *stack, int value);
int		parse_arguments(char **av, t_stack **a, int *flag, t_bench *bench);
int		stack_size(t_stack *stack);
int		is_sorted(t_stack *stack);
void	index_assignment(t_stack *stack);
double	compute_disorder(t_stack **a);
void	sort_simple(t_stack **a, t_stack **b, t_bench *bench);
void	sort_medium(t_stack **a, t_stack **b, t_bench *bench);
void	sort_complex(t_stack **a, t_stack **b, t_bench *bench);
void	sort_stack(t_stack **a, t_stack **b, int flag, t_bench *bench);
void	init_bench(t_bench *bench);
void	print_bench(t_bench *bench, double disorder, int flag);

#endif
