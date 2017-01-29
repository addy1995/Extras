#include<stdio.h>
#include<malloc.h>
struct node
{
    int no;
    struct node * link;
};
void display(struct node * start)
{
    struct node *temp=NULL;
    temp=start;
    do
    {
        printf("%d ",temp->no);
        temp=temp->link;

    }
    while(temp!=start);
    printf("\n");
}
int main()
{
    struct node * start=NULL,*temp=NULL,*temp2=NULL,*start2=NULL;
    int size,i;
    scanf("%d",&size);
    for(i=0;i<size;i++)
    {
        struct node * n1=(struct node *)malloc(sizeof(struct node));
        n1->no=i+1;
        if(i==0)
        {
            start=n1;
            temp=n1;
        }
        else
        {
            temp->link=n1;
            temp=n1;

        }
    }
    temp->link=start;
    display(start);
    temp=start;
    temp2=start;
    while(1)
    {
        if(temp2->link==start||temp2->link->link==start)
        {
            break;
        }
        temp=temp->link;
        temp2=temp2->link->link;

    }
    //printf("%d %d",temp->no,temp2->no);
    if(temp2->link==start)
    {start2=temp->link;
    temp2->link=start2;
    temp->link=start;

    }
    else
    {
        start2=temp->link;
        temp2->link->link=start2;
        temp->link=start;
    }
    display(start);
    display(start2);



}
