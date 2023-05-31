#include<stdio.h>
#include<stdlib.h>
#define MAX 5
typedef struct queue
{
    int front;
    int items[MAX];
    int rear;
}*QUEUE;
int isFull(QUEUE q);
int isEmpty(QUEUE q);
void enqueue(QUEUE q,int e);
void dequeue(QUEUE q);
void display(QUEUE q);
void initqueue(QUEUE q);
void main()
{
    int ch;
    int e;
    struct queue q;
    initqueue(&q);
    while(1)
    {
        printf("1.ENQUEUE\n");
        printf("2.DEQUEUE\n");
        printf("3.DISPLAY\n");
        printf("4.EXIT\n");
        printf("ENTER YOUR CHOICE\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:printf("ENTER THE ELEMENT\n");
                   scanf("%d",&e);
                   enqueue(&q,e);
                   break;
            case 2:dequeue(&q);
                   break;
            case 3:display(&q);
                   break;
            case 4:exit(0);   
        }

    }
}
int isFull(QUEUE q)
{
    return q->front==(q->rear+1)%MAX;
}
int isEmpty(QUEUE q)
{
    if(q->rear==-1)
     return 1;
     return 0;
}
void enqueue(QUEUE q,int e)
{
    if(isFull(q))
    {
        printf("QUEUE FULL\n");
        return;
    }
    if(q->front==-1)
    {
        q->front++;
    }
    q->rear=(q->rear+1)%MAX;
    q->items[q->rear]=e;
    return;
}
void dequeue(QUEUE q)
{
    int e;
    if(isEmpty(q))
    {
        printf("QUEUE EMPTY\n");
        return;
    }
    else
    {
     e=q->items[q->front];
     if(q->front==q->rear)
     {
      q->front=-1;
      q->rear=-1;
     }
     else
     {
        q->front=(q->front+1)%MAX;
     }
    }
    printf("%d\n",e);
    return;

}
void initqueue(QUEUE q)
{
    q->front=-1;
    q->rear=-1;
}
void display(QUEUE q)
{
    int i;
    if(isEmpty(q))
    {
        printf("QUEUE IS EMPTY\n");
        return;
    }
    for(i=q->front;i!=q->rear;i=(i+1)%MAX)
    {
        printf("%d ",q->items[i]);
    }
    printf("%d\n",q->items[i]);

}