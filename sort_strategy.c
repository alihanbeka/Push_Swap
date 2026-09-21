/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_strategy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masik <masik@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/19 00:09:45 by masik             #+#    #+#             */
/*   Updated: 2026/09/20 15:21:54 by masik            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_Swap.h"

void	sort_stack(t_stack **a, t_stack **b, int flag, t_bench *bench)
{
	int		size;
	double	disorder;

	size = stack_size(*a);
	if (is_sorted(*a))
		return ;
	if (size == 2)
		sort_two(a, bench);
	else if (size == 3)
		sort_three(a, bench);
	else if (size <= 5)
		sort_four_five(a, b, bench);
	else
	{
		if (flag == 0)
		{
			disorder = compute_disorder(a);
			if (disorder < 0.20)
				sort_simple(a, b, bench);
			else if (disorder < 0.50)
				sort_medium(a, b, bench);
			else
				sort_complex(a, b, bench);
		}
		else if (flag == 1)
			sort_simple(a, b, bench);
		else if (flag == 2)
			sort_medium(a, b, bench);
		else if (flag == 3)
			sort_complex(a, b, bench);
	}
}
