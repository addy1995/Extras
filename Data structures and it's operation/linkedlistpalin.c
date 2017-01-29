#include<stdio.h>
#include<malloc.h>
struct node
{
    int no;
    struct node * link;
};
void print(struct node *start)
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
    struct node * head=NULL,*head2=NULL,*temp=NULL,*temp2=NULL;
    int i,size;
    scanf("%d",&size);
    for(i=0;i<size;i++)
    {
        struct node * n1=(struct node *)malloc(sizeof(struct node));
        scanf("%d",&(n1->no));
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
    if(size!=0)
    temp->link=NULL;
    print(head);
    temp2=head;
    i=0;
    while(temp2!=NULL)
    {
        struct node *n2=(struct node *)malloc(sizeof(struct node));
        n2->no=temp2->no;
        if(i==0)
        {
            n2->link=NULL;
            temp=n2;
        }
        else
        {
            n2->link=temp;
            temp=n2;

        }
        temp2=temp2->link;
        i++;
    }
    head2=temp;
    temp2=head;
    print(head2);
    i=0;
    while(1)
    {
        if(temp->no!=temp2->no)
        {
            i=1;
            break;
        }
        temp=temp->link;
        temp2=temp2->link;
        if(temp==NULL||temp2==NULL)
            break;
    }
    if(i==0)
        printf("No is palindrome");
    else
        printf("No is not palindrome");

}
