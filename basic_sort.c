/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masik <masik@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/15 14:53:52 by masik             #+#    #+#             */
/*   Updated: 2026/09/17 00:46:16 by masik            ###   ########.fr       */
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

static void	sort_four_five(t_stack **a, t_stack **b)
{
	int	target;

	target = 0;
	while (stack_size(*a) > 3)
	{
		while ((*a)->index != target)
			ra(a);
		pb(a, b);
		target++;
	}
	sort_three(a);
	while (*b != NULL)
		pa(a, b);
}

void	basit_sort(t_stack **a, t_stack **b)
{
	int	size;

	if (is_sorted(*a))
		return ;
	size = stack_size(*a);
	if (size == 2)
		sort_two(a);
	else if (size == 3)
		sort_three(a);
	else if (size == 4 || size == 5)
		sort_four_five(a, b);
}
