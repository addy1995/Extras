#include<iostream>
#include<stdio.h>
#include<string>
using namespace std;
int main()
{
    int n,len,i,j,k;
    scanf("%d",&len);
    int sx,sy;
    int ex,ey;
    scanf("%d%d",&sx,&sy);
    scanf("%d%d",&ex,&ey);
    int num;
    scanf("%d",&num);
    cout<<sx<<sy<<ex<<ey<<num;


    for(i=0;i<=num;i++)
    {
        for(j=0;j<=len;j++)
        {
            for(k=0;k<=len;k++)
            {
                arr[i][j][k]=0;
            }
        }
    }
    arr[0][sx+1][sy+1]=1;
    for(i=1;i<=num;i++)
    {
        for(j=1;j<=len;j++)
        {
            for(k=1;k<=len;k++)
            {

                if(arr[i-1][j][k]!=0)
                {
;                    if(j>1)
                    {
                        arr[i][j-1][k]+=arr[i-1][j][k];
                        if(k>1)
                        {
                            arr[i][j-1][k-1]+=arr[i-1][j][k];
                            arr[i][j][k-1]+=arr[i-1][j][k];
                        }
                        if(k<len)
                        {
                            arr[i][j-1][k+1]+=arr[i-1][j][k];
                            arr[i][j][k+1]+=arr[i-1][j][k];
                        }
                    }
                    else
                    {
                        if(k>1)
                        {
                            arr[i][j][k-1]+=arr[i-1][j][k];
                        }
                        if(k<len)
                        {
                            arr[i][j][k+1]+=arr[i-1][j][k];
                        }
                    }
                    if(j<len)
                    {
                        arr[i][j+1][k]+=arr[i-1][j][k];
                        if(k>1)
                        {
                            arr[i][j+1][k-1]+=arr[i-1][j][k];
                        }
                        if(k<len)
                        {
                            arr[i][j+1][k+1]+=arr[i-1][j][k];
                        }
                    }
                    if(j>2)
                    {
                        if(k>1)
                        arr[i][j-2][k-1]+=arr[i-1][j][k];
                        if(k<len)
                            arr[i][j-2][k+1]+=arr[i-1][j][k];
                    }

                    if(j<len-1)
                    {
                        if(k>1)
                        arr[i][j+2][k-1]+=arr[i-1][j][k];
                        if(k<len)
                            arr[i][j+2][k+1]+=arr[i-1][j][k];
                    }
                    if(k>2)
                    {
                        if(j>1)
                        arr[i][j-1][k-2]+=arr[i-1][j][k];
                        if(j<len)
                            arr[i][j+1][k-2]+=arr[i-1][j][k];

                    }
                    if(k<len-1)
                    {
                        if(j>1)
                        arr[i][j-1][k+2]+=arr[i-1][j][k];
                        if(j<len)
                            arr[i][j+1][k+2]+=arr[i-1][j][k];

                    }
                }
            }
        }
    }
    printf("%lld",arr[num][ex+1][ey+1]);

}
