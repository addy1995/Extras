#include<stdio.h>
struct node
{
    int no;
    struct ndoe * link;
};
void print(struct node * start)
{
    while(start!=NULL)
    {
        printf("%d ",start->no);
        start=start->link;
    }
    printf("\n");
}

int main()
{
    struct node * start=NULL,*temp=NULL,*start1=NULL,*temp2=NULL;
    int size,i;
scanf("%d",&size);
    for(i=0;i<size;i++)
    {
        struct node * n1=(struct node *)malloc(sizeof(struct node));
        n1->no=i*i;
        if(i==0)
        {
            temp=n1;
            start=n1;
        }
        else
        {
            temp->link=n1;
            temp=n1;
        }
    }

    temp->link=NULL;
    print(start);
    scanf("%d",&size);
    for(i=0;i<size;i++)
    {
        struct node * n1=(struct node *)malloc(sizeof(struct node));
        n1->no=i*i*i;
        if(i==0)
        {
            temp=n1;
            start1=n1;
        }
        else
        {
            temp->link=n1;
            temp=n1;
        }
    }

    temp->link=NULL;
    print(start1);
    temp=start;
    temp2=start1;
    struct node * start3=(struct node *)malloc(sizeof(struct node)),*temp3;
    temp3=start3;
    if(temp->no>=temp2->no&&temp!=NULL&&temp2!=NULL)
        {
            temp3->no=temp->no;
            temp=temp->link;
        }
        else
        {
            struct node * n1=(struct node *)malloc(sizeof(struct node));
            temp3->no=temp2->no;
            temp2=temp2->link;
        }
    while(1)
    {
        if(temp==NULL)
            {
                temp3->link=temp2;
                break;
            }
        if(temp2==NULL)
            {
                temp3->link=temp;
                break;
            }
        if(temp->no<temp2->no)
        {
            struct node * n1=(struct node *)malloc(sizeof(struct node));
            n1->no=temp->no;
            temp3->link=n1;
            temp3=n1;
            temp=temp->link;
        }
        else
        {
            struct node * n1=(struct node *)malloc(sizeof(struct node));
            n1->no=temp2->no;
            temp3->link=n1;
            temp3=n1;
            temp2=temp2->link;
        }
    }

    print(start3);
}
