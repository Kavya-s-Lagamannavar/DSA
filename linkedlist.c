#include<stdio.h>

void display()
{
    int i;
    struct node *ptr;
    ptr=head;
    if(ptr==NULL)
    {
        printf("Stack is empty\n");
    }
    else
    {
        printf("Printing Stack elements \n");
        while(ptr!=NULL)
        {
            printf("%d\n",ptr->val);
            ptr = ptr->next;
        }
    }
}
