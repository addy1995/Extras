#include<stdio.h>
#define max 5
struct queue
{
    int arr[max];
    int front,rear;
};
void createqueue(struct queue *q)
{
    q->front=q->rear=-1;
}
int isfull(struct queue *q)
{
    return q->front==0&&q->rear==max-1;
}
int isempty(struct queue *q)
{
    return q->front==-1;
}
void enqueue(struct queue *q,int item)
{
    if(q->front==-1)
    {
        q->front=0;
    }

    if(isfull(q))
    {
        printf("queue full");
        return;
    }
    else if(q->rear==max-1)
    {
        int i;
        for(i=q->front;i<=q->rear;i++)
        {
            q->arr[i-q->front]=q->arr[i];
        }
        q->rear=q->rear-q->front+1;
        q->front=0;
    }
    else
    {
        q->rear++;

    }
    q->arr[q->rear]=item;

}
int dequeue(struct queue *q)
{
    if(isempty(q))
    {
        printf("queue is empty");
        return -1;
    }
    int temp;
    if(q->front==q->rear)
    {
        temp=q->arr[q->front];
        q->front=q->rear=-1;
        return temp;
    }
    else
    {
        temp=q->arr[q->front++];
        return temp;
    }
}
void print(struct queue *s)
{
    int i;
    for(i=s->front;i<=s->rear;i++)
    {
        printf("%d ",s->arr[i]);
    }
}
int main()
{
    struct queue s;
    createqueue(&s);
    enqueue(&s,5);
    enqueue(&s,51);
    enqueue(&s,10);
    print(&s);
    printf("\ndeleting element %d\n",dequeue(&s));;
    print(&s);
    return 0;
}
