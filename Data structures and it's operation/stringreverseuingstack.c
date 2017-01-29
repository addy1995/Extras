#include<stdio.h>
#include<malloc.h>
struct stack
{
    int top;
    unsigned capacity;
    char * array;
};
struct stack * createstack(unsigned capacity)
{
    struct stack * temp=(struct stack *)malloc(sizeof(struct stack));
    temp->capacity=capacity;
    temp->top=-1;
    temp->array=(char *)malloc(sizeof(char)*capacity);
    return temp;
};
int isempty(struct stack * stack)
{
    return stack->top==-1;
}
void push(struct stack * stack,char ch)
{
    stack->array[++stack->top]=ch;

}
char pop(struct stack * stack)
{
    return stack->array[stack->top--];
}
int main()
{
    char str[20];
    scanf("%s",str);
    int i=0;
    struct stack * stack=createstack(20);
    while(str[i]!='\0')
    {
        push(stack,str[i]);
        i++;
    }
    i=0;
    while(!isempty(stack))
    {
        str[i]=pop(stack);
        i++;
    }
    str[i]='\0';
    printf("%s",str);

}

