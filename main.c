/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masik <masik@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/13 14:57:09 by masik             #+#    #+#             */
/*   Updated: 2026/09/15 14:26:56 by masik            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_Swap.h"
#include <stdio.h>

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*tmp;
	int		flag;

	if (ac < 2)
		return (0);
	a = NULL;
	if (!parse_arguments(ac, av, &a, &flag))
	{
		stack_clear(&a);
		write(2, "Error\n", 6);
		return (1);
	}
	index_assignment(a);
	tmp = a;
	while (tmp != NULL)
	{
		printf("Value: %d, Index: %d\n", tmp->value, tmp->index);
		tmp = tmp->next;
	}
	stack_clear(&a);
	return (0);
}
