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
void dequeue(QUEUE q,int *a);
void display(QUEUE q);
void main()
{
int n;
int e;
struct queue q;
initqueue(&q);
FILE *fp;
printf("enter n:");
scanf("%d",&n);
fp=fopen("abc.txt","r");
for(int i=0;i<n;i++)
{
    fscanf(fp,"%d",&e);
    enqueue(&q,e);
}
fclose(fp);
fp=fopen("dequeued.txt","w");
for(int i=0;i<n;i++)
{
dequeue(&q,&e);
fprintf(fp,"%d ",e);
}
fclose(fp);
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
void dequeue(QUEUE q,int *a)
{
    int e;
    if(isempty(q))
    {
        printf("EMPTY\n");
        return;
    }
    *a=q->items[q->front++];
    printf("%d\n",*a);
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
