#include "Push_Swap.h"
#include <stdio.h>

void sa(s_node *a){
    s_node *tmp;
    tmp = a;
    a=a->next;
    a->next=tmp;
}

int main()
{

s_node *a;
s_node *b;
s_node *c;
a->value = 3;
b->value= 1;

a->next = b;
b->next = c;
c->next = NULL;

s_node *tmp;
tmp=a;
sa(a);
while(tmp){
printf("%d",tmp->value);
tmp=tmp->next;
}



}