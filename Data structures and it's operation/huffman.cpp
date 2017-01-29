#include<iostream>
#include<algorithm>
#include<stdio.h>
#include<queue>
using namespace std;
struct node
{
    char ch;
    float freq;
    struct node * left,*right;
};
struct node * createnode(char ch,float freq)
{
    struct node * n=(struct node *)malloc(sizeof(struct node));
    n->ch=ch;n->freq=freq;
    n->left=n->right=NULL;
    return n;
}
int print(struct node * n,char * str,int i)
{
    int j,k;
    if(n!=NULL)
    {
        str[i]='0';
        j=print(n->left,str,i+1);
        str[i]='1';
        k=print(n->right,str,i+1);
        str[i]='\0';
        if(j==1&&k==1)
        {
            cout<<"   "<<n->ch<<"     "<<n->freq<<"     "<<str<<endl;
        }
        return 2;

    }
    else
        return 1;
}
int main()
{
    int i;
    queue< struct node * > q1,q2;
    struct node * n1,*n2,*n3,*n4;
    pair<float,char> p;
    int n;
    cout<<"Enter the no of characters\n";
    cin>>n;
    cout<<"Enter the symbol and their frequency\n";
    vector<pair<float ,char> > temp;
    for(i=0;i<n;i++)
    {
        cin>>p.second>>p.first;
        temp.push_back(p);
    }
    sort(temp.begin(),temp.end());
    for(i=0;i<n;i++)
    {
        q1.push(createnode(temp[i].second,temp[i].first));
    }
    while(q1.size()>1||q2.size()>1||(q1.size()>0&&q2.size()>0))
    {
        if(q2.size()==0)
        {
            if(q1.front()!=NULL)
            n1=q1.front();
            q1.pop();
            if(q1.front()!=NULL)
            n2=q1.front();
            q1.pop();
        }
        else if(q1.size()==0)
        {
            if(q2.front()!=NULL)
            n1=q2.front();
            q2.pop();
            if(q2.front()!=NULL)
            n2=q2.front();
            q2.pop();
        }
        else
        {


            if(q1.size()!=0)
            n3=q1.front();
            if(q2.size()!=0)
            n4=q2.front();
            if(q1.size()==0)
            {
                n1=n4;
                q2.pop();
            }
            else if(q2.size()==0)
            {
                n1=n3;
                q1.pop();
            }
            else
            if(n3->freq<n4->freq)
            {
                n1=n3;
                q1.pop();
            }
            else
            {
                n1=n4;
                q2.pop();
            }
            if(q1.size()!=0)
            n3=q1.front();
            if(q2.size()!=0)
            n4=q2.front();
            if(q1.size()==0)
            {
                n2=n4;
                q2.pop();
            }
            else if(q2.size()==0)
            {
                n2=n3;
                q1.pop();
            }
            else
            if(n3->freq<n4->freq)
            {

                n2=n3;
                q1.pop();
            }
            else
            {
                n2=n4;
                q2.pop();
            }
        }
        n3=createnode('@',n1->freq+n2->freq);
        if(n1->freq<n2->freq)
        {
            n3->left=n1;
            n3->right=n2;
        }else
        {
            n3->left=n2;
            n3->right=n1;
        }
        q2.push(n3);
    }

    n4=q2.front();
    q2.pop();
    char *str;
    str[0]='\0';
    cout<<"Symbol Freq. code\n"
;    print(n4,str,0);
}
