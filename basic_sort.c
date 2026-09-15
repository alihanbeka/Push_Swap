/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masik <masik@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/15 14:53:52 by masik             #+#    #+#             */
/*   Updated: 2026/09/15 18:07:33 by masik            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_Swap.h"

static void	sort_two(t_stack **a)
{
	if ((*a)->index > (*a)->next->index)
		sa(a);
}

static void	sort_three(t_stack **a)
{
	int	first;
	int	second;
	int	third;

	first = (*a)->index;
	second = (*a)->next->index;
	third = (*a)->next->next->index;
	if (first > second && first > third)
		ra(a);
	else if (second > first && second > third)
		rra(a);
	if ((*a)->index > (*a)->next->index)
		sa(a);
}

void	sort_five(t_stack **a, t_stack **b)
{
	while (stack_size(*a) > 3)
	{
		while ((*a)->index != 0 && (*a)->index != 1)
			ra(a);
		pb(a, b);
	}
	sort_three(a);
	if (stack_size(*b) == 2 && (*b)->index < (*b)->next->index)
		sb(b);
	while (*b != NULL)
		pa(a, b);
}
