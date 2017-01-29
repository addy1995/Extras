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
    struct node *head1=NULL,*temp=NULL,*temp2,*temp3;
    int i=0,size;
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
    temp->link=NULL;
    print(head1);
    temp=head1;
    int var;
    i=1;
    while(temp!=NULL)
    {
        if(i==1)
        {

            temp2=temp;
            var=temp->no;
            i=0;
            temp=temp->link;
        }
        else
        {
            if(var==temp->no)
            {
                temp2->link=temp->link;
                temp3=temp;
                temp=temp->link;
                free(temp3);
            }
            else
            {
                temp2=temp;
                var=temp->no;
                temp=temp->link;
            }
        }

    }
    print(head1);

}
