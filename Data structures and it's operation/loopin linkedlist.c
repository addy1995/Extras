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
        getch();
        temp=temp->link;
    }
}
int main()
{
    struct node * start=NULL,*temp,*joint;
    int i,var;
    scanf("%d",&i);
    var=i;
    int join;
    scanf("%d",&join);
    while(i>0)
    {
        if(var==i)
        {
            start=(struct node *)malloc(sizeof(struct node));
            start->data=var-i+1;
            temp=start;
            if(join==(var-i+1))
            joint=start;
        }
        else
        {
            struct node *n1=(struct node *)malloc(sizeof(struct node));
            n1->data=var-i+1;
            temp->link=n1;
            temp=n1;
            if(join==(var-i+1))
            {
                joint=n1;
            }
        }

        i--;
    }
    temp->link=joint;
    temp=start;
    struct node * temp2=start;
    var=1;
    i=1;
    while(1)
    {
        if(var==1)
        {
            temp=temp->link;
            temp2=temp2->link->link;
        }
        else
        {
            temp=temp->link;
            temp2=temp2->link;
            i++;
        }
        if(temp==temp2&&var==1)
        {
            if(temp==start)
            {
                printf("%d",i);
                break;
            }
            temp=start;
            var=0;
        }
        else if(temp==temp2)
        {
            printf("%d",i);
            break;
        }
    }
    return 0;
}
