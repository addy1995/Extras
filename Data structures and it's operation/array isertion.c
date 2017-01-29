#include<stdio.h>
struct student
{
    int rollno;
    char name[20];
};
int main()
{
    struct student arr[6];
    int i=0;
    for(i=0;i<5;i++)
    {
        scanf("%s",&arr[i].name);
        scanf("%d",&arr[i].rollno);
    }
    struct student var;
    scanf("%s",&var.name);
    scanf("%d",&var.rollno);
    int pos;
    scanf("%d",&pos);
    for(i=4;i>=pos;i--)
    {
        arr[i+1]=arr[i];
    }
    arr[pos]=var;
    for(i=0;i<6;i++)
    {
        printf("%s %d\n",arr[i].name,arr[i].rollno);
    }

}
