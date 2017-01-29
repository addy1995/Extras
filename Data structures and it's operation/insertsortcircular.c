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
    struct node * start=NULL,*temp=NULL,*temp2=NULL;
    int size,i;
    scanf("%d",&size);
    for(i=0;i<size;i++)
    {
        struct node * n1=(struct node *)malloc(sizeof(struct node));
        scanf("%d",&n1->no);
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
    temp2=temp;
    temp->link=start;
    display(start);
    int var;
    scanf("%d",&var);
    temp=start;
    while(1)
    {



        if(var>=temp->no&&var<=temp->link->no)
        {
            struct node * n1=(struct node *)malloc(sizeof(struct node));
            n1->no=var;
            n1->link=temp->link;
            temp->link=n1;
            break;
        }
        if(var<temp->no)
        {
            struct node * n1=(struct node *)malloc(sizeof(struct node));
            n1->no=var;
            n1->link=temp;
            start=n1;
            temp2->link=start;
            break;

            }
        if(temp->link==start)
        {
            struct node * n1=(struct node *)malloc(sizeof(struct node));
            n1->no=var;
            n1->link=temp->link;
            temp->link=n1;


            break;
        }
        temp=temp->link;

    }
    display(start);


}
