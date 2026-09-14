#include "push_swap.h"

void	stack_clear(t_stack **stack)
{
	t_stack	*next;

	if (stack == NULL)
		return ;
	while (*stack != NULL)
	{
		next = (*stack)->next;
		free(*stack);
		*stack = next;
	}
}