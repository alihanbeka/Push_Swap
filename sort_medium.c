/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_medium.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masik <masik@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/18 11:24:32 by masik             #+#    #+#             */
/*   Updated: 2026/09/18 12:35:39 by masik            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_Swap.h"

static int	ft_sqrt(int number)
{
	int	i;

	if (number <= 0)
		return (0);
	i = 1;
	while (i * i <= number)
		i++;
	return (i - 1);
}

static int	get_max_pos(t_stack *b, int max_index)
{
	int	pos;

	pos = 0;
	while (b != NULL)
	{
		if (b->index == max_index)
			return (pos);
		pos++;
		b = b->next;
	}
	return (pos);
}

static void	push_back_to_a(t_stack **a, t_stack **b)
{
	int	max_idx;
	int	pos;
	int	size;

	while (*b != NULL)
	{
		size = stack_size(*b);
		max_idx = size - 1;
		pos = get_max_pos(*b, max_idx);
		if (pos <= size / 2)
		{
			while ((*b)->index != max_idx)
				rb(b);
		}
		else
		{
			while ((*b)->index != max_idx)
				rrb(b);
		}
		pa(a, b);
	}
}

void	sort_medium(t_stack **a, t_stack **b)
{
	int	chunk_size;
	int	i;

	if (!a || !*a || is_sorted(*a))
		return ;
	chunk_size = ft_sqrt(stack_size(*a));
	i = 0;
	while (*a != NULL)
	{
		if ((*a)->index <= i)
		{
			pb(a, b);
			rb(b);
			i++;
		}
		else if ((*a)->index <= i + chunk_size)
		{
			pb(a, b);
			i++;
		}
		else
			ra(a);
	}
	push_back_to_a(a, b);
}
