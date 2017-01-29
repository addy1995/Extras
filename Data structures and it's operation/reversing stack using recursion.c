#include<stdio.h>
#include<malloc.h>
struct stack
{
    int data;
    struct stack * link;
};
void push(struct stack ** stack ,int no)
{
    struct stack * n1=(struct stack *)malloc(sizeof(struct stack));
    n1->link=*stack;
    n1->data=no;
    *stack=n1;
}
int pop(struct stack ** stack)
{
    int var=(*stack)->data;
    struct stack * temp=*stack;
    *stack=(*stack)->link;
    free(temp);
    return var;
}

int isempty(struct stack *stack)
{
    return !stack;
}
void insertatbottom(struct stack ** stack,int no)
{
    int var;
    if(isempty(*stack)==1)
    {   push(stack,no);
        return;
    }
    else
    {
        var=pop(stack);
        insertatbottom(stack,no);
    }
    push(stack,var);
}
void reverse(struct stack ** stack)
{
    int var;
    if(isempty(*stack)==1)
    {
        return;
    }
    else
    {
    //    printf("s");
        var=pop(stack);
        reverse(stack);
    }
    insertatbottom(stack,var);
}
void print(struct stack * temp)
{
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->link;
    }

}
int main()
{
    struct stack * stack=NULL;
    int i=0;
    for(i=0;i<5;i++)
    {
        push(&stack,i*i);
    }
    printf("stack before reverion : ");
    print(stack);
    reverse(&stack);
    printf("\nstack after reverion : ");
    print(stack);

}
