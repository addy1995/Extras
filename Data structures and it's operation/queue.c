#include<stdio.h>
#include<malloc.h>
struct node
{
    int no;
    struct node * link;
};
void push(struct node ** start,struct node  ** end,int no)
{
    if(*start==NULL)
    {

        struct node * n1=(struct node *)malloc(sizeof(struct node));
        n1->no=no;
        n1->link=NULL;
        *start=n1;
        *end=n1;

    }
    else
    {
        struct node * n1=(struct node *)malloc(sizeof(struct node));
        n1->link=NULL;
        n1->no=no;
        (*end)->link=n1;
        *end=n1;

    }
}
void display(struct node * start,struct node *  end)
{
    if(start==NULL)
    return;
    while(1)
    {
        printf("%d ",start->no);
        if(start==end)
            break;
        start=start->link;
    }
    printf("\n");

}
void pop(struct node ** start,struct node **end)
{
    struct node * temp=NULL;
    if(*start==NULL&&end==NULL)
    {
        return;
    }
    else
    {
        if(*start==NULL)
        {
            printf("underflow");
            *end=NULL;
            return;
        }
        temp=*start;
        printf("%d \n",(*start)->no);
        *start=(*start)->link;
        free(temp);
        temp=NULL;

    }

}
int main()
{
    struct node * start=NULL,*end=NULL;
    int i=0;
    push(&start,&end,6);
    push(&start,&end,75);
    push(&start,&end,5);
    push(&start,&end,59);
    display(start,end);
    printf("poping element : ");
    pop(&start,&end);
    printf("poping element : ");
    pop(&start,&end);
    display(start,end);
}
