#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node * link;
};
void print(struct node *temp)
{
    while(temp!=NULL)
    {
        printf("%d\n",(temp)->data);
        temp=temp->link;
    }
}
int main()
{
    struct node * start=NULL,*temp;
    int i,var;
    scanf("%d",&i);
    var=i;
    while(i>0)
    {
        if(var==i)
        {
            start=(struct node *)malloc(sizeof(struct node));
            start->data=i;
            temp=start;
        }
        else
        {
            struct node *n1=(struct node *)malloc(sizeof(struct node));
            n1->data=i;
            temp->link=n1;
            temp=n1;
        }
        i--;
    }
    temp->link=NULL;
    temp=start;
    struct node * vari=start,*temp2;
    int counter=0;
    while(temp->link!=NULL)
    {
        temp=temp->link;
        if(counter==0)
        {
        vari->link=NULL;
        }
        else
        {
            vari->link=temp2;
        }
        temp2=vari;
        vari=temp;

        counter++;

    }
    vari->link=temp2;

    print(vari);
    return 0;
}
