/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masik <masik@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/13 14:57:09 by masik             #+#    #+#             */
/*   Updated: 2026/09/15 14:11:49 by masik            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_Swap.h"
#include "stdio.h"

int	main(int ac, char **av)
{
	t_stack	*lst;
	int		i;
	int		flag;
	int		val;

	flag = 0;
	lst = NULL;
	i = 1;
	if (ac < 2)
		return (0);
	if (ft_strncmp(av[i], "--", 2) == 0)
	{
		if (ft_strncmp(av[i], "--simple", 9) == 0)
			flag = 1;
		else if (ft_strncmp(av[i], "--medium", 9) == 0)
			flag = 2;
		else if (ft_strncmp(av[i], "--complex", 10) == 0)
			flag = 3;
		else if (ft_strncmp(av[i], "--adaptive", 11) == 0)
			flag = 0;
		else
		{
			write(2, "Error\n", 6);
			//
			return (1);
		}
		i++;
	}
	while (i < ac)
	{
		if (!ft_atoi_check(av[i], &val) || check_duplicate(lst, val))
		{
			write(2, "Error\n", 6);
			stack_clear(&lst);
			return (1);
		}
		stack_add_back(&lst, stack_new(val));
		i++;
	}
	index_assignment(lst);
	if (!lst)
		return (0);
	while (lst)
	{
		printf("Value: %d, Index: %d\n", lst->value, lst->index);
		lst = lst->next;
	}
}
