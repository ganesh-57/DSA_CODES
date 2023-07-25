#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    struct node *prev;
    int data;
    struct node *next;
}*NODE;

NODE addAtbeg(NODE head,int a);
NODE addAtend(NODE head,int a);
void traverse_reverse(NODE head);
void display(NODE head);
NODE deleteAtend(NODE head);
NODE deleteAtbeg(NODE head);
NODE getNode(void);
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
        printf("4.DISPLAY REVERSE\n");
        printf("5.DELETE AT END\n");
        printf("6.DELETE AT FRONT\n");
        printf("7.EXIT\n");
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
            case 4:traverse_reverse(head);
                   break;
            case 5:head=deleteAtend(head);
                   break;
            case 6:head=deleteAtbeg(head);
                   break;
            case 7:exit(0);


        }
    }    
}
NODE getNode(void)
{
    NODE p=(struct node*)malloc(sizeof(struct node));
    if(p==NULL)
    {
        printf("INSUFFICIENT MEMORY\n");
        return NULL;
    }
    p->prev=NULL;
    p->next=NULL;
    return p;
}
NODE addAtbeg(NODE head,int a)
{
    NODE p=getNode();
    p->data=a;
    if(head==NULL)
    {
        head=p;
        return head;
    }
    p->next=head;
    head->prev=p;
    head=p;
    return head;

}
NODE addAtend(NODE head,int a)
{
    NODE p=getNode();
    p->data=a;
    if(head==NULL)
    {
        head=p;
        return head;
    }
    NODE temp=head;
    NODE cur=NULL;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=p;
    p->prev=temp;
    return head;
}
void display(NODE head)
{
    if(head==NULL)
    {
        printf("LIST IS EMPTY\n");
        return;
    }
    NODE temp=head;
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }    
    printf("\n");
    return;
}
void traverse_reverse(NODE head)
{
    if(head==NULL)
    {
        printf("LIST IS EMPTY\n");
        return;
    }
    NODE temp=head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    while(temp!=NULL)
    {
      printf("%d ",temp->data);
      temp=temp->prev;
    }
    printf("\n");
    return;
}
NODE deleteAtend(NODE head)
{
    if(head==NULL)
    {
        printf("list is empty\n");
        head=NULL;
        return head;
    }
    if(head->next==NULL)
    {
        free(head);
        head=NULL;
        return head;
    }
    NODE temp=head;
    NODE cur=NULL;
    while(temp->next!=NULL)
    {
        cur=temp;
        temp=temp->next;
    }
    free(temp);
    cur->next=NULL;
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
    if(head->next==NULL)
    {
        free(head);
        head=NULL;
        return head;
    }
    NODE temp=head->next;
    free(head);
    head=temp;
    head->prev=NULL;
    return head;
    
}