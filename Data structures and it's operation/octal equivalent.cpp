#include<stdio.h>
main()
{int a,b,c,d,e=0,f=1;
printf("enter the no");
scanf("%d",&a);
while(a!=0)
{b=a%8;
e=b*f+e;
f=f*10;
a=a/8;
}
printf("%d",e);}
