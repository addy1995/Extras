#include<stdio.h>
struct stack
{
    int arr[30];
    int top;
}s;
void push(int var)
{
    s.arr[++s.top]=var;
}
int pop()
{
    int temp=s.arr[s.top];
    s.top--;
    return temp;
}
int main()
{
    s.top=-1;
    char str[30];
    int i=0,temp=0;
    scanf("%s",&str);
    while(str[i]!='\0')
    {
        if(str[i]=='+'||str[i]=='%'||str[i]=='/'||str[i]=='*'||str[i]=='-')
        {
            switch(str[i])
            {
                case '+':
                temp=pop();
                temp=pop()+temp;
                break;
                case '-':
                    temp=pop();
                    temp=pop()-temp;
                    break;
                case '/':
                    temp=pop();
                    temp=pop()/temp;
                    break;
                case '*':
                    temp=pop();
                    temp=pop()*temp;
                    break;
                case '%':
                    temp=pop();
                    temp=pop()%temp;
                    break;
            };
            push(temp);
            i++;
            if(str[i]=='\0')
                break;
        }
        else
        {
            temp=0;
            while(str[i]!=',')
            {
                temp=temp*10+(int)str[i]-48;
                i++;
            }
           push(temp);
        }
        i++;

    }
    printf("%d",pop());
}
