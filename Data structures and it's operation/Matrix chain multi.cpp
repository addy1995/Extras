#include<iostream>
#include<stdio.h>
#define N 5
using namespace std;
void order(int val[N+1],int arr[N][N],int i,int j)
{
    int k;
    if(i!=0)
    cout<<"*(";
    else
        cout<<"(";
              for(k=i;k<j;k++)
              {
                  if(arr[i][j]==arr[i][k]+arr[k+1][j]+val[i]*val[j+1]*val[k+1])
                  {
                      if(i==k&&i==0)
                        cout<<char('A'+i);
                        if(i==k&&i!=0)
                        cout<<char('A'+i);
                        if(k-i==1&&i!=0)
                        {
                            cout<<"("<<char('A'+i)<<"*"<<char('A'+k)<<')';
                        }
                        if(k-i==1&&i==0)
                        {
                            cout<<"("<<char('A'+i)<<"*"<<char('A'+k)<<')';
                        }

                      if(k-i>1&&i!=0)
                      {
                          order(val,arr,i,k);
                      }
                      if(k-i>1&&i==0)
                      {
                          order(val,arr,i,k);

                      }
                      if(j-k-1>1&&j!=N-1)
                   {

                       order(val,arr,k+1,j);

                  }
                      if(j-k-1>1&&j==N-1)
                   {

                       order(val,arr,k+1,j);

                  }
                  if(k+1==j&&j!=N-1)
                    cout<<'*'<<char('A'+j);
                    if(k+1==j&&j==N-1)
                    cout<<'*'<<char('A'+j);
                    if(j-k-1==1&&j==N-1)
                    {
                          cout<<"*("<<char('A'+k+1)<<"*"<<char('A'+j)<<")";
                    }
                    if(j-k-1==1&&j!=N-1)
                    {
                          cout<<"*("<<char('A'+k+1)<<"*"<<char('A'+j)<<")";
                    }
                    break ;
                  }
              }
              cout<<")";
}
int main()
{
    int n,i,j,k;

    printf("Enter the no of matrices\n");
    scanf("%d",&n);
    int val[n+1];
    printf("Enter the matrix sizes\n");
    for(i=0;i<=n;i++)
    {
        cin>>val[i];
    }
    int arr[N][N];
    if(n!=1)
    for(i=0;i<n;i++)
    {
        for(j=0;j+i<n;j++)
        {
            if(i==0)
                arr[j][j]=0;
            else
            {
                arr[j][j+i]=1000000000;
                for(k=0;j+k<j+i;k++)
                {

                    arr[j][j+i]=min(arr[j][j+i],arr[j][j+k]+arr[j+k+1][j+i]+val[j]*val[j+i+1]*val[j+k+1]);
                }
            }
        }
    }
    else
        arr[0][0]=val[0]*val[1];
    cout<<"Minimum multiplication possible is "<<arr[0][n-1]<<endl;

    order(val,arr,0,n-1);

}

