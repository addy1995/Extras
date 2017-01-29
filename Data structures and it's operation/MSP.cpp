#include<iostream>
#include<stdio.h>
using namespace std;
#include<vector>
#include<queue>
queue<int> track;
vector<vector<int> >  dp;
void removelast()
{
    queue<int> temp;
    while(track.size()!=0)
    {
        if(track.size()!=1)
        temp.push(track.front());
        track.pop();
    }
    while(temp.size()!=0)
    {
        track.push(temp.front());
        temp.pop();
    }
}
void print()
{
    queue<int> temp;
    while(track.size()!=0)
    {
        temp.push(track.front());
        if(track.size()!=1)
        cout<<track.front()<<"->";
        else
            cout<<track.front()<<endl;
        track.pop();
    }
    while(temp.size()!=0)
    {
        track.push(temp.front());
        temp.pop();
    }
    cout<<endl;
}
void printans(vector<vector<vector< int> > > data,vector<int> arr,int n,int ans,int stage,int index)
{
    int i;
    if(stage==n-1)
    {
        if(ans==dp[0][0])
     {
            print();
    }
        else
            return ;
    }
    else
    {
        for(i=0;i<arr[stage+2]-arr[stage+1];i++)
        {
            if(data[stage][index][i]!=0)
            {
                track.push(arr[stage+1]+i);
                printans(data,arr,n,ans+data[stage][index][i],stage+1,i);
                removelast();

            }
        }
    }
}
int mgp(vector<vector<vector< int> > > data,vector<int> arr,int n,int stage,int index)
{
    int i,j,k,mini=100000000,var;
    if(stage!=n-1)
    {
        if(dp[stage][index]!=0)
        return dp[stage][index];
        for(i=0;i<arr[stage+2]-arr[stage+1];i++)
        {
            if(data[stage][index][i]!=0)
            {
                mini=min(mini,data[stage][index][i]+mgp(data,arr,n,stage+1,i));
            }
        }
        return (dp[stage][index]=mini);
    }
    else
    {
        return 0;
    }
}
int main()
{
    int n,i,j,var,a,u,v,w,k;
    cout<<"Enter the no of stages\n";
    scanf("%d",&n);
    vector<int> arr;
    cout<<"Enter the no of vertex at each stage\n";
    vector<vector<vector< int> > > data;
    data.resize(n-1);
    dp.resize(n);
    arr.push_back(1);
    for(i=0;i<n;i++)
    {
        scanf("%d",&var);
        arr.push_back(arr[i]+var);
        dp[i].resize(0);
        if(i!=n-1)
        {

            data[i].resize(var);
        for(j=0;j<var;j++)
        {

             data[i][j].resize(0);
             dp[i].push_back(0);
             for(k=0;k<var;k++)
             {
                 data[i][j].push_back(0);
             }
        }
        }
        else
        {
            for(j=0;j<var;j++)
        {
             dp[i].push_back(0);
        }

        }

    }
    for(i=0;i<n-1;i++)
    {
        cout<<"Enter the no of edges from stage "<<i+1<<" to stage "<<i+2<<endl;
        cin>>a;
        cout<<"Enter the staring vextex,ending vertex and weight\n";
        for(j=0;j<a;j++)
        {
            cin>>u>>v>>w;
            data[i][u-arr[i]][v-arr[i+1]]=w;
        }

    }
    track.push(1);
    cout<<"Minimum path is ";
    cout<<(dp[0][0]=mgp(data,arr,n,0,0))<<endl;
    printans(data,arr,n,0,0,0);
}
