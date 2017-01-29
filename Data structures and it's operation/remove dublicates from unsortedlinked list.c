#include<stdio.h>
struct node
{
    int no;
    struct node * link;
};
void print(struct node * start)
{
    printf("\n");
    while(start!=NULL)
    {
        printf("%d ",start->no);
        start=start->link;
    }
    printf("\n");
}
int main()
{
    struct node *start=NULL,*temp=NULL,*temp2=NULL,*temp3=NULL,*var1=NULL;
    int size;
    scanf("%d",&size);
    int i,var;
    for(i=0;i<size;i++)
    {
        struct node * n1=(struct node * )malloc(sizeof(struct node));
        n1->link=NULL;
        scanf("%d",&var);
        n1->no=var;
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
    while(temp!=NULL)
    {
        temp2=temp;
        while(temp2!=NULL)
        {
            printf("s");
            if(temp!=temp2)
            {
                if(temp->no==temp2->no)
                {
                    temp3->link=temp2->link;
                    var1=temp2;
                    printf("%d",temp2->no);
                    temp2=temp2->link;

                    printf("%d",temp3->no);
                    var1->link=NULL;
                    free(var1);




                }
                else
                {
                    temp3=temp2;
                    temp2=temp2->link;
                }
            }
            else
            {

            temp3=temp2;
            temp2=temp2->link;
            }
        }
        temp=temp->link;

    }
    print(start);

}
