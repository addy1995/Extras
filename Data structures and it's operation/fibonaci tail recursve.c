#include<stdio.h>
void fibo(int a,int b,int size)
{

   if(size==0)
        return;
   printf("%d ",b);
   fibo(b,a+b,size-1);


}
void main()
{
    int size;
    scanf("%d",&size);
    fibo(0,1,size);
}
