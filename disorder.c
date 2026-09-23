/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masik <masik@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/15 18:14:17 by masik             #+#    #+#             */
/*   Updated: 2026/09/23 17:37:43 by masik            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_Swap.h"

double	compute_disorder(t_stack **a)
{
	t_stack	*curr;
	t_stack	*next;
	int		mistakes;
	int		total;

	if (!a || !*a || !(*a)->next)
		return (0.0);
	mistakes = 0;
	total = 0;
	curr = *a;
	while (curr != NULL)
	{
		next = curr->next;
		while (next != NULL)
		{
			if (curr->index > next->index)
				mistakes++;
			total++;
			next = next->next;
		}
		curr = curr->next;
	}
	return ((double) mistakes / total);
}
