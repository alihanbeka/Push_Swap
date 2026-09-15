/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masik <masik@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/13 16:53:18 by masik             #+#    #+#             */
/*   Updated: 2026/09/15 15:44:35 by masik            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_Swap.h"

t_stack	*stack_new(int value)
{
	t_stack	*new_stack_node;

	new_stack_node = malloc(sizeof(t_stack));
	if (!new_stack_node)
		return (NULL);
	new_stack_node->value = value;
	new_stack_node->next = NULL;
	return (new_stack_node);
}

void	stack_add_back(t_stack **stack, t_stack *new_stack)
{
	t_stack	*last;

	if (!stack || !new_stack)
		return ;
	if (!(*stack))
	{
		*stack = new_stack;
		return ;
	}
	last = (*stack);
	while ((last)->next)
		last = (last)->next;
	(last)->next = new_stack;
}

int	stack_size(t_stack *stack)
{
	int	size;

	size = 0;
	while (stack != NULL)
	{
		size++;
		stack = stack->next;
	}
	return (size);
}
