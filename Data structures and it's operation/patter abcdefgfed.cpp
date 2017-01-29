#include<stdio.h>
main()
{int i,j,c,d;
for(i=0;i<=6;i++)
{for(j=65;j<=71-i;j++)
printf("%c",j);
for(j=0;j<2*i-1;j++)
printf(" ");

if(i==1)
{i=0;
for(j=70-i;j>=65;j--)
printf("%c",j);
i=1;}
else if(i==0){
for(j=70-i;j>=65;j--)
printf("%c",j);
}
else
{
for(j=71-i;j>=65;j--)
printf("%c",j);
}
printf("\n");}

}
