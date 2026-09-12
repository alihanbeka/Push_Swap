/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   swap.c                                            :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: masik <masik@student.42istanbul.com.tr>   #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/09/10 17:00:57 by masik            #+#    #+#              */
/*   Updated: 2026/09/12 16:05:14 by masik           ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "Push_Swap.h"

static int	swap(t_stack **stack)
{
	t_stack	*tmp;

	if (!stack || !(*stack) || (*stack)->next == NULL)
		return (0);
	tmp = (*stack);
	(*stack) = (*stack)->next;
	tmp->next = (*stack)->next;
	(*stack)->next = tmp;
	return (1);
}

void	sa(t_stack **a)
{
	if (swap(a))
		write(1, "sa\n", 3);
}

void	sb(t_stack **b)
{
	if (swap(b))
		write(1, "sb\n", 3);
}

void	ss(t_stack **a, t_stack **b)
{
	int	s_a;
	int	s_b;

	s_a = swap(a);
	s_b = swap(b);
	if (s_a || s_b)
		write(1, "ss\n", 3);
}
