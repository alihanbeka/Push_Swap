/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_complex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masik <masik@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/18 16:17:34 by masik             #+#    #+#             */
/*   Updated: 2026/09/20 15:17:26 by masik            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_Swap.h"

static int	max_index_bit(t_stack **a)
{
	int	max_index;
	int	max_bits;

	max_index = stack_size(*a) - 1;
	max_bits = 0;
	while ((max_index >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}

void	sort_complex(t_stack **a, t_stack **b, t_bench *bench)
{
	int	max_bit;
	int	i;
	int	j;
	int	size;

	size = stack_size(*a);
	max_bit = max_index_bit(a);
	i = 0;
	while (i < max_bit)
	{
		j = 0;
		while (j < size)
		{
			if (((*a)->index >> i) & 1)
				ra(a, bench);
			else
				pb(a, b, bench);
			j++;
		}
		while ((*b) != NULL)
			pa(a, b, bench);
		i++;
	}
}
