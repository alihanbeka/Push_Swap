/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masik <masik@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/15 14:27:50 by masik             #+#    #+#             */
/*   Updated: 2026/09/21 17:39:11 by masik            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_Swap.h"

static int	set_flag(char *arg, int *flag, t_bench *bench)
{
	if (ft_strncmp(arg, "--bench", 8) == 0)
	{
		if (bench->is_bench)
			return (0);
		bench->is_bench = 1;
		return (1);
	}
	if (*flag != -1)
		return (0);
	if (ft_strncmp(arg, "--simple", 9) == 0)
		*flag = 1;
	else if (ft_strncmp(arg, "--medium", 9) == 0)
		*flag = 2;
	else if (ft_strncmp(arg, "--complex", 10) == 0)
		*flag = 3;
	else if (ft_strncmp(arg, "--adaptive", 11) == 0)
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

static void	free_tokens(char **tokens, int start)
{
	if (!tokens)
		return ;
	while (tokens[start])
	{
		free(tokens[start]);
		start++;
	}
	free(tokens);
}

static int	parse_split_arg(t_stack **a, char *arg)
{
	char	**tokens;
	int		j;

	tokens = ft_split(arg, ' ');
	if (!tokens || !tokens[0])
	{
		free_tokens(tokens, 0);
		return (0);
	}
	j = 0;
	while (tokens[j])
	{
		if (!add_number(a, tokens[j]))
		{
			free_tokens(tokens, j);
			return (0);
		}
		free(tokens[j]);
		j++;
	}
	free(tokens);
	return (1);
}

int	parse_arguments(char **av, t_stack **a, int *flag, t_bench *bench)
{
	int	i;

	i = 1;
	*flag = -1;
	while (av[i] && ft_strncmp(av[i], "--", 2) == 0)
	{
		if (!set_flag(av[i], flag, bench))
			return (0);
		i++;
	}
	if (*flag == -1)
		*flag = 0;
	if (!av[i])
		return (0);
	while (av[i])
	{
		if (!parse_split_arg(a, av[i]))
			return (0);
		i++;
	}
	return (1);
}
