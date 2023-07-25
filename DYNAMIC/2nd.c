#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<strings.h>

typedef struct data
{
    char roboid[30];
    int task;
    int th;

}DATA;
typedef struct node
{
    struct node *prev;
    DATA D;
    struct node *next;
}*NODE;
NODE getnode(void);
void read(DATA *s);
NODE addatend(NODE head,DATA s);
void display(NODE head);
NODE fun(NODE head,int new,char roboid[30]);
int main()
{
    int n;
    NODE head=NULL;
    DATA S;
    int new;
    char str[30];
    printf("enter the number of robots\n");
    scanf("%d",&n);
    int i;
    for(i=0;i<n;i++)
    {
     read(&S);
     head=addatend(head,S);

    }
    display(head);
    for(i=0;i<3;i++)
    {
    printf("ROBOID:");
    scanf("%s",str);
    printf("enter the new task:");
    scanf("%d",&new);
    head=fun(head,new,str);
    display(head);
    }
    



}
NODE getnode(void)
{
    NODE p;
    p=(NODE)malloc(sizeof(struct node));
    if(p==NULL)
    {
        printf("insufficient memory\n");
        return 0;
    }
    p->prev=p;
    p->next=p;
    return p;
}
void read(DATA *s)
{
 printf("enter the robo ID\n");
 scanf("%s",s->roboid);
 printf("enter the task\n");
 scanf("%d",&s->task);
 printf("enter the threshold\n");
 scanf("%d",&s->th);
}
NODE addatend(NODE head,DATA s)
{
    NODE cur=head;
    NODE a=getnode();
    a->D=s;
    if(head==NULL)
    {
        return a;
    }
    if(head->next==head)
    {
        a->next=head->next;
        head->next=a;
        a->prev=head;
        head->prev=a;
        return head;
    }
    while(cur->next!=head)
    {

    cur=cur->next;

    }
    a->next=cur->next;
    a->prev=cur;
    cur->next=a;
    head->prev=a;
    return head;
}
void display(NODE head)
{
    NODE cur=head;
    if(head==NULL)
    {
        printf("list is empty\n");
        return;
    }
    printf("ROBO ID\tTASK\tTH");
    printf("\n");
    while(cur->next!=head)
    {
        printf("%s\t%d\t%d",cur->D.roboid,cur->D.task,cur->D.th);
        printf("\n");
        cur=cur->next;

    }
    printf("%s\t%d\t%d",cur->D.roboid,cur->D.task,cur->D.th);
    printf("\n");


}
NODE fun(NODE head,int new,char roboid[30])
{
 NODE cur=head;
 NODE prev=head->prev;
 NODE next=head->next;
if(head==NULL)
{
    printf("list is empty\n");
    head=NULL;
    return head;

}
if(head->next==head)
{
 if(strcasecmp(head->D.roboid,roboid)==0)
 {
    if(head->D.th>=new+head->D.task)
    {
        head->D.task=new+head->D.task;
        return head;
    }
    else
    {
        printf("robo  not found and single node\n");
        return head;
    }
 }



}
while(cur->next!=head)
{
    if(strcasecmp(cur->D.roboid,roboid)==0)
    {
        if(cur->D.th>=cur->D.task+new)
        {
            cur->D.task=cur->D.task+new;
            return head;
        }
        if(cur->D.th<cur->D.task+new)
        {
          if(prev->D.th>=prev->D.task+new)
          {
            prev->D.task=prev->D.task+new;
            return head;
          }
          if(next->D.th>=next->D.task+new)
          {
            next->D.task=next->D.task+new;
            return head;
          }
          

        }
    }
    prev=cur;
    cur=cur->next;
    next=cur->next;

}
if(strcasecmp(cur->D.roboid,roboid)==0)
{
    if(cur->D.th>=cur->D.task+new)
    {
        cur->D.task=cur->D.task+new;
        return head;
    }
    if(cur->D.th<cur->D.task+new)
        {
          if(prev->D.th>=prev->D.task+new)
          {
            prev->D.task=prev->D.task+new;
            return head;
          }
          if(next->D.th>=next->D.task+new)
          {
            next->D.task=next->D.task+new;
            return head;
          }

    
        }
}
printf("NOT found such robo\n");
return head;


}








