/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masik <masik@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/20 16:30:00 by masik             #+#    #+#             */
/*   Updated: 2026/09/21 14:42:48 by masik            ###   ########.fr       */
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

static void	write_number(int n)
{
	char	c;

	if (n >= 10)
		write_number(n / 10);
	c = (n % 10) + '0';
	write(2, &c, 1);
}

static void	print_strategy(int flag, double disorder)
{
	if (flag == 1)
		write(2, "[bench] strategy:\tSimple / O(n^2)\n", 34);
	else if (flag == 2)
		write(2, "[bench] strategy:\tMedium / O(n\\sqrt{n})\n", 38);
	else if (flag == 3)
		write(2, "[bench] strategy:\tComplex / O(n log n)\n", 37);
	else if (flag == 0)
	{
		if (disorder < 0.20)
			write(2, "[bench] strategy:\tAdaptive / O(n^2)\n", 36);
		else if (disorder < 0.50)
			write(2, "[bench] strategy:\tAdaptive / O(n\\sqrt{n})\n", 40);
		else
			write(2, "[bench] strategy:\tAdaptive / O(n log n)\n", 39);
	}
}

static void	print_ops_details(t_bench *b)
{
	write(2, "\n[bench] sa:\t", 13);
	write_number(b->sa);
	write(2, "\tsb:\t", 5);
	write_number(b->sb);
	write(2, "\tss:\t", 5);
	write_number(b->ss);
	write(2, "\tpa:\t", 5);
	write_number(b->pa);
	write(2, "\tpb:\t", 5);
	write_number(b->pb);
	write(2, "\n[bench] ra:\t", 13);
	write_number(b->ra);
	write(2, "\trb:\t", 5);
	write_number(b->rb);
	write(2, "\trr:\t", 5);
	write_number(b->rr);
	write(2, "\n[bench] rra:\t", 14);
	write_number(b->rra);
	write(2, "\trrb:\t", 5);
	write_number(b->rrb);
	write(2, "\trrr:\t", 5);
	write_number(b->rrr);
	write(2, "\n", 1);
}

void	print_bench(t_bench *b, double disorder, int flag)
{
	if (!b || !b->is_bench)
		return ;
	write(2, "[bench] disorder:\t", 18);
	write_number((int)(disorder * 100));
	write(2, ".", 1);
	if ((int)(disorder * 10000) % 100 < 10)
		write(2, "0", 1);
	write_number((int)(disorder * 10000) % 100);
	write(2, "%\n", 2);
	print_strategy(flag, disorder);
	write(2, "[bench] total_ops:\t", 19);
	write_number(b->total);
	print_ops_details(b);
}
