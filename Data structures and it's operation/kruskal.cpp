#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
    int m,i,j,mini,index,n,k;
    cout<<"Enter the no of vertices and edges\n";
    cin>>n>>m;
    int u,v;
    int arr[n][n];
    int result[m-1];
    bool mst[n];
    for(i=0;i<m-1;i++)
        result[i]=0;
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
        arr[i][j]=0;
    vector<pair<int , pair < int,int > > > edges;
    pair< int,int > p;
    pair<int,pair<int,int> > q;
    cout<<"Enter starting and ending point of each edge and its weight\n";
    for(i=0;i<m;i++)
    {
        cin>>p.first>>p.second;
        cin>>q.first;
        q.second=p;
        edges.push_back(q);
    }
    index=0;
    k=0;
    sort(edges.begin(),edges.end());
    for(i=0;i<m;i++)
    {
        u=edges[index].second.first;
        v=edges[index].second.second;
        if(arr[u][v]==0)
     {
         arr[u][v]=arr[v][u]=1;
         result[k]=index;
         k++;
         if(k==n-1)
            break;
        for(j=0;j<n;j++)
        {
            if(arr[j][u]==1)
            {
                arr[j][v]=1;
                arr[v][j]=1;
            }
            if(arr[j][v]==1)
            {
                arr[j][u]=1;
                arr[u][j]=1;
            }
        }
     }
        index++;
    }
    printf("Edge   Weight\n");
    for(i=0;i<n-1;i++)
    {
         cout<<edges[result[i]].second.first<<"  "<<edges[result[i]].second.second<<"    "<<edges[result[i]].first<<endl;
    }
}
