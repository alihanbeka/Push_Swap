#include "Push_Swap.h"

int	check_duplicate(t_stack *stack, int value)
{
	t_stack	*tmp;

	tmp = stack;
	while (tmp)
	{
		if (tmp->value == value)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}