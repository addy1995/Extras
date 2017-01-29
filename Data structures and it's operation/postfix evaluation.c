#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node * link;
};
void push(struct node ** stack,int no)
{
    struct node * n1=(struct node *)malloc(sizeof(struct node));
    n1->link=*stack;
    n1->data=no;
    *stack=n1;
}
int isempty(struct node * stack)
{
    return !stack;
}
int pop(struct node **stack)
{
    if(isempty(*stack)==1)
        return ;
    int var=(*stack)->data;
    *stack=(*stack)->link;
    return var;
}
int postfixevaluation(char * exp)
{
    int var1,var2,i=0;
    struct node * stack=NULL;
    while(*(exp+i)!='\0')
    {
        //printf("%d",(int)*(exp+i)-48
        if(*(exp+i)<=57 && *(exp+i)>=48)
        {
            push(&stack,(int)*(exp+i)-48);

        }
        else
        {
            var1=pop(&stack);
            var2=pop(&stack);
            switch(*(exp+i))
            {
                case '+':
                push(&stack,var2+var1);
                break;
                case '-':
                push(&stack,var2-var1);
                break;
                case '*':
                push(&stack,var2*var1);
                break;
                case '/':
                push(&stack,var2/var1);
                break;
                case '%':
                push(&stack,var2%var1);
                break;
            };

        }
        i++;

    }
    return pop(&stack);
}
int main()
{
    char exp[50];
    scanf("%s",exp);
    printf("%d",postfixevaluation(exp));
}
