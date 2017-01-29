#include<stdio.h>
#include<malloc.h>
struct node
{
    int info;
    struct node * link;
};
void print(struct node * link )
{
    while(link!=NULL)
    {
        printf("%d ",link->info);
        link=link->link;
    }
}
int main()
{
    struct node  * head,*temp,*temp2,*mid,*lb,*ub;
    int i=0,var;
    for(i=0;i<15;i++)
    {
        struct node * n1=(struct node *)malloc(sizeof(struct node));
        n1->info=i*i;
        n1->link=NULL;
        if(i==0)
        {
            head=n1;
            temp=n1;
        }
        else
        {
            temp->link=n1;
            temp=n1;
        }

    }
    temp->link=NULL;
    lb=head;
    ub=temp;
    mid=head;
    temp=head;
    print(head);
    while(temp!=NULL&&temp->link!=NULL)
    {
        mid=mid->link;
        temp=temp->link->link;
    }
    printf("%d ",mid->info);
    scanf("%d",&var);
    while(1)
    {
        if(mid->info==var)
        {
            printf("found");
            break;
        }
         if(lb==ub)
        {
            printf("not found");
            break;
        }
        if(var>mid->info)
        {
            lb=mid->link;
        }
        else
        {
            ub=mid;
        }
        mid=lb;
        temp=lb;
        while(temp!=ub&&temp->link!=ub)
        {
            mid=mid->link;
            temp=temp->link->link;
        }

    }

}
