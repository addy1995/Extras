#include<stdio.h>
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
        start=start->
        link;
    }
    printf("\n");
}
int main()
{
    int i,j,flag1,size;
    struct node * start=NULL,*temp=NULL,*temp2=NULL,*temp3=NULL,*ptr=NULL,*temp4=NULL;
    int counter;
    scanf("%d",&size);
    for(i=0;i<size;i++)
    {
        struct node * n1=(struct node *)malloc(sizeof(struct node));
        n1->no=i*i*i;
        n1->link=NULL;
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
    int var,flag=0;
    flag1=0;
    scanf("%d",&var);
    temp=start;temp2=start;temp3=start;
    while(temp!=NULL)
    {
        for(i=0;i<var;i++)
        {
            if(temp2==NULL)
            {
                break;
            }
            if(i==0)
            {
                temp=temp2;
                temp2=temp2->link;
                temp3=temp2;
                ptr=temp;
            }
            else
            {
                temp3=temp3->link;
                temp2->link=temp;
                temp=temp2;
                temp2=temp3;
            }

        }
        if(flag==0)
        {
            start=temp;
            flag=1;
        }
        temp=temp2;
        temp4=temp2;
        counter=0;
        while(1)
        {
            if(counter==var-1)
            {
                flag1=1;
                break;
            }

            if(temp4!=NULL)
            {


            if(temp4->link==NULL)
             {
                 flag1=1;
                 break;
             }
            }
            else
            {
                flag1=1;
                break;
            }
            temp4=temp4->link;
            counter++;

        }
        if(temp2==NULL)
        {
            ptr->link=NULL;

        }

        if(flag1==1)
        {
            ptr->link=temp4;
            flag1=0;
        }
    }
    print(start);


}
