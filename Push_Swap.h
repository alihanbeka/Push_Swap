
#ifndef SWAP.H
#define SWAP.H


typedef struct swapdeneme
{ 
    int                 value;
	struct swapdeneme	*next;
	struct swapdeneme	*prev;
    
} s_node;

void    sa(s_node *a);
void    sb(s_node *a);
void	ss(s_node *a, s_node *b);
void	pb(s_node **a, s_node **b);
void	pa(s_node **a, s_node **b);
void    ra(s_node **a);
void    rb(s_node **b);
void	rr(s_node **a, s_node **b);



#endif
