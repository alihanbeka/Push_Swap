#include "Push_Swap.h"
#include <stdio.h>
#include <stdlib.h>

void	sa(s_node *a)
{
	int	tmp;

	if (a == NULL || a->next == NULL)
		return ;
	tmp = a->value;
	a->value = a->next->value;
	a->next->value = tmp;
}

void    sb(s_node *b){
    int tmp;
    
    if(b==NULL || b->next ==NULL)
        return;

    tmp=b->value;
    b->value=b->next->value;
    b->next->value=tmp;
}

void    ss(s_node *a, s_node *b)
 {
    sa(a);
    sb(b);

} 


int	main(void)
{
	s_node	*a;
	s_node	*b;
	s_node	*c;
	s_node	*tmp;

	a = malloc(sizeof(s_node));
	b = malloc(sizeof(s_node));
	c = malloc(sizeof(s_node));
	if (a == NULL || b == NULL || c == NULL)
	{
		free(a);
		free(b);
		free(c);
		return (1);
	}
	a->value = 3;
	b->value = 1;
	c->value = 2;

	a->prev = NULL;
	a->next = b;
	b->prev = a;
	b->next = c;
	c->prev = b;
	c->next = NULL;

	sa(a);
	tmp = a;
	while (tmp != NULL)
	{
		printf("%d\n", tmp->value);
		tmp = tmp->next;
	}
	free(a);
	free(b);
	free(c);
	return (0);
}