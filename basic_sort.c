/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masik <masik@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/25 15:59:34 by masik             #+#    #+#             */
/*   Updated: 2026/09/25 16:01:24 by masik            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_Swap.h"

static int	get_target_position(t_stack *a, int target)
{
	int	pos;

	pos = 0;
	while (a != NULL && a->index != target)
	{
		pos++;
		a = a->next;
	}
	return (pos);
}

static void	bring_target(t_stack **a, int target, t_bench *bench)
{
	int	pos;
	int	size;

	size = stack_size(*a);
	pos = get_target_position(*a, target);
	while ((*a)->index != target)
	{
		if (pos <= size / 2)
			ra(a, bench);
		else
			rra(a, bench);
	}
}

void	sort_two(t_stack **a, t_bench *bench)
{
	if ((*a)->index > (*a)->next->index)
		sa(a, bench);
}

void	sort_three(t_stack **a, t_bench *bench)
{
	int	first;
	int	second;
	int	third;

	first = (*a)->index;
	second = (*a)->next->index;
	third = (*a)->next->next->index;
	if (first > second && first > third)
		ra(a, bench);
	else if (second > first && second > third)
		rra(a, bench);
	if ((*a)->index > (*a)->next->index)
		sa(a, bench);
}

void	sort_four_five(t_stack **a, t_stack **b, t_bench *bench)
{
	int	target;

	target = 0;
	while (stack_size(*a) > 3)
	{
		bring_target(a, target, bench);
		pb(a, b, bench);
		target++;
	}
	sort_three(a, bench);
	while (*b != NULL)
		pa(a, b, bench);
}
