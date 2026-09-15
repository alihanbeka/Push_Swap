/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index_assignment.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masik <masik@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/15 14:09:50 by masik             #+#    #+#             */
/*   Updated: 2026/09/15 14:09:54 by masik            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_Swap.h"

void	index_assignment(t_stack *stack)
{
	t_stack	*current;
	t_stack	*compare;
	int		index;

	current = stack;
	while (current != NULL)
	{
		index = 0;
		compare = stack;
		while (compare != NULL)
		{
			if (current->value > compare->value)
				index++;
			compare = compare->next;
		}
		current->index = index;
		current = current->next;
	}
}
