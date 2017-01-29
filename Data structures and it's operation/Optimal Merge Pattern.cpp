#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,cost=0;
    cout<<"Enter the number of files\n";
    cin>>n;
    int ar[n];
    cout<<"enter the records\n";
    for(int i=0; i<n; i++)
    {
        scanf("%d",&ar[i]);
    }
    for(int i=0; i<n-1; i++)
    {
        sort(ar+i,ar+n);
        cost+=ar[i]+ar[i+1];
        int f=ar[i]+ar[i+1];
        ar[i+1]=f;

    }
    cout<<"Ans "<<cost<<endl;

}
