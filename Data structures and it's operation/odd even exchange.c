#include<stdio.h>
main()
{int a[11],b,c,n,temp;
scanf("%d",&n);
for(b=0;b<n;b++)
{scanf("%d",&a[b]);
}
if(n%2==0)
{
for(b=0;b<n;b+=2)
{
	temp=a[b];
	a[b]=a[b+1];
	a[b+1]=temp;	
}
}
else
{
for(b=0;b<n;b+=2)
{
	temp=a[b];
	a[b]=a[b+1];
	a[b+1]=temp;	
}
	
	
}
for(b=0;b<n-1;b++)
{printf("%d\n",a[b]);
}



}
