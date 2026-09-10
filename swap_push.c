/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   swap_push.c                                       :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: masik <masik@student.42istanbul.com.tr>   #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/09/10 17:00:57 by masik            #+#    #+#              */
/*   Updated: 2026/09/11 01:25:47 by masik           ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "Push_Swap.h"

void	swap(t_stack **stack)
{
	t_stack	*tmp;

	if (!stack || !(*stack) || (*stack)->next == NULL)
		return ;
	tmp = (*stack);
	(*stack) = (*stack)->next;
	tmp->next = (*stack)->next;
	(*stack)->next = tmp;
}

void	sa(t_stack **a)
{
	t_stack	*tmp;

	if (!a || !(*a) || (*a)->next == NULL)
		return ;
	tmp = (*a)->next;
	(*a)->next = tmp->next;
	(tmp)->next = (*a);
	(*a) = tmp;
	write(1, "sa\n", 3);
}

void	sb(t_stack **b)
{
	t_stack	*tmp;

	if (!b || !(*b) || (*b)->next == NULL)
		return ;
	tmp = (*b)->next;
	(*b)->next = tmp->next;
	tmp->next = (*b);
	(*b) = tmp;
	write(1, "sb\n", 3);
}

void	ss(t_stack **a, t_stack **b)
{
	swap(a);
	swap(b);
	write(1, "ss\n", 3);
}

void	pa(t_stack **a, t_stack **b)
{
	t_stack	*tmp;

	if (!b || !(*b))
		return ;
	tmp = (*b);
	(*b) = (*b)->next;
	tmp->next = (*a);
	(*a) = tmp;
	write(1, "pa\n", 3);
}

void	pb(t_stack **a, t_stack **b)
{
	t_stack	*tmp;

	if (!a || (!*a))
		return ;
	tmp = (*a);
	(*a) = (*a)->next;
	tmp->next = (*b);
	(*b) = tmp;
	write(1, "pb\n", 3);
}
