#include<iostream>
#include<conio.h>
int getkey()
{
 int ch;
 ch=getch();
 if(ch==0)
 {
  ch=getch();
  return ch;
 }
 return ch;
}
main()
{int l=0,a[4][4]={{1,4,15,7},{8,10,2,11},{14,3,6,13},{12,9,5,0}},c=0,x=33,y=13,i,j,k=0,var,var1=0,var2=0;
clrscr();
while(1)
{back:
 l=0;
 for(j=0;j<15;j++)
 {
  if((*(*a+j)<*(*a+j+1)))
  {
   if(j==14)
   {c=1;
   break;}
  }
  else
  break;
 }

 if(c==1)
 {
  gotoxy(28,20);
  cout<<"solved" ;
  break;
 }
 for(i=0;i<4;i++)
 {
  gotoxy(25,10+i);
  cout<<"                   ";
  gotoxy(25,10+i);
  for(j=0;j<4;j++)
  {if(a[i][j]==0)
   cout<<"   ";
   else if(a[i][j]>9)
   cout<<a[i][j]<<" ";
   else
   cout<<a[i][j]<<"  ";
  }
  cout<<endl;
 }
 for(i=0;i<4;i++)
  {
   for(j=0;j<4;j++)
   {
    if(a[i][j]==0)
    {
     l=1;
     break;
    }
   }
   if(l==1)
   break;
  }
  l=0;
  gotoxy(25+3*j,10+i);
 //gotoxy(x,y);
 var=getkey();
 if(var=='e')
 break;
 else if(var==80)
 {
  for(i=0;i<4;i++)
  {
   for(j=0;j<4;j++)
   {
    if(a[i][j]==0)
    {
     l=1;
     break;
    }
   }
   if(l==1)
   break;
  }
  l=0;
  if(i<3)
  {a[i][j]=a[i+1][j];
  a[i+1][j]=0;
  }
  else
  {
   gotoxy(28,20);
   cout<<"not possible press enter and choose again";
   getch();
   gotoxy(28,20);
   cout<<"                                         ";
   //goto back;
  }
  var2=-1;
  var1=0 ;
 }
 else if(var==72)
 {
  for(i=0;i<4;i++)
  {
   for(j=0;j<4;j++)
   {
    if(a[i][j]==0)
    {
     l=1;
     break;
    }
   }
   if(l==1)
   break;
  }
  l=0;
  if(i>0)
  {
   a[i][j]=a[i-1][j];
   a[i-1][j]=0;
  }
  else
  {
   gotoxy(28,20);
   cout<<"not possible press enter and choose again";
   getch();
   gotoxy(28,20);
   cout<<"                                         ";
   //goto back;
  }
  var2=1;
  var1=0;
 }
 else if(var==77)
 {
  for(i=0;i<4;i++)
  {
   for(j=0;j<4;j++)
   {
    if(a[i][j]==0)
    {
     l=1;
     break;
     }
   }
   if(l==1)
   break;
  }
  l=0;
  if(j<3)
  {
   a[i][j]=a[i][j+1];
   a[i][j+1]=0;
  }
  else
  {
   gotoxy(28,20);
   cout<<"not possible press enter and choose again";
   getch();
   gotoxy(28,20);
   cout<<"                                         ";
  // goto back;
  }
  var1=-1;
  var2=0;
 }
 else if(var==75)
 {
  for(i=0;i<4;i++)
  {
   for(j=0;j<4;j++)
   {
    if(a[i][j]==0)
    {l=1;
     break;
    }
   }
   if(l==1)
   break;
  }
  l=0;
  if(j>0)
  {a[i][j]=a[i][j-1];
   a[i][j-1]=0;
  gotoxy(28,20);
  cout<<i<<" "<<j;
  gotoxy(28,20);
  cout<<"        ";
  }
  else
  {
   gotoxy(28,20);
   cout<<"not possible press enter and choose again";
   getch();
   gotoxy(28,20);
   cout<<"                                         ";
   //goto back;
  }
  var1=1;
  var2=0;
 }
// cout<<k;
 x=x+var1;
 y=y+var2;
 k++;
}
 getch();
}
