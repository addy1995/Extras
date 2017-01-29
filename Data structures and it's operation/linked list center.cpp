#include<iostream>
#include<stdlib.h>
using namespace std;
int main()
{
    struct node
    {
        int a;
        struct node *link;
    }*n1,*start,*temp,*temp2;
    int i=0,no;
    while(i<10)
    {
    n1=(struct node *)malloc(sizeof(node));
    n1->a=i+1;
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
    i++;
    }
    n1->link=NULL;
    temp=start;
    temp2=start;
    for(i=1;;i++)
    {
        if(temp2->link==NULL||temp2->link->link==NULL)
        break;

        temp=temp->link;
        temp2=temp2->link->link;
    }
    cout<<temp->a<<endl;



    for(i=0;1;i++)
    {
        if(i==0)
        {
            temp=start;
        }
        else
        {
            temp=temp->link;
        }
        cout<<temp->a<<endl;
        if(temp->link==NULL)
            break;




    }
    return 0;

}

