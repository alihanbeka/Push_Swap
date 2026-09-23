/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_simple.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masik <masik@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/15 20:45:40 by masik             #+#    #+#             */
/*   Updated: 2026/09/23 17:20:06 by masik            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_Swap.h"

static int	get_target_position(t_stack *a, int target)
{
	int	pos;

	pos = 0;
	while (a != NULL)
	{
		if (a->index == target)
			return (pos);
		pos++;
		a = a->next;
	}
	return (pos);
}

void	sort_simple(t_stack **a, t_stack **b, t_bench *bench)
{
	int	target;
	int	size;

	if (!a || !*a || !b || is_sorted(*a))
		return ;
	target = 0;
	while (*a != NULL)
	{
		size = stack_size(*a);
		if (get_target_position(*a, target) <= size / 2)
		{
			while ((*a)->index != target)
				ra(a, bench);
		}
		else
		{
			while ((*a)->index != target)
				rra(a, bench);
		}
		pb(a, b, bench);
		target++;
	}
	while (*b != NULL)
		pa(a, b, bench);
}
