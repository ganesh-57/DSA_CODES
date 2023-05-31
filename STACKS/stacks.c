#include<stdio.h>
#include<stdlib.h>
#define MAX 5
typedef struct stack
{
    int top;
    int items[MAX];
}*STACK;
int isFull(STACK s);
void initstack(STACK s);
void push(STACK s,int e);
void pop(STACK s);
int isEmpty(STACK s);
void peek(STACK s);
void main()
{
    int ch;
    int e;
    struct stack s;
    initstack(&s);
    while(1)
    {
        printf("1.PUSH\n");
        printf("2.POP\n");
        printf("3.PEEK\n");
        printf("4.EXIT\n");
        printf("ENTER YOUR CHOICE\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:printf("ENTER THE ELEMENT\n");
                   scanf("%d",&e);
                   push(&s,e);
                   break;
            case 2:pop(&s);
                   break;
            case 3:peek(&s);
                   break;
            case 4:exit(0);   
        }

    }
}
int isFull(STACK s)
{
    return s->top==MAX-1;
}
void initstack(STACK s)
{
    s->top=-1;
}
int isEmpty(STACK s)
{
    return s->top==-1;
}
void push(STACK s,int e)
{
if(isFull(s))
{
    printf("STACK FULL\n");
    return;
}
s->items[++s->top]=e;
return;
}
void pop(STACK s)
{
    if(isEmpty(s))
    {
    printf("STACK EMPTY\n");
    return;
    }
    int e;
    e=s->items[s->top--];
    printf("\n%d\n",e);
    return;

}
void peek(STACK s)
{
    if(isEmpty(s))
    {
        printf("EMPTY STACK\n");
        return;
    }
        printf("%d\n",s->items[s->top]);
        return;
}

