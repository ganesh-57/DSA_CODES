#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
 int data;
 struct node *next;
}*NODE;
NODE getnode(void);
NODE addAtbeg(NODE head,int a);
NODE addAtend(NODE head,int a);
void display(NODE head);
NODE deleteAtbeg(NODE head);
NODE deleteAtend(NODE head);
void main()
{
int ch;
    int ele;
    NODE head=NULL;
    while(1)
    {
        printf("1.ADD AT BEGINNING\n");
        printf("2.ADD AT END\n");
        printf("3.DISPLAY\n");
        printf("4.DELETE AT END\n");
        printf("5.DELETE AT FRONT\n");
        printf("6.EXIT\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:printf("ENTER THE ELEMENT:");
                   scanf("%d",&ele);
                   head=addAtbeg(head,ele);
                   break;
            case 2:printf("ENTER THE ELEMENT:");
                   scanf("%d",&ele);
                   head=addAtend(head,ele);
                   break;
            case 3:display(head);
                   break;
            case 4:head=deleteAtend(head);
                   break;
            case 5:head=deleteAtbeg(head);
                   break;
            case 6:exit(0);

        }
    }
}
NODE getnode(void)
{
    NODE p=(struct node *)malloc(sizeof(struct node));
    if(p==NULL)
    {
     printf("insufficient memory\n");
     return NULL;
    }
    p->next=p;
    return p;
}
NODE addAtbeg(NODE head,int a)
{
    NODE p=getnode();
    p->data=a;
    if(head==NULL)
    {
        head=p;
        return head;
    }
    NODE temp=head;
    while(temp->next!=head)
    {
        temp=temp->next;
    }
    temp->next=p;
    p->next=head;
    head=p;
    return head;
}
NODE addAtend(NODE head,int a)
{
    NODE p=getnode();
    p->data=a;
    if(head==NULL)
    {
        head=p;
        return head;
    }
    NODE temp=head;
    while(temp->next!=head)
    {
        temp=temp->next;
    }
    p->next=head;
    temp->next=p;
    return head;
}
void display(NODE head)
{
    NODE temp=head;
    if(head==NULL)
    {
        printf("LIST IS EMPTY\n");
        return;
    }
    while(temp->next!=head)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("%d\n",temp->data);
    return;
}
NODE deleteAtend(NODE head)
{
    if(head==NULL)
    {
        printf("LIST IS EMPTY\n");
        head=NULL;
        return head;
    }
    if(head->next==head)
    {
        free(head);
        head=NULL;
        return head;
    }
    NODE temp=head;
    NODE cur=NULL;
    while(temp->next!=head)
    {
     cur=temp;
     temp=temp->next;
    }
    cur->next=head;
    free(temp);
    return head;
    
}
NODE deleteAtbeg(NODE head)
{
    if(head==NULL)
    {
        printf("LIST IS EMPTY\n");
        head=NULL;
        return head;
    }
    if(head->next==head)
    {
        free(head);
        head=NULL;
        return head;
    }
    NODE temp=head;
    while(temp->next!=head)
    {
        temp=temp->next;
    }
    temp->next=head->next;
    free(head);
    head=temp->next;
    return head;
}