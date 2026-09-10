/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   rotate.c                                          :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: masik <masik@student.42istanbul.com.tr>   #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/09/10 23:23:07 by masik            #+#    #+#              */
/*   Updated: 2026/09/11 01:05:15 by masik           ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "Push_Swap.h"

static void	rotate(t_stack **stack)
{
	t_stack	*tmp;

	if (!stack || !(*stack) || (*stack)->next == NULL)
		return ;
	tmp = (*stack);
	(*stack) = (*stack)->next;
	lastnode(*stack)->next = tmp;
	tmp->next = NULL;
}

static t_stack	*lastnode(t_stack *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	ra(t_stack **a)
{
	rotate(a);
	write(1, "ra\n", 3);
}

void	rb(t_stack **b)
{
	rotate(b);
	write(1, "rb\n", 3);
}

void	rr(t_stack **a, t_stack **b)
{
	rotate(a);
	rotate(b);
	write(1, "rr\n", 3);
}
