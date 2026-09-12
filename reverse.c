/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   reverse.c                                         :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: masik <masik@student.42istanbul.com.tr>   #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/09/12 15:38:14 by masik            #+#    #+#              */
/*   Updated: 2026/09/12 16:00:40 by masik           ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "Push_Swap.h"

static int	reverse_rotate(t_stack **stack)
{
	t_stack	*before_last;
	t_stack	*last;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return (0);
	before_last = *stack;
	while (before_last->next->next != NULL)
		before_last = before_last->next;
	last = before_last->next;
	before_last->next = NULL;
	last->next = *stack;
	*stack = last;
	return (1);
}

void	rra(t_stack **a)
{
	if (reverse_rotate(a))
		write(1, "rra\n", 4);
}

void	rrb(t_stack **b)
{
	if (reverse_rotate(b))
		write(1, "rrb\n", 4);
}

void	rrr(t_stack **a, t_stack **b)
{
	int	rr_a;
	int	rr_b;

	rr_a = reverse_rotate(a);
	rr_b = reverse_rotate(b);
	if (rr_a || rr_b)
		write(1, "rrr\n", 4);
}
