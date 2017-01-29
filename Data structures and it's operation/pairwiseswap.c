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
    struct node * head=NULL,*temp=NULL,*temp2=NULL,*var=NULL;
    int size,i;
    scanf("%d",&size);
    for(i=0;i<size;i++)
    {
        struct node * n1=(struct node *)malloc(sizeof(struct node));
        n1->no=i+1;
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
    print(head);
    temp=head;
    temp2=head->link;
    i=1;
    while(1)
    {
        if(i==1)
        {
            temp->link=temp2->link;
            head=temp2;
            temp2->link=temp;
            i=0;
        }
        else
        {
            temp->link=temp2->link;
            temp2->link=temp;
            var->link=temp2;
        }
        var=temp;

        if(temp->link==NULL||temp->link->link==NULL)
            break;

        temp=temp->link;
        temp2=temp2->link->link->link;
    }
    print(head);

}
