/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   rotate.c                                          :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: masik <masik@student.42istanbul.com.tr>   #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/09/10 23:23:07 by masik            #+#    #+#              */
/*   Updated: 2026/09/12 16:04:35 by masik           ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "Push_Swap.h"

static t_stack	*lastnode(t_stack *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

static int	rotate(t_stack **stack)
{
	t_stack	*tmp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return (0);
	tmp = *stack;
	*stack = (*stack)->next;
	tmp->next = NULL;
	lastnode(*stack)->next = tmp;
	return (1);
}

void	ra(t_stack **a)
{
	if (rotate(a))
		write(1, "ra\n", 3);
}

void	rb(t_stack **b)
{
	if (rotate(b))
		write(1, "rb\n", 3);
}

void	rr(t_stack **a, t_stack **b)
{
	int	r_a;
	int	r_b;

	r_a = rotate(a);
	r_b = rotate(b);
	if (r_a || r_b)
		write(1, "rr\n", 3);
}
