#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node * link;
};
void new(struct node **,int);
void new(struct node ** start,int data)
{    struct node * temp=(struct node *)malloc(sizeof(struct node));
    temp->data=data;
    temp->link=NULL;
    if(*start==NULL)
    {
        *start=temp;
    }
    else
    {
        while((*start)->link!=NULL)
    {
       *start=(*start)->link;
    }
    (*start)->link=temp;
    }
}
void newhead(struct node** start,int data)
{
    struct node *temp=(struct node *)malloc(sizeof(struct node));
    temp->link=*start;
    temp->data=data;
    *start=temp;
}
void newnode(struct node ** start,int data,int pos)
{
    struct node *temp=(struct node *)malloc(sizeof(struct node));
    temp->data=data;
    int i=1;
    while(i<pos-1)
    {
        *start=(*start)->link;

    }
    temp->link=(*start)->link;
    (*start)->link=temp;
}
void delete(struct node ** start,int pos)
{
    struct node *temp=*start;
    if(*start!=NULL)
    {


    if(pos==1)
    {

        *start=(*start)->link;
        free(temp);
    }
    else
    {
        int i=1;
        while(i<pos)
        {
            temp=temp->link;
            i++;
        }
         //free(temp->link);
        temp->link=temp->link->link;
    }
    }
    else
        printf("empty");
}
void print(struct node * start)
{
    while(start!=NULL)
    {
        printf("%d\n",start->data);
        start=start->link;
    }
}
int main()
{
    struct node * head=NULL;
        //new(&head,5);
        //new(&head,7);
        newhead(&head,0);
        //newnode(&head,55,2);
        delete(&head,2);
        print(head);

}
