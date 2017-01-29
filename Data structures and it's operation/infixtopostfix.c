#include<stdio.h>
#include<malloc.h>
struct node
{
    char ch;
    struct node * link;
};
void push(struct node **stack,char ch)
{
    struct node * n1=(struct node * )malloc(sizeof(struct node));
    n1->link=*stack;
    n1->ch=ch;
    *stack=n1;
}
int isempty(struct node *stack)
{
    return !stack;
}
char pop(struct node **stack)
{
    if(isempty(*stack)==1)
    {
        printf("stack is empty");

        return;
    }
    char ch=(*stack)->ch;
    *stack=(*stack)->link;
    return ch;
}
char peek(struct node *stack)
{
    return (stack->ch);
}
int main()
{
    char str[50];
    int i=0;
    printf("enter infix expression : ");
    scanf("%s",str);
    struct node * stack=NULL;
    printf("postfix expression : ");
    while(str[i]!=0)
    {
        if(!(str[i]=='+'||str[i]=='-'||str[i]=='/'||str[i]=='*'||str[i]=='%'||str[i]==')'||str[i]=='('||str[i]=='^'))
        printf("%c",str[i]);
        if(str[i]=='(')
        {
            push(&stack,str[i]);
        }

        if(str[i]=='+'||str[i]=='-')
        {
            while((isempty(stack)!=1)&&(peek(stack)=='+'||peek(stack)=='*'||peek(stack)=='/'||peek(stack)=='-'||peek(stack)=='%'||peek(stack)=='^')&&peek(stack)!='(')
                  printf("%c",pop(&stack));
            push(&stack,str[i]);
        }
        if((str[i]=='/'||str[i]=='%'||str[i]=='*'))
        {
            while(isempty(stack)!=1&&(peek(stack)=='*'||peek(stack)=='%'||peek(stack)=='/'||peek(stack)=='^')&&peek(stack)!='(')
                printf("%c",pop(&stack));
            push(&stack,str[i]);
        }
        if(str[i]=='^')
        {
            if(isempty(stack)!=1&&(peek(stack)=='^')&&peek(stack)!='(')
                printf("%c",pop(&stack));
                push(&stack,str[i]);
        }
        if(str[i]==')')
        {
            while(peek(stack)!='(')
            {
                printf("%c",pop(&stack));
            }
            pop(&stack);
        }
        i++;
    }
    while(isempty(stack)!=1)
    printf("%c",pop(&stack));
}
