/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masik <masik@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/13 14:57:09 by masik             #+#    #+#             */
/*   Updated: 2026/09/21 14:43:54 by masik            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_Swap.h"

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	t_bench	bench;
	int		flag;
	double	disorder;

	if (ac < 2)
		return (0);
	a = NULL;
	b = NULL;
	init_bench(&bench);
	if (!parse_arguments(av, &a, &flag, &bench))
	{
		stack_clear(&a);
		write(2, "Error\n", 6);
		return (1);
	}
	index_assignment(a);
	disorder = compute_disorder(&a);
	sort_stack(&a, &b, flag, &bench);
	print_bench(&bench, disorder, flag);
	stack_clear(&a);
	stack_clear(&b);
	return (0);
}
