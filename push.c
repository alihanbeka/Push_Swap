#include "Push_Swap.h"
#include <stdio.h>
#include <stdlib.h>

void    pb(s_node **a, s_node **b)
{
    s_node	*tmp;

	if (!a || !b || !*a)
		return ;

	tmp = *a;
	*a = (*a)->next;
	if (*a != NULL)
		(*a)->prev = NULL;

	tmp->next = *b;
	tmp->prev = NULL; 

	if (*b != NULL)
		(*b)->prev = tmp;

	*b = tmp;
	write(1, "pb\n", 3);
    
}

void pa(s_node **a, s_node **b)
{
    s_node *tmp;
  
    if(!a|| !b || !*b)
        return ;
         
    tmp = *b;
    *b = (*b)->next;
    if (*b != NULL)
		(*b)->prev = NULL;

    tmp->next = *a;
    tmp->prev=NULL;
    
    if(*a != NULL)
        (*a)->prev = tmp;

    *a = tmp;

    write(1, "pa\n", 3);
}

s_node *last_node(s_node *lst){
    
    if(!lst)
        return(NULL);

    while(lst->next !=NULL)
        lst=lst->next;
    
    return(lst);
}

void rb (s_node **b)
{
    // 3 1 2
    
    s_node *tmp;
    if(!b || !(*b) || (*b)->next = NULL)
        return ;

    tmp = *b;
    (*b) = (*b)->next;
    (*b)->prev = NULL;

    tmp->prev = last_node(*b);
    tmp->next = NULL;
    tmp->prev->next = tmp;
     write(1,"rb\n",3);

}
void ra (s_node **a)
{   
    s_node *tmp;

    if(!a || !*a || (*a)->next==NULL)
        return;
    tmp=*a;
    *a=(*a)->next;
    (*a)->prev=NULL;
    tmp->prev=last_node(*a);
    tmp->next=NULL;
    tmp->prev->next=tmp;
    write(1,"ra\n",3);
        
}  





















