/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_strategy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masik <masik@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/19 00:09:45 by masik             #+#    #+#             */
/*   Updated: 2026/09/21 16:44:31 by masik            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_Swap.h"

void	sort_stack(t_stack **a, t_stack **b, int flag, t_bench *bench)
{
	double	disorder;

	if (is_sorted(*a))
		return ;
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
