#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
}*NODE;

NODE add_at_beg();
NODE getNode(void);
NODE add_at_end(int a,NODE head);
NODE deleteAtbeg(NODE head);
NODE deleteAtend(NODE head);
void display(NODE head);
int countnodes(NODE head);
void main()
{
    int ch;
    int ele;
    NODE head=NULL;
    while(1)
    {
        printf("1.ADD AT BEGINNING\n");
        printf("2.ADD AT END\n");
        printf("3.DELETE AT END\n");
        printf("4.DELETE AT BEGINNING\n");
        printf("5.DISPLAY\n");
        printf("6.EXIT\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:printf("ENTER THE ELEMENT:");
                   scanf("%d",&ele);
                   head=add_at_beg(ele,head);
                   break;
            case 2:printf("ENTER THE ELEMENT:");
                   scanf("%d",&ele);
                   head=add_at_end(ele,head);
                   break;
            case 3:head=deleteAtend(head);
                   break;
            case 4:head=deleteAtbeg(head);
                   break;
            case 5:display(head);
                   break;
            case 6:exit(0);

        }
    }
}
NODE getNode(void)
{
  NODE p;
  p=(struct node*)malloc(sizeof(struct node));
  if(p==NULL)
  {
    printf("insufficient memory\n");
    return NULL;
  }
  else
  {
    p->next=NULL;
    return p;
  }
}
NODE add_at_beg(int a,NODE head)
{
    NODE p=getNode();
    p->data=a;
    if(head==NULL)
    {
       head=p;
       return head;
    }
    p->next=head;
    head=p;
    return head;
    
}
NODE add_at_end(int a,NODE head)
{
    NODE p=getNode();
    NODE temp=head;
    p->data=a;
    if(head==NULL)
    {
      head=p;
      return head;
    }
    while(temp->next!=NULL)
    {
        
        temp=temp->next;
    }
    temp->next=p;
    return head;

}
NODE deleteAtbeg(NODE head)
{
    if(head==NULL)
    {
        printf("list is empty\n");
        return NULL;
    }
    if(head->next==NULL)
    {
        free(head);
        head=NULL;
        return head;
    }
    NODE temp=head;
    temp=temp->next;
    free(head);
    head=temp;
    return head;
}
NODE deleteAtend(NODE head)
{
if(head==NULL)
{
    printf("list is empty\n");
    return NULL;
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
int countnodes(NODE head)
{
    if(head==NULL)
    {
        return 0;
    }
    int a=0;
    NODE temp=head;
    while(temp!=NULL)
    {
        temp=temp->next;
        a++;
    }
    return a;

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