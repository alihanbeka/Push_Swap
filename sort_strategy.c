/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_strategy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masik <masik@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/19 00:09:45 by masik             #+#    #+#             */
/*   Updated: 2026/09/25 16:56:30 by masik            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_Swap.h"

#include "Push_Swap.h"

static void	sort_small(t_stack **a, t_stack **b, t_bench *bench)
{
	int	size;

	size = stack_size(*a);
	if (size == 2)
		sort_two(a, bench);
	else if (size == 3)
		sort_three(a, bench);
	else
		sort_four_five(a, b, bench);
}

static void	sort_adaptive(t_stack **a, t_stack **b, t_bench *bench)
{
	double	disorder;

	disorder = compute_disorder(a);
	if (disorder < 0.20)
		sort_simple(a, b, bench);
	else if (disorder < 0.50)
		sort_medium(a, b, bench);
	else
		sort_complex(a, b, bench);
}

void	sort_stack(t_stack **a, t_stack **b, int flag, t_bench *bench)
{
	if (!a || !*a || !b || is_sorted(*a))
		return ;
	if (stack_size(*a) <= 5)
	{
		sort_small(a, b, bench);
		return ;
	}
	if (flag == 0)
		sort_adaptive(a, b, bench);
	else if (flag == 1)
		sort_simple(a, b, bench);
	else if (flag == 2)
		sort_medium(a, b, bench);
	else if (flag == 3)
		sort_complex(a, b, bench);
}
