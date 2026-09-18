/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_simple.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masik <masik@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/15 20:45:40 by masik             #+#    #+#             */
/*   Updated: 2026/09/18 10:54:35 by masik            ###   ########.fr       */
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

void	sort_simple(t_stack **a, t_stack **b)
{
	int	target;
	int	pos;
	int	size;

	if (!a || !*a || !b || is_sorted(*a))
		return ;
	target = 0;
	while (*a != NULL)
	{
		size = stack_size(*a);
		pos = get_target_position(*a, target);
		if (pos <= size / 2)
		{
			while ((*a)->index != target)
				ra(a);
		}
		else
		{
			while ((*a)->index != target)
				rra(a);
		}
		pb(a, b);
		target++;
	}
	while (*b != NULL)
		pa(a, b);
}
