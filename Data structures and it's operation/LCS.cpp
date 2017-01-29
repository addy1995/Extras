#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{
    char result[30];
char str1[30];
int i=0,j=0,n=0,m=0;
char str2[30];
cout<<"Enter the string 1 and string 2\n";
scanf("%s%s",str1,str2);
while(str1[n]!='\0')
    n++;
while(str2[m]!='\0')
    m++;
    int arr[n+1][m+1];
    for(i=0;i<=n;i++)
    {
        for(j=0;j<=m;j++)
        {
            if(i==0||j==0)
                arr[i][j]=0;
            else if(str1[i-1]==str2[j-1])
                arr[i][j]=1+arr[i-1][j-1];
            else
                arr[i][j]=max(arr[i-1][j],arr[i][j-1]);
        }
    }
    cout<<"Length of LCS is ";
    cout<<arr[n][m]<<endl;
    int index=arr[n][m];
    i=n;j=m;
    result[index]='\0';
    while(i>0&&j>0)
    {
        if(str1[i-1]==str2[j-1])
        {
            result[index-1]=str2[j-1];
            i--;j--;index--;
        }
        else if(arr[i-1][j]>arr[i][j-1])
            i--;
        else
            j--;
    }
    cout<<"LCS is "<<result;
}
