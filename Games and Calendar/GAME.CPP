#include<iostream.h>
#include<conio.h>
void main()
{int a=21,b,c;
clrscr();
while(a>0)
{cout<<"\nPick ( 1,2,3 or 4) matchsticks only ";
back:
cin>>b;
if(!(b>=1&&b<=4))
{
cout<<"Enter valid input";
goto back;}
a=a-b;
if(a==1)
{cout<<"Last stick is left so computer loses";
break;
 }
cout<<"We have left with "<<a<<" matchsticks\nNow computer's turn\n";
getch();
c=a;
if(a-4==16)
a=a-4;
else if(a-3==16)
a=a-3;
else if(a-2==16)
a=a-2;
else if(a-1==16)
a=a-1;
else if(a-4==11)
a=a-4;
else if(a-3==11)
a=a-3;
else if(a-2==11)
a=a-2;
else if(a-1==11)
a=a-1;
else if(a-4==6)
a=a-4;
else if(a-3==6)
a=a-3;
else if(a-2==6)
a=a-2;
else if(a-1==6)
a=a-1;
else if(a==4)
a=a-3;
else if(a==3)
a=a-2;
else if(a==2)
a=a-1;
else
a=a-4;
if(a==1)
{
cout<<"Computer picked "<<c-a<<" sticks out of "<<c<<" sticks leaving only 1 stick so \n             YOU LOST";
break;
 }
else
cout<<"Computer picked "<<c-a<<" sticks\n";
cout<<"Now we are left with "<<a<<" matchsticks \n\nYour's turn again";

}
getch();
}