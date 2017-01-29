#include<stdio.h>
#include<malloc.h>
struct node
{
    int data;
    struct node * link;
};
struct node * intersect(struct node * head1,struct node * head2)
{
    struct node * head3=NULL,*temp=NULL;
    int i=0;
    while(head1!=NULL)
    {
        while(1)
        {
            if(head1->data<head2->data)
            {
                break;
            }
            if(head1->data==head2->data)
            {
                struct node * n1=(struct node *)malloc(sizeof(struct node));
                n1->data=head1->data;
                if(i==0)
                {
                    head3=n1;
                    temp=n1;
                }
                else
                {
                    temp->link=n1;
                    temp=n1;
                }
                i++;
                if(head2->link==NULL)
                    break;

                while(1)
                {
                    if(head2->link->data==head1->data)
                    {
                        head2=head2->link;
                    }
                    else
                        break;
                }




            }
             head2=head2->link;

        }
        if(head2==NULL)
            break;
        head1=head1->link;

    }
    //printf("%");
    temp->link=NULL;
    return head3;

}
void display(struct node * temp)
{
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->link;
    }
    printf("\n");
}

int main()
{
    struct node * start1=NULL,*start2=NULL,*temp=NULL;
    int size,i;
    scanf("%d",&size);
    for(i=0;i<size;i++)
    {
        struct node * n1=(struct node *)malloc(sizeof(struct node));
        scanf("%d",&n1->data);
        if(i==0)
        {
            start1=n1;
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
        scanf("%d",&n1->data);
        if(i==0)
        {
            start2=n1;
            temp=n1;
        }
        else
        {
            temp->link=n1;
            temp=n1;
        }
    }temp->link=NULL;

    display(start1);
    display(start2);

    temp=intersect(start1,start2);
    display(temp);

}
