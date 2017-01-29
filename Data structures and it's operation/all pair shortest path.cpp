#include<iostream>
#include<stdio.h>
#include<string.h>
#define inf 100000000
using namespace std;
int main()
{
    int n,m,i,j,k,u,v,w;
    char ch[4];
    cout<<"Enter the no of nodes in graph\n";
    cin>>n;
    int arr[n+1][n+1];
    cout<<"Enter the no of edges\n";
    cin>>m;
    cout<<"is the graph directed\n";
    cin>>ch;
    cout<<"Enter the starting node,ending node and weight\n";
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            if(i!=j)
            arr[i][j]=inf;
            else
            arr[i][j]=0;
        }
    }
    if(strcmp(ch,"yes")==0||strcmp(ch,"YES")==0)
    for(i=0;i<m;i++)
    {
        cin>>u>>v>>w;
        arr[u][v]=w;
    }
    else
    for(i=1;i<=m;i++)
    {

        cin>>u>>v>>w;
        arr[v][u]=arr[u][v]=w;

    }
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            for(k=1;k<=n;k++)
            {
                if(arr[j][i]+arr[i][k]<arr[j][k])
                {
                    arr[j][k]=arr[j][i]+arr[i][k];
                }
            }

        }
    }
    cout<<"\n";
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            cout<<arr[i][j]<<' ';
        }
        cout<<endl;
    }
}
