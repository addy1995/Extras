#include<stdio.h>
#define max 30
struct queue
{
    int arr[30];
    int front,rear;
};

void createqueue(struct queue *q)
{
    q->front=q->rear=-1;
}
int isempty(struct queue *q)
{
    if(q->front==-1)
        return 1;
    else
        return 0;
}
int isfull(struct queue *q)
{
    if((q->front==0&&q->rear==max-1)||(q->rear==q->front+1))
        return 1;
    else
        return 0;
}
void f_enqueue(struct queue *q,int item)
{
    if(q->rear==-1)
    {
        q->rear=max-1;
    }

    if(isfull(q))
    {
        printf("overflow\n");
        return ;
    }
    if(q->front==-1||q->front==0)
    {
        q->front=max-1;

    }
    else
    {
        q->front-=1;
    }
    q->arr[q->front]=item;


}
void r_enqueue(struct queue *q,int item)
{
    if(isfull(q))
    {
        printf("overflow");
        return;
    }
    if(q->front==-1)
    {
        q->front=0;
    }
    if(q->rear==max-1)
    {
        q->rear=0;
    }
    else
    {
        q->rear+=1;
    }
    q->arr[q->rear]=item;


}
int f_dequeue(struct queue * q)
{
    int temp;
    if(isempty(q))
    {
        printf("underflow");
        return -1;
    }
    temp=q->arr[q->front];
    if(q->rear==q->front)
    {
        q->rear=q->front=-1;
    }
    else
    if(q->front==max-1)
    {
        q->front=0;
    }
    else
    {
        q->front++;
    }
    return temp;
}
int r_dequeue(struct queue * q)
{
    int temp;
    if(isempty(q))
    {
        printf("underflow");
        return -1;
    }
    temp=q->arr[q->rear];
    if(q->rear==q->front)
    {
        q->rear=q->front=-1;
    }
    else if(q->rear==0)
    {
        q->rear=max-1;
    }
    else
    {
        q->rear--;
    }
    return temp;

}
int main()
{
    struct queue q;
    createqueue(&q);
    f_enqueue(&q,786);
    r_enqueue(&q,78);

    printf("%d ",r_dequeue(&q));
    printf("%d ",r_dequeue(&q));

    f_dequeue(&q);
    return 0;
}
