#include<stdio.h>
main()
{int a,f,e,b,c,d=1,n,m;
scanf("%d%d",&n,&m);
f=n-1;
for(a=1;a<=n;a++)
{e=a-2;
for(b=1;b<=m;b++)
{for(c=1;c<a;c++)
printf(" ");
printf("*");
for(c=2*f-1;c>=d;c--)
printf(" ");
if(a!=1&&a!=n)
printf("*");
if(a==1&&b==m)
printf("*");
for(c=1;c<=e;c++)
printf(" ");
}
d+=2;
printf("\n");
}

}
