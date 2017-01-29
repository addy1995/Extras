#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<vector>
#define N 3
using namespace std;
struct node
{
    char ch;
    struct node * left;
    struct node * right;
};
int root;/*
queue<struct btree *> makequeue(struct btree * node,queue<struct btree*>  q)
{
    int i=0;

    if(node!=NULL)
    {

            if(node->left!=NULL)
            {
            q.push(node->left);
            }
            else
            {
                q.push(temp);
            }
            if(node->right!=NULL)
            {
                q.push(node->right);
            }
            else
            {
                q.push(temp);
            }

            if(node->left!=NULL)
            {
            q.push(node->left);
            }
            else
            {
                q.push(temp);
            }
            if(node->right!=NULL)
            {
                q.push(node->right);
            }
            else
            {
                q.push(temp);
            }


        return q;
    }
}
void printbtree(struct node * node,queue <struct btree *> q)
{
    int i,j,k;

    data[0]=0;
    data1[0]=1;
    data2[0]=2;
    for(i=1;i<20;i++)
    {
        data[i]=data[i-1]+N+data2[i-1];
        data1[i]=3*data1[i-1];
        data2[i]=3*data2[i-1]+2*(N);
    }
    q.push(node);
    q=makequeue(node,q);
    struct btree * q1;
    int count=0;
    while((pow(N,count)-1)/2<q.size()-p)
    {
        count++;
    }
    for(i=1;i<=count;i++)
    {
        for(j=0;j<data[count-i];j++)
        cout<<"_";
        for(j=1;j<=data1[i-1];j++)
        {
            if(q.front()!=NULL)
            {
            q1=q.front();
            q.pop();
            }
            else
            {
                cout<<endl;
                return;
            }

//cout.width(3);
            if(q1->active!=-1)
            {


            for(k=1;k<=2;k++)
            {
                if(k<=q1->active)
                    cout<<q1->arr[k-1]<<' ';
                else
                {
                    cout<<"__";
                }
            }

                for(k=0;k<data2[count-i];k++)
                 cout<<"_";
            }
            else
            {
                for(k=1;k<=2;k++)
            {

                    cout<<"__";

            }

                for(k=0;k<data2[count-i];k++)
                 cout<<"_";
            }

        }

        cout<<endl;
    }

}*/
struct node * createnode(char ch)
{
    struct node * n=(struct node *)malloc(sizeof(struct node))        ;
    n->ch=ch;
    n->left=NULL;
    n->right=NULL;
    return n;
}
void tree(vector<int> r[N+1][N+1],int done[],int n,int i,int j,struct node * trees[])
{
    if(j==i)
    {
        j=n;i++;
    }
    if(i==n)
    {
        return;
    }
    int k=0,flagl=0,flagr=0;
    for(k=0;k<r[i][j].size();k++)
    {
        if(i==0&&j==n)
        {
            root=r[i][j][k]          ;

        }
        else if(i==0&&j!=n)
        {
            if(r[i][j+1][k]!=r[i][j][k])
            {
                if(trees[r[i][j+1][k]]->left==NULL)
                {
                    flagl=1;
                    trees[r[i][j+1][k]]->left=trees[r[i][j][k]]   ;
                }
            }

            tree(r,done,n,i,j-1,trees);
            if(r[i][j+1][k]!=r[i][j][k])
            {
                if(flagl==1)
                {
                    trees[r[i][j+1][k]]->left=NULL;
                    flagl=0;
                }
            }

        }
        else if(i!=0&&j==n)
        {
            if(r[i-1][j][k]!=r[i][j][k])
            {
                if(trees[r[i-1][j][k]]->right==NULL)
                {
                    flagr=1;
                    trees[r[i-1][j][k]]->right=trees[r[i][j][k]]               ;
                }
            }
            tree(r,done,n,i,j-1,trees);
            if(r[i-1][j][k]!=r[i][j][k])
            {
                if(flagr==1)
                {
                    flagr=0;
                    trees[r[i-1][j][k]]->right=NULL;
                }
            }
        }
        else
        {

            if(r[i][j+1][k]!=r[i][j][k])
            {
                if(trees[r[i][j+1][k]]->left==NULL)
                {
                    flagl=1;
                    trees[r[i][j+1][k]]->left=trees[r[i][j][k]]     ;
                }
            }
            if(r[i-1][j][k]!=r[i][j][k])
            {
                if(trees[r[i-1][j][k]]->right==NULL)
                {
                    flagr=1;
                    trees[r[i-1][j][k]]->right=trees[r[i][j][k]]               ;
                }
            }
            tree(r,done,n,i,j-1,trees);
            if(r[i][j+1][k]!=r[i][j][k])
            {
                if(flagl==1)
                {
                    trees[r[i][j+1][k]]->left=NULL;
                    flagl=0;
                }
            }
            if(r[i-1][j][k]!=r[i][j][k])
            {
                if(flagr==1)
                {
                    flagr=0;
                    trees[r[i-1][j][k]]->right=NULL;
                }
            }
        }
    }

}
int main()
{
    int i,t,flag,n,q,j,mini,k;
    cout<<"Enter the no of nodes\n";
    cin>>n;
    cout<<"Enter the characters and their corresponding frequency\n";
    pair <char,int> arr[n+1];
    for(i=1;i<=n;i++)
    {
       cin>>arr[i].first>>arr[i].second;
    }
    int p[n+1][n+1];
    for(i=0;i<=n;i++)
    {
        for(j=i;j<=n;j++)
        {
            if(i==j)
                p[i][i]=0;
            else
                p[i][j]=p[i][j-1]+arr[j].second;

        }
    }
    int w[n+1][n+1];
    vector<int> r[n+1][n+1];
    for(i=0;i<=n;i++)
    {
        for(j=0;j+i<=n;j++)
        {
            if(i==0)
         {
            r[j][j].push_back(0);
            w[j][j]=0;
        }
            else
            {
                mini=w[j][j+i-1]+w[j+i][j+i];
                for(k=j;k<j+i;k++)
                {
                    if(mini>=w[j][k]+w[k+1][j+i])
                    {
                        mini=w[j][k]+w[k+1][j+i];
                    }
                }
                for(k=j;k<j+i;k++)
                {
                    if(mini==w[j][k]+w[k+1][j+i])
                    {
                        r[j][j+i].push_back(0);
                    }
                }
                w[j][j+i]=p[j][j+i]+mini;
            }
        }
    }
    cout<<"Ans is "<<w[0][n]<<endl;
    int done[n];
    struct node *trees[n+1];
    for(i=0;i<=n;i++)
    {
        for(j=0;j<i;j++)
        {
            cout<<"  ";
        }
        for(j=i;j<=n;j++)
        {
            cout<<w[i][j]<<' ';
        }
        cout<<endl;
    }
    for(i=1;i<=n;i++)
    {
        trees[i]=createnode('A'+i-1);
    }
}
