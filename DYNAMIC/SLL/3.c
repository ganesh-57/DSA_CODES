#include<stdio.h>
#include<stdlib.h>
typedef struct node 
{
    struct node *prv;
    int data;
    struct node *nxt;
}*NODE;
NODE getnode(void);
NODE add_at_beg(NODE head,int n);
NODE add_at_end(NODE head,int n);
NODE add_at_specific(NODE head,int n,int pos);
int count_nodes(NODE head);
void display(NODE head);
NODE delete_at_specific(NODE head,int pos);
int main()
{
    int pos;
    NODE head=NULL;
     int ch;
    int e;
    while(1)
    {
        printf("\n1.Add at beginning\n");
        printf("2.Add at end\n");
        printf("3.display\n");
        printf("4.Add at specific\n");
        printf("5.Delete at specific\n");
        printf("6.exit\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: printf("enter data:");
                    scanf("%d",&e);
                    head=add_at_beg(head,e);
                    break;
            case 2: printf("enter data:");
                    scanf("%d",&e);
                    head=add_at_end(head,e);
                    break;
            case 3: display(head);
                    break; 
            case 4: printf("enter pos:");
                    scanf("%d",&pos);
                    printf("enter data:");
                    scanf("%d",&e);
                    head=add_at_specific(head,e,pos);
                    break;
            case 5:printf("enter positon:");
                   scanf("%d",&pos);
                   head=delete_at_specific(head,pos);
                   break;
            case 6:exit(0);






        }
    }

}
NODE getnode(void)
{
    NODE p=(NODE)malloc(sizeof(struct node));
    if(p==NULL)
    {
        printf("insufficient memory\n");
        return p;
    }
    p->nxt=p;
    p->prv=p;
}
NODE add_at_beg(NODE head,int n)
{
 NODE temp=head;
 NODE p=getnode();
 p->data=n;
 if(head==NULL)
 {
    head=p;
    return head;
 }
 while(temp->nxt!=head)
 {
    temp=temp->nxt;
 }
 p->nxt=temp->nxt;
 temp->nxt=p;
 p->prv=temp;
 head->prv=p;
 head=p;
 return head;

}
NODE add_at_end(NODE head,int n)
{
    NODE temp;
    NODE p=getnode();
    p->data=n;
    if(head==NULL)
    {
        head=p;
        return head;
    }
    else
    {
        temp=head;
        while(temp->nxt!=head)
        {
            temp=temp->nxt;
        }
        p->nxt=temp->nxt;
        head->prv=p;
        temp->nxt=p;
        p->prv=temp;
        return head;
    }

}
void display(NODE head)
{
    NODE temp=head;
    if(head==NULL)
    {
        printf("empty list\n");
        return;
    }
    while(temp->nxt!=head)
    {
        printf("%d ",temp->data);
        temp=temp->nxt;
    }
    printf("%d ",temp->data);
}
NODE add_at_specific(NODE head,int n,int pos)
{
    NODE p=getnode();
    p->data=n;
    if(pos<1 && pos>count_nodes(head)+1)
    {
      printf("invalid position\n");
      return head;
    }
    if(pos==1)
    {
        head=add_at_beg(head,n);
        return head;
    }
    if(pos==count_nodes(head)+1)
    {
        head=add_at_end(head,n);
        return head;
    }   
    NODE temp=head;
    NODE prev=NULL;
    int i;
    for(i=1;i<pos;i++)
    {
        prev=temp;
        temp=temp->nxt;
    }
    p->nxt=prev->nxt;
    p->prv=temp->prv;
    prev->nxt=p;
    temp->prv=p;
    
    return head;
}
int count_nodes(NODE head)
{
    int c=0;
    NODE temp=head;
    if(head==NULL)
    {
     printf("list empty\n");
     return 0;
    }
    while(temp->nxt!=head)
    {
        c++;
        temp=temp->nxt;
    }
    c++;
    return c;
}
NODE delete_at_specific(NODE head,int pos)
{
    
    NODE temp=head;
    int i;
    NODE prev=NULL;
    if(head==NULL)
    {
        printf("list empty\n");
        return head;
    }
    if(pos>=1 && pos<=count_nodes(head))
   {
    if(pos==1)
    {
      while(temp->nxt!=head)
      {
        temp=temp->nxt;
      }     
      temp->nxt=head->nxt;
      head->nxt->prv=temp;
      free(head);
      head=temp->nxt;
      return head;
    }
    if(pos==count_nodes(head))
    {
     while(temp->nxt!=head)
      {
        prev=temp;
        temp=temp->nxt;
      }
      prev->nxt=temp->nxt;
      head->prv=prev;
      free(temp);
      return head;
    }
    for(i=1;i<pos;i++)
    {
        prev=temp;
        temp=temp->nxt;
    }
    prev->nxt=temp->nxt;
    temp->nxt->prv=temp->prv;
    free(temp);
    return head;
    }
    else
    {
        printf("invalid position\n");
        return head;
    }
}