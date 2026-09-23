/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masik <masik@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/11 23:32:21 by masik             #+#    #+#             */
/*   Updated: 2026/09/23 16:52:43 by masik            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_Swap.h"

void	pa(t_stack **a, t_stack **b, t_bench *bench)
{
	t_stack	*tmp;

	if (!a || !b || !(*b))
		return ;
	tmp = (*b);
	(*b) = (*b)->next;
	tmp->next = (*a);
	(*a) = tmp;
	write(1, "pa\n", 3);
	if (bench)
	{
		bench->pa++;
		bench->total++;
	}
}

void	pb(t_stack **a, t_stack **b, t_bench *bench)
{
	t_stack	*tmp;

	if (!a || !b || !(*a))
		return ;
	tmp = (*a);
	(*a) = (*a)->next;
	tmp->next = (*b);
	(*b) = tmp;
	write(1, "pb\n", 3);
	if (bench)
	{
		bench->pb++;
		bench->total++;
	}
}
