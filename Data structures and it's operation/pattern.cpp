#include<stdio.h>
main()
{int a,b,c=1,d,e;
for(a=1;a<=4;a++)
{
for(b=4;b>a;b--)
printf(" ");

for(b=1;b<=2*a-1;b++)
{
printf("*");
}
printf("\n");
}
for(a=1;a<4;a++)
{
for(b=1;b<=a;b++)
printf(" ");

for(b=6;b>2*a-1;b--)
{
printf("*");
}
printf("\n");
}
	
}
