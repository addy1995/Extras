#include<stdio.h>
#include<malloc.h>
struct node
{
    int no;
    struct node * link;
};
void push(struct node ** start,struct node  ** end,int no)
{
    struct node * start2=NULL, *end2=NULL,*temp=NULL;
    int i=0;
    while(*start!=NULL)
    {
        struct node * n1=(struct node *)malloc(sizeof(struct node));
        if(i==0)
        {
            start2=n1;
            end2=n1;                //Copying nos from queue 1 to queue 2
            n1->link=NULL;


            n1->no=(*start)->no;

        }
        else
        {


            n1->no=(*start)->no;
            (end2)->link=n1;
            n1->link=NULL;
            end2=n1;
        }
        i++;
        if(*start==*end)
           {
               free(*start);
               *start=NULL;
               free(*end);
               *end=NULL;

            break;
           }
           temp=*start;
        *start=(*start)->link;
        free(temp);
        temp=NULL;
    }
    struct node * n1=(struct node *)malloc(sizeof(struct node));

    n1->no=no;
    n1->link=NULL;
    *start=n1;
    *end=n1;
    while(start2!=NULL)
    {
        struct node * n1=(struct node *)malloc(sizeof(struct node));
        n1->no=start2->no;
        (*end)->link=n1;
        *end=n1;
        if(start2==end2)
            {
                free(start2);
                start2=NULL;
                free(end2);
                end2=NULL;
                break;
            }
            temp=start2;
        start2=start2->link;
        free(temp);
        temp=NULL;
    }



}
void display(struct node * start,struct node *  end)
{
    if(start==NULL&&end==NULL)
    return;
    while(1)
    {
        printf("%d ",start->no);
        if(start==end)
            break;
        start=start->link;
    }

}
void pop(struct node **start,struct node * *end)
{
    struct node * temp=*start;
    if(*start==NULL)
    {
        printf("underflow");
        free(temp);
        free(*end);
        (*end)->link=NULL;
        *end=NULL;

        return;
    }
    printf("\n%d \n",(*start)->no);
    *start=(*start)->link;
    free(temp);
    temp->link=NULL;
}
int main()
{
    struct node * start=NULL,*end=NULL;
    int i=0,size,var;
    scanf("%d",&size);
    for(i=0;i<size;i++)
    {
        scanf("%d",&var);
        push(&start,&end,var);
    }
    display(start,end);
    pop(&start,&end);
    display(start,end);

}
