#include<iostream>
using namespace std;
int main()
{
    int spar1[4][4]={0,0,1,0,3,1,0,1,0,1,0,0,0,0,0,1};
    int spar2[4][4]={1,0,0,0,0,5,0,0,0,0,0,0,1,0,0,0};
    int count1=1;
    int count2=1;
    int arr[9][3];
    int arr1[9][3];
    int arr2[9][3];
    int i=0,j=0;
    arr[0][0]=4;
    arr[0][1]=4;
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            if(spar1[i][j]!=0)
            {
                count1++;
                arr[count1-1][0]=i;
                arr[count1-1][1]=j;
                arr[count1-1][2]=spar1[i][j];
            }
        }

    }
    arr[0][2]=count1;
    arr1[0][0]=4;
    arr1[0][1]=4;
    for(i=0;i<count1;i++)
    {
        for(j=0;j<3;j++)
        {
            cout<<arr[i][j]<<" ";

        }
        cout<<endl;
    }
    cout<<endl;
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            if(spar2[i][j]!=0)
            {
                count2++;
                arr1[count2-1][0]=i;
                arr1[count2-1][1]=j;
                arr1[count2-1][2]=spar2[i][j];
            }
        }

    }

    arr1[0][2]=count2;
    for(i=0;i<count2;i++)
    {
        for(j=0;j<3;j++)
        {
            cout<<arr1[i][j]<<" ";

        }
        cout<<endl;
    }
    cout<<endl;
        j=1;
        int k=1;
    for(i=0;i<9;i++)
    {
        if(i==0)
        {
            arr2[i][0]=4;
            arr2[i][1]=4;
            arr2[i][2]=9;
        }
        else
        {
            if(arr[j][0]==arr1[k][0])
            {
                if(arr[j][1]==arr1[k][1])
                {
                    arr2[i][0]=arr1[k][0];
                    arr2[i][1]=arr1[k][1];
                    arr2[i][2]=arr1[k][2]+arr[j][2];
                    k++;
                    j++;
                }
                else if(arr[j][1]>arr1[k][1])
                    {
                    arr2[i][0]=arr1[k][0];
                    arr2[i][1]=arr1[k][1];
                    arr2[i][2]=arr1[k][2];
                    k++;
                    }
                    else
                    {

                    arr2[i][0]=arr[j][0];
                    arr2[i][1]=arr[j][1];
                    arr2[i][2]=arr[j][2];
                    j++;
                    }
            }
            else if(arr[j][0]>arr1[k][0])
            {
                 arr2[i][0]=arr1[k][0];
                 arr2[i][1]=arr1[k][1];
                 arr2[i][2]=arr1[k][2];
                 k++;
            }
            else
            {
                 arr2[i][0]=arr[j][0];
                 arr2[i][1]=arr[j][1];
                 arr2[i][2]=arr[j][2];
                 j++;
            }
        }
    }
    for(i=0;i<9;i++)
    {
        for(j=0;j<3;j++)
        {
            cout<<arr2[i][j]<<" ";

        }
        cout<<endl;
    }


}
