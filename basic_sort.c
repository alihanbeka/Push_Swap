/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masik <masik@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/15 14:53:52 by masik             #+#    #+#             */
/*   Updated: 2026/09/20 15:19:07 by masik            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_Swap.h"

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
		while ((*a)->index != target)
			ra(a, bench);
		pb(a, b, bench);
		target++;
	}
	sort_three(a, bench);
	while (*b != NULL)
		pa(a, b, bench);
}
