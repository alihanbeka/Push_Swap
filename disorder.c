/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masik <masik@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/15 18:14:17 by masik             #+#    #+#             */
/*   Updated: 2026/09/15 18:40:08 by masik            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_Swap.h"

double	compute_disorder(t_stack **a)
{
	t_stack	*before;
	t_stack	*next;
	int		mistakes;
	int		total_pairs;

	if (!a || !(*a))
		return (0.0);
	mistakes = 0;
	total_pairs = 0;
	before = (*a);
	next = before->next;
	while (before->next != NULL)
	{
		next = before->next;
		while (next != NULL)
		{
			if (before->index > next->index)
				mistakes += 1;
			total_pairs += 1;
			next = next->next;
		}
		before = before->next;
	}
	if (total_pairs == 0)
		return (0.0);
	return ((double) mistakes / total_pairs);
}
