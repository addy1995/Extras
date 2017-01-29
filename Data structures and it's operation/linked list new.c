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
void deletelink(struct node ** temp)
{
    struct node * temp2;
        while(*temp!=NULL)
    {
        temp2=*temp;
     *temp=(*temp)->link;
     free(temp2);
     temp2==NULL;

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
    int pos;
    scanf("%d",&pos);
    struct node * temp2,*temp3;
    temp2=start;temp=start;
    temp3=start;
    for(i=0;i<pos;i++)
    {
        if(temp2==NULL||temp2->link==NULL)
        {
            printf("not possible");
            exit(1);
        }
        temp2=temp2->link;

    }
    print(start);
    while(!(temp3==NULL||temp3->link==NULL))
    {
        //if(temp3==NULL||temp3->link==NULL)
          //break;
        if(pos<=0)
        {temp=temp->link;

        }
        temp2=temp2->link;
        temp3=temp3->link->link;

        pos--;
    }
    if(pos>=0)
    {
        printf("not possible");
      exit(1);
    }
    printf("%d %d",temp->data,temp2->data);
    deletelink(&start);
    print(start);
    return 0;
}
