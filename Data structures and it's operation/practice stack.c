#include<stdio.h>
struct stack
{
    char arr[30];
    int top;
};
int isempty(struct stack *s)
{
    return s->top==-1;
}
int isfull(struct stack *s)
{
    return s->top==29;
}
void push(struct stack *s,int item)
{
    s->arr[++s->top]=item;

}
int pop(struct stack *s)
{

    int temp=s->arr[s->top--];
    return temp;
}
void initialize(struct stack *s)
{
    s->top=-1;
}
void printreverse(struct stack *s)
{
    while(!isempty(s))
    {

    printf("%c",pop(s));
    }
}
void main()
{
   struct stack s1;
   char str[30];
   gets(str);
   initialize(&s1);
    int i=0;
    while(str[i]!=NULL)
    {
        if(isfull(&s1))
        {
            printf("overflow\n );
            break;
        }
        push(&s1,str[i]);
        i++;
    }
    printreverse(&s1);

}
