#include<stdio.h>
#include<malloc.h>
struct node
{
    int no;
    struct node * link;
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
    struct node *head1=NULL,*head2=NULL,*temp=NULL,*head3=NULL;
    int i=0,size;
    scanf("%d",&size);
    for(i=1;i<=size;i++)
    {
        struct node * n1=(struct node*)malloc(sizeof(struct node));
        n1->no=i+10;

        if(i==1)
        {
            head3=n1;
            temp=n1;
        }
        else
        {
            temp->link=n1;
            temp=n1;

        }
    }
    temp->link=NULL;
    scanf("%d",&size);
    for(i=0;i<size;i++)
    {
        struct node * n1=(struct node *)malloc(sizeof(struct node));
        scanf("%d",&n1->no);

        if(i==0)
        {
            head1=n1;
            temp=n1;
        }
        else
        {
            temp->link=n1;
            temp=n1;

        }
    }
    temp->link=head3;
    print(head1);
    scanf("%d",&size);
    for(i=0;i<size;i++)
    {
        struct node * n1=(struct node *)malloc(sizeof(struct node));
        scanf("%d",&n1->no);

        if(i==0)
        {
            head2=n1;
            temp=n1;
        }
        else
        {
            temp->link=n1;
            temp=n1;

        }
    }
    temp->link=head3;
    print(head2);
    int count=0,count2=0;
    head3=head1;
    temp=head2;

    while(head3!=NULL)
    {
        count++;
        head3=head3->link;
    }
    while(temp!=NULL)
    {
        count2++;
        temp=temp->link;
    }
    head3=head1;
    temp=head2;
    i=0;
    while(head3!=NULL||temp!=NULL)
    {
        if(count>count2)
        {
            if((i>=count-count2))
            {
                temp=temp->link;

            }
            head3=head3->link;

        }
        else
        {
            if((i>=count2-count))
            {
                head3=head3->link;

            }
            temp=temp->link;

        }
        if(temp==head3)
        {
            printf("%d",temp->no);
            exit(1);
        }
        i++;
    }
}
