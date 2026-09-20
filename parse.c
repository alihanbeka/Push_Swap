/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masik <masik@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/15 14:27:50 by masik             #+#    #+#             */
/*   Updated: 2026/09/20 14:09:09 by masik            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masik <masik@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/15 14:27:50 by masik             #+#    #+#             */
/*   Updated: 2026/09/20 14:00:00 by masik            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_Swap.h"

static int	set_flag(char *argument, int *flag)
{
	if (ft_strncmp(argument, "--simple", 9) == 0)
		*flag = 1;
	else if (ft_strncmp(argument, "--medium", 9) == 0)
		*flag = 2;
	else if (ft_strncmp(argument, "--complex", 10) == 0)
		*flag = 3;
	else if (ft_strncmp(argument, "--adaptive", 11) == 0)
		*flag = 0;
	else
		return (0);
	return (1);
}

static int	add_number(t_stack **a, char *argument)
{
	t_stack	*new;
	int		value;

	if (!ft_atoi_check(argument, &value))
		return (0);
	if (check_duplicate(*a, value))
		return (0);
	new = stack_new(value);
	if (new == NULL)
		return (0);
	stack_add_back(a, new);
	return (1);
}

static int	parse_split_arg(t_stack **a, char *arg)
{
	char	**tokens;
	int		j;

	tokens = ft_split(arg, ' ');
	if (!tokens || !tokens[0])
	{
		if (tokens)
			free(tokens);
		return (0);
	}
	j = 0;
	while (tokens[j])
	{
		if (!add_number(a, tokens[j]))
		{
			while (tokens[j])
				free(tokens[j++]);
			free(tokens);
			return (0);
		}
		free(tokens[j]);
		j++;
	}
	free(tokens);
	return (1);
}

int	parse_arguments(int ac, char **av, t_stack **a, int *flag)
{
	int	i;

	i = 1;
	*flag = 0;
	if (i < ac && ft_strncmp(av[i], "--", 2) == 0)
	{
		if (!set_flag(av[i], flag))
			return (0);
		i++;
	}
	if (i >= ac)
		return (0);
	while (i < ac)
	{
		if (!parse_split_arg(a, av[i]))
			return (0);
		i++;
	}
	return (1);
}
