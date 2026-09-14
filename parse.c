/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masik <masik@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/13 14:57:09 by masik             #+#    #+#             */
/*   Updated: 2026/09/14 01:44:21 by masik            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_Swap.h"
#include "stdio.h"

int	main(int ac, char **av)
{
	t_stack	*lst;
	int		i;
	int		flag;

	lst = NULL;
	i = 1;
	if (ac < 2)
		return (0);
	if (ft_strncmp(av[i], "--", 2) == 0)
	{
		if (ft_strncmp(av[i], "--simple", 8) == 0);
			else if (ft_strncmp(av[i], "--medium", 8) == 0)
			else if (ft_strncmp(av[i], "--complex", 9) == 0)
			else if (ft_strncmp(av[i], "--adaptive", 10) == 0)
			i++;
	}
	while (i < ac)
	{
		stack_add_back(&lst, stack_new(ft_atoi(av[i])));
		i++;
	}
}
