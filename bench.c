/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masik <masik@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/20 16:30:00 by masik             #+#    #+#             */
/*   Updated: 2026/09/21 18:13:17 by masik            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_Swap.h"

void	init_bench(t_bench *bench)
{
	bench->sa = 0;
	bench->sb = 0;
	bench->ss = 0;
	bench->pa = 0;
	bench->pb = 0;
	bench->ra = 0;
	bench->rb = 0;
	bench->rr = 0;
	bench->rra = 0;
	bench->rrb = 0;
	bench->rrr = 0;
	bench->total = 0;
	bench->is_bench = 0;
}

static void	print_strategy(int flag, double disorder)
{
	if (flag == 1)
		ft_putstr_fd("[bench] strategy:\tSimple / O(n^2)\n", 2);
	else if (flag == 2)
		ft_putstr_fd("[bench] strategy:\tMedium / O(n sqrt(n))\n", 2);
	else if (flag == 3)
		ft_putstr_fd("[bench] strategy:\tComplex / O(n log n)\n", 2);
	else if (flag == 0)
	{
		if (disorder < 0.20)
			ft_putstr_fd("[bench] strategy:\tAdaptive / O(n^2)\n", 2);
		else if (disorder < 0.50)
			ft_putstr_fd("[bench] strategy:\tAdaptive / O(n sqrt(n))\n", 2);
		else
			ft_putstr_fd("[bench] strategy:\tAdaptive / O(n log n)\n", 2);
	}
}

static void	print_basic_ops(t_bench *bench)
{
	ft_putstr_fd("[bench] sa:\t", 2);
	ft_putnbr_fd(bench->sa, 2);
	ft_putstr_fd("\tsb:\t", 2);
	ft_putnbr_fd(bench->sb, 2);
	ft_putstr_fd("\tss:\t", 2);
	ft_putnbr_fd(bench->ss, 2);
	ft_putstr_fd("\tpa:\t", 2);
	ft_putnbr_fd(bench->pa, 2);
	ft_putstr_fd("\tpb:\t", 2);
	ft_putnbr_fd(bench->pb, 2);
	ft_putstr_fd("\n", 2);
}

static void	print_rotate_ops(t_bench *bench)
{
	ft_putstr_fd("[bench] ra:\t", 2);
	ft_putnbr_fd(bench->ra, 2);
	ft_putstr_fd("\trb:\t", 2);
	ft_putnbr_fd(bench->rb, 2);
	ft_putstr_fd("\trr:\t", 2);
	ft_putnbr_fd(bench->rr, 2);
	ft_putstr_fd("\n[bench] rra:\t", 2);
	ft_putnbr_fd(bench->rra, 2);
	ft_putstr_fd("\trrb:\t", 2);
	ft_putnbr_fd(bench->rrb, 2);
	ft_putstr_fd("\trrr:\t", 2);
	ft_putnbr_fd(bench->rrr, 2);
	ft_putstr_fd("\n", 2);
}

void	print_bench(t_bench *bench, double disorder, int flag)
{
	int	percentage;

	if (!bench || !bench->is_bench)
		return ;
	percentage = (int)(disorder * 10000 + 0.5);
	ft_putstr_fd("[bench] disorder:\t", 2);
	ft_putnbr_fd(percentage / 100, 2);
	ft_putstr_fd(".", 2);
	if (percentage % 100 < 10)
		ft_putstr_fd("0", 2);
	ft_putnbr_fd(percentage % 100, 2);
	ft_putstr_fd("%\n", 2);
	print_strategy(flag, disorder);
	ft_putstr_fd("[bench] total_ops:\t", 2);
	ft_putnbr_fd(bench->total, 2);
	ft_putstr_fd("\n", 2);
	print_basic_ops(bench);
	print_rotate_ops(bench);
}
