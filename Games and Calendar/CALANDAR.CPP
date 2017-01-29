#include<iostream.h>
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
{int key,a=0,x=18,y=11,cd=1,cm=1,cy=1900,i,count=1,year,month1;
int month[31];
char month2[12][20]={"January","February","March","April","May","June","July","August","September","October","November","December"};
clrscr();
cout<<"Enter Month : "<<"\n1.January\n2.February\n3.March\n4.April\n5.May\n6.June\n7.July\n8.August\n9.September\n10.October\n11.November\n12.December\n";
back1:
cin>>month1;
if(!(month1>=1&&month1<=12))
{
cout<<"Invalid Option choose again";
month1=0;
goto back1;
}
cout<<"Enter Year(>=1900) : ";
back2:
cin>>year;
if(year<1900)
{
cout<<"<1900 enter again";
goto back2;
year=0;
}
back:
cd=1;cm=1;cy=1900;count=1;a=0;
clrscr();
while(1)
{
if(cm==month1&&cy==year)
break;
for(int i=1;i<=7;i++)
{
if((cd==28&&cm==2&&cy%4!=0)||(cy==1900&&cm==2&&cd==28))
{
cd=0;
cm++;
}
else if(cd==29&&cm==2&&cy%4==0)
{cd=0;
cm++;
}
else if(cd==30&&(cm==4||cm==6||cm==9||cm==11))
{
 cd=0;
 cm++;
}
else if(cd==31&&(cm==1||cm==3||cm==5||cm==7||cm==8||cm==10||cm==12))
{
cd=0;
cm++;
}
if(cm==13)
{cy++;
cm=1;
}
cd++;
}
}
clrscr();
while(1)
{
gotoxy(37,8);
cout<<month2[month1-1]<<" "<<year<<"\n";
cout<<"\t\tMon\tTues\tWed\tThu\tFri\tSat\tSun\n\n";
for(int i=1;i<=6;i++)
{gotoxy(18,10+i);
 if(i==1)
 {
  for(int j=cd;j<8;j++)
  {
   cout<<"\t";
  }
 for(j=1;j<=cd-1;j++)
 {
  cout<<count<<"\t";
  count++;
 }
}
else
{
for(int j=1;j<=7;j++)
{cout<<count<<"\t";

if((count==28&&month1==2&&year%4!=0)||(cy==1900&&month1==2&&count==28))
{
 a=1;
 break;
}
else if(count==29&&month1==2&&year%4==0)
{a=1;
 break;
}
else if(count==30&&(month1==4||month1==6||month1==9||month1==11))
{a=1;
 break;
}
else if(count==31&&(month1==1||month1==3||month1==5||month1==7||month1==8||month1==10||month1==12))
{
 a=1;
 break;
}
++count;
}
}
cout<<endl;
if(a==1)
break;
}
count=1;
gotoxy(x,y);
if(key==27)
break;
key=getkey();
if(key==77)
{
  if(x+8>66)
  {
   month1++;
   if(month1==13)
   {
    month1=1;
    year++;
   }
   goto back;
  }
  else
  x=x+8;

}
else if(key==75)
{
  if(x-8<18)
  {
   month1--;
   if(month1==0)
   {
    year--;
    if(year==1899)
    {year=1900;
    month1=1;
    }
    else
    month1=12;
   }
   goto back;
  }
  else
  x=x-8;

}
else if(key==80)
{if(y+1<=16)
y=y+1;
}
else if(key==72)
{if(y-1>=11)
y=y-1;
}
gotoxy(10,20);
cout<<x<<" "<<y;
}
getch();
}
