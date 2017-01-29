#include<stdio.h>
#include<malloc.h>
struct node
{
    float coeff;
    int power;
    struct node * link;
};
void input(struct node ** poly1)
{
    float coeff;
    int power;
    int no;
    scanf("%d",&no);
    int i=0;
    struct node * temp;
    while(i<no)
    {
        scanf("%f%d",&coeff,&power);
        struct node * n=(struct node *)malloc(sizeof(struct node));
        n->power=power;
        n->coeff=coeff;
        n->link=NULL;
        if(i==0)
        {
            temp=n;
            *poly1=n;
        }
        else
        {
            temp->link=n;
            temp=n;
        }
        i++;
    }
}
void display(struct node *  poly1)
{
    while(poly1!=NULL)
    {
        printf("%fx^%d ",poly1->coeff,poly1->power);
        poly1=poly1->link;
    }
    printf("\n");
}
struct node * multiply(struct node * poly1,struct node * poly2)
{
    struct node * temp1=poly1,*temp2,*poly3=NULL,*temp,*temp3;
    int var;
    while(temp1!=NULL)
    {
        temp2=poly2;
        while(temp2!=NULL)
        {
            temp=poly3;
            if(temp==NULL)
            {
                struct node * n=(struct node * )malloc(sizeof(struct node));
                n->power=temp1->power+temp2->power;
                n->coeff=temp1->coeff*temp2->coeff;
                n->link=NULL;
                poly3=n;
            }
            else
            {
                var=temp1->power+temp2->power;
                while(var!=temp->power&&var<temp->power&&temp->link!=NULL)
                {
                    temp3=temp;
                    temp=temp->link;
                }
                if(var==temp->power)
                {
                    temp->coeff+=temp1->coeff*temp2->coeff;
                }
                else if(var>temp->power)
                {
                    if(temp==poly3)
                    {
                        struct node * n=(struct node *)malloc(sizeof(struct node));
                        n->power=var;
                        n->coeff=temp1->coeff*temp2->coeff;
                        n->link=poly3;
                        poly3=n;
                    }
                    else
                    {
                        struct node * n=(struct node *)malloc(sizeof(struct node));
                        n->power=var;
                        n->coeff=temp1->coeff*temp2->coeff;
                        temp3->link=n;
                        n->link=temp;
                    }
                }
                else if(temp->link==NULL)
                {
                    struct node * n=(struct node *)malloc(sizeof(struct node));
                        n->power=var;
                        n->coeff=temp1->coeff*temp2->coeff;
                        n->link=NULL;
                        temp->link=n;
                }
            }
            temp2=temp2->link;
        }
        temp1=temp1->link;
    }
    return poly3;
}
int main()
{
    struct node * poly1,*poly2,*poly3;
    input(&poly1);
    input(&poly2);
    display(poly1);
    display(poly2);
    poly3=multiply(poly1,poly2);
    display(poly3);
}
