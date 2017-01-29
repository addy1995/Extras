#include<stdio.h>
#include<malloc.h>
struct node
{
    int data;
    struct node * link;
};
struct node * createstack(int data)
{
    struct node * n1=(struct node *)malloc(sizeof(struct node));
    n1->link=NULL;
    n1->data=data;

}

void push(struct node ** stack,int data)
{
    struct node * n1=(struct node *)malloc(sizeof(struct node));
    n1->link=*stack;
    n1->data=data;
    *stack=n1;

}
int isempty(struct node * stack)
{
    return !stack;
}
int pop(struct node **stack)
{
    if(isempty(*stack)==1)
    {
        printf("stack is empty");
        return;
    }
    int var=(*stack)->data;
    *stack=(*stack)->link;
    return var;
}
int peek(struct node * stack)
{
    if(isempty(stack)==1)
    {
        printf("stack is empty");
        return;
    }

    return (stack)->data;
}
int main()
{
        struct node * stack=(createstack(34));
        push(&stack,7);
        printf("poping element %d\n",pop(&stack));
        printf("%d",peek(stack));
}
