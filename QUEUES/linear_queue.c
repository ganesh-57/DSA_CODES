#include<stdio.h>
#include<stdlib.h>
#define MAX 5
typedef struct queue
{
    int front;
    int items[MAX];
    int rear;
}*QUEUE;
void initqueue(QUEUE q);
int isempty(QUEUE q);
int isfull(QUEUE q);
void enqueue(QUEUE q,int e);
void dequeue(QUEUE q);
void display(QUEUE q);
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
void initqueue(QUEUE q)
{
    q->front=0;
    q->rear=-1;
}
int isempty(QUEUE q)
{
    return q->front>q->rear;
}
int isfull(QUEUE q)
{
    return q->rear==MAX-1;
}
void enqueue(QUEUE q,int e)
{
    if(isfull(q))
    {
        printf("QUEUE FULL\n");
        return;
    }
    
    q->items[++q->rear]=e;
    return;
}
void dequeue(QUEUE q)
{
    int e;
    if(isempty(q))
    {
        printf("EMPTY\n");
        return;
    }
    e=q->items[q->front++];
    printf("%d\n",e);
    return;

}
void display(QUEUE q)
{
    if(isempty(q))
    {
        printf("queue is empty\n");
        return;
    }
    int i;
    for(i=q->front;i<=q->rear;i++)
    {
        printf("%d ",q->items[i]);
    }
    printf("\n");
}
