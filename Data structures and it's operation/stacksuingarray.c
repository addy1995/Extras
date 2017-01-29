#include<stdio.h>
#include<malloc.h>
struct stack
{
    int top;
    unsigned capacity;
    int * array;

};
struct stack * createstack(unsigned capacity)
{
    struct stack * stack=(struct stack *)malloc(sizeof(struct stack));
    stack->top=-1;
    stack->capacity=capacity;
    stack->array=(int *)malloc(sizeof(int)*capacity);

}
int isfull(struct stack * stack)
{
    return (stack->top==stack->capacity-1);
}
void push(struct stack * stack,int no)
{
    if(isfull(stack)==1)
    {
        printf("stack is full");
        return;
    }
    (stack)->array[++(stack->top)]=no;

}
int isempty(struct stack * stack)
{
    return (stack->top==-1);

}
void pop(struct stack * stack)
{
    if(isempty(stack)==1)
    {
        printf("stack is empty");
        return;
    }
    printf("poping element %d",(stack)->array[(stack)->top--]);
}
int peek(struct stack * stack)
{
    if(isempty(stack)==1)
    {
        printf("stack is empty");
        return;
    }
    return stack->array[stack->top];
}
int main()
{
    struct stack * stack=createstack(10);
    printf("pushing element 10\n");
    push(stack,10);
    printf("pushing element 20\n");
    push(stack,20);
    printf("pushing element 30\n");
    push(stack,30);
    pop(stack);
    printf("\npeeking element %d",peek(stack));
}
