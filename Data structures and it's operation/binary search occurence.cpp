#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;
int binary(int a[],int left,int right,int item)
{
    int mid;
    mid=(left+right)/2;
    if(left>right)
        return -1;
    if(a[mid]==item)
    {
        int b=binary(a,left,mid-1,item);
        if(b==-1)
            return mid;
            return b;
    }
    else
    if(a[mid]<item)
    {
        return binary(a,mid+1,right,item);
    }
    else
    {
        return binary(a,left,mid-1,item);
    }

}
int main()
{
    int i=0;
    int arr[10];
    for(i=0;i<=9;i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("%d",binary(arr,0,9,7));
}
