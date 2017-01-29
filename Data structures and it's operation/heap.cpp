#include<iostream>
#include<math.h>
#include<stdio.h>
using namespace std;
int data[20];
int data1[20];
void heapify(int a[],int n,int sizes)
{
    int i=2*(n),j=2*(n)+1;
    int largest;
    if(i<=sizes&&a[i-1]>a[n-1])
    largest=i;
    else
    largest=n;
    if(j<=sizes&&a[j-1]>a[largest-1])
        largest=j;
    if(largest!=n)
    {
        swap(a[largest-1],a[n-1]);
        heapify(a,largest,sizes);
    }
}
void makeheap(int a[],int sizes)
{
    int i;
    for(i=sizes/2;i>0;i--)
    {
        heapify(a,i,sizes);
    }
}
void delete_ele(int a[],int sizes,int in)
{
int i;
    for(i=in-1;i<sizes-1;i++)
    {
        a[i]=a[i+1];
    }
}
void display(int a[],int sizes)
{
    int i,count=1,j,k;
    while(pow(2,count)-1<sizes)
    {
        count++;
    }
    //cout<<count;
    for(i=1;i<=count;i++)
    {
        if(i!=count)
        for(j=0;j<data[count-i];j++)
        cout<<" ";
        else
            for(j=0;j<data[count-i];j++)

        cout<<" ";


        for(j=1;j<=data1[i-1];j++)
        {
            if(data1[i-1]+j-2==sizes)
           {
            cout<<endl;
                return;
           }
//cout.width(3);
            cout<<a[data1[i-1]+j-2];
                for(k=0;k<data[count-i+1];k++)
                 cout<<" ";
        }
        if(i==count)
        {
         cout<<endl;
         return;
        }
        cout<<endl;
        for(j=0;j<data[count-i]-1;j++)
        cout<<" ";
        for(j=1;j<=data1[i];j++)
        {
         if(data1[i]-1+j>sizes)
         {
             break;
         }

        if(j%2==1)
            {cout<<'/';
            cout<<" ";
            }else
        if(data1[i]-1+j<=sizes)
        {
            cout<<'\\';
        }
        else
            break;
            if(j%2==0)
        for(k=0;k<data[count-i+1]-1;k++)
           cout<<" ";
        }
        cout<<endl;


    }
}
int main()
{
    int sizes,choice,i;
    data[0]=0;
    data1[0]=1;
    for(i=1;i<20;i++)
    {
        data[i]=2*data[i-1]+1;
        data1[i]=2*data1[i-1];
    }

    cout<<"Enter the size of heap\n";
    cin>>sizes;
    int a[sizes];
    cout<<"Enter the elements of heap\n";
    for(i=0;i<sizes;i++)
        cin>>a[i];
        choice=1;
        while(choice!=4)
        {
            cout<<"Enter\n1 for making heap\n2 for deleting an element\n3 to display\n4 to exit\n";
            cin>>choice;
            if(choice==1)
            {
                makeheap(a,sizes);
            }
            else if(choice==2)
            {
                cout<<"Enter the index of element\n";
                cin>>i;
                delete_ele(a,sizes,i);
                sizes--;
            }
            else if(choice==3)
            {
                display(a,sizes);
            }

        }
}
