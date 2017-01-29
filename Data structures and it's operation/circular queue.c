#include<stdio.h>
#define max 4
struct queue
{
    int arr[30];
    int rear,front;
};
void createqueue(struct queue *ptr)
{
    ptr->front=ptr->rear=-1;
}
int isfull(struct queue *ptr )
{
    if( ( ptr->front ==0 && ptr->rear ==max-1 ) || ( ptr->rear + 1 == ptr->front ) )
        return 1;
    else
        return 0;
}
int isempty(struct queue * ptr)
{
    return ptr->front==-1;
}
void enqueue(struct queue *ptr,int item)
{
    if(ptr->front==-1)
    {
        ptr->front=0;
    }
    else
    if(isfull(ptr))
    {
        printf("oerflow");
        return ;
    }
    if(ptr->rear==max-1)
    {
        ptr->rear=0;
    }
    else
    {
        ptr->rear++;
    }
    ptr->arr[ptr->rear]=item;

}
int dequeue(struct queue *q)
{
    int temp;
    if(isempty(q))
    {
        printf("underflow");
        return -1;
    }
    if(q->front==q->rear)
    {
        temp=q->arr[q->front];
        q->front=q->rear=-1;
    }
    else if(q->front==max-1)
    {
        temp=q->arr[q->front];
        q->front=0;
    }
    else
    {
        temp=q->arr[q->front++];
    }
        return temp;
}
void display(struct queue s)
{
    int i;
    if(s.front<s.rear)
    {
        for(i=s.front;i<=s.rear;i++)
        {
            printf("%d ",s.arr[i]);
        }
    }

}
int main()
{
    struct queue q;
    createqueue(&q);
    enqueue(&q,5);
    enqueue(&q,6);
    enqueue(&q,7);
    enqueue(&q,8);
    display(q);
    printf("\ndeleting element %d\n",dequeue(&q));
    enqueue(&q,10);
    printf("deleting element %d\n",dequeue(&q));
    return 0;
}
