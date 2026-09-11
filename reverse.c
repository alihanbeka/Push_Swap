#include "Push_Swap.h"

static int	reverse_rotate(t_stack **stack)
{
	t_stack	*before_last;
	t_stack	*last;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return (0);
	before_last = *stack;
	while (before_last->next->next != NULL)
		before_last = before_last->next;
	last = before_last->next;
	before_last->next = NULL;
	last->next = *stack;
	*stack = last;
	return (1);
}

void	rra(t_stack **a)
{
	if (reverse_rotate(a))
		write(1, "rra\n", 4);
}

void	rrb(t_stack **b)
{
	if (reverse_rotate(b))
		write(1, "rrb\n", 4);
}