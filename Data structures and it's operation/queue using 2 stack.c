#include<stdio.h>
#include<malloc.h>
struct node
{
    int no;
    struct node * link;

};
void push(struct node ** stack1,int no)
{
    struct node * stack2=NULL,*temp=NULL;
    int i=0;
    while(*stack1!=NULL)
    {
        struct node * n1=(struct node *)malloc(sizeof(struct node *));
        n1->no=(*stack1)->no;
        if(i==0)
        {
        stack2=n1;
        n1->link=NULL;
        }
        else
        {
            n1->link=stack2;
            stack2=n1;
        }
        temp=*stack1;
        *stack1=(*stack1)->link;
        free(temp);
        i++;
    }
    struct node * n1=(struct node *)malloc(sizeof(struct node *));
    n1->no=no;
    *stack1=n1;
    n1->link=NULL;
    while(stack2!=NULL)
    {
        struct node * n1=(struct node *)malloc(sizeof(struct node *));
        n1->link=*stack1;
        n1->no=stack2->no;
        *stack1=n1;
        stack2=stack2->link;

    }

}
void pop(struct node ** stack1)
{
    struct node * temp=*stack1;
    printf("%d ",(*stack1)->no);
    *stack1=(*stack1)->link;
    free(temp);
    temp=NULL;
}
void display(struct node * temp)
{
    while(temp!=NULL)
    {
        printf("%d ",temp->no);
        temp=temp->link;
    }
    printf("\n");
}
int main()
{
    struct node * stack1=NULL;
    int i=0,size,var;
    scanf("%d",&size);
    for(i=0;i<size;i++)
    {
        scanf("%d",&var);
        push(&stack1,var);
    }
    pop(&stack1);
    pop(&stack1);
display(stack1);
    pop(&stack1);
    pop(&stack1);
    display(stack1);

}
