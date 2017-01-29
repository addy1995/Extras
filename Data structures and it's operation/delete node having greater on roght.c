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
    struct node * start=NULL,*temp,*temp2,*temp3;
    int  i=0,size;
    scanf("%d",&size);
    for(i=0;i<size;i++)
    {
        struct node *n1=(struct node*)malloc(sizeof(struct node));
        n1->link=NULL;
        scanf("%d",&(n1->no));
        if(i==0)
        {
            start=n1;
            temp=n1;
        }
        else
        {
            temp->link=n1;
            temp=n1;
        }
    }
    print(start);
    temp=start;
    i=0;
    scanf("%d",&size);
    while(temp->link!=NULL)
    {
        if(temp==NULL)
            break;

        if(temp->link!=NULL)
        {
           /// printf("%d ",temp->no);
        if(temp->link->no > temp->no)
        {
            if(i==0)
            {
                printf("1");
                temp2=temp;
                start=temp->link;
                free(temp2);
            }
            else
            {
                printf("2");
                temp3->link=temp->link;
                temp2=temp;
                temp3=temp;
                temp=temp->link;
                free(temp2);
            }
        }
        else
        {

            printf("3");
            scanf("%d",&size);
          temp3=temp;
         temp=temp->link;
          i=1;
        }
        }
        else
            break;
    }
    print(start);

}
