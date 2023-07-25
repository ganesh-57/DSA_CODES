#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    struct node *nxt;
}*NODE;
NODE getnode(void);
NODE insert_at_end(NODE head,int n);
NODE insert_at_beg(NODE head,int n);
NODE insert_At_specific(NODE head,int pos,int n);
int count_nodes(struct node *head);
NODE delete_At_beg(NODE head);
void display(NODE head);
NODE delete_At_end(NODE head);
NODE delete_At_specific(NODE head,int pos);
int main()
{
int ch;
int o;
int pos;
int e;
NODE head=NULL;
while(1)
{
    printf("\n1.Add at beginning\n");
    printf("2.Add at end\n");
    printf("3.display\n");
    printf("4.add at specific\n");
    printf("5.delete at beginning\n");
    printf("6.delete at end\n");
    printf("7.delete at specific\n");
    printf("8.exit\n");
    scanf("%d",&ch);
    
    switch(ch)
    {
        case 1:printf("enter data:");
               scanf("%d",&e); 
               head=insert_at_beg(head,e);
               break;
        case 2:printf("enter data:");
               scanf("%d",&e);
               head=insert_at_end(head,e);
               break;
        case 3:display(head);
               break;
        case 4:printf("enter positon:");
               scanf("%d",&pos);
               printf("enter data:");
               scanf("%d",&e);
               head=insert_At_specific(head,pos,e);
               break;
        case 5:head=delete_At_beg(head);
               break;
        case 6:head=delete_At_end(head);
               break;
        case 7:printf("enter pos:");
               scanf("%d",&pos);
               head=delete_At_specific(head,pos);
               break;
        case 8:exit(0);


    }
}
}
NODE getnode(void)
{
     NODE p;
     p=(NODE)malloc(sizeof(struct node));
     if(p==NULL)
     {
     printf("insufficient memory\n");
     return p;
     }
     else 

   { p->nxt=p;
     return p;
   }

}
NODE insert_at_beg(NODE head,int n)
{
 NODE p;
 NODE temp=head;
 p=getnode();
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
 temp->nxt=p;
 p->nxt=head;
 head=p;
 return head;
}
NODE insert_at_end(NODE head,int n)
{
    NODE p=getnode();
    NODE temp=head;
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
    return head;
    
}
void display(NODE head)
{
    NODE temp=head;
    if(head==NULL)
    {
        printf("list empty\n");
        exit(0);
    }
    while(temp->nxt!=head)
    {
        printf("%d ",temp->data);
        temp=temp->nxt;
    }
    printf("%d ",temp->data);
}
NODE insert_At_specific(NODE head,int pos,int n)
{
    NODE temp=head;
    NODE p=getnode();
    int i;
    p->data=n;
    if(head==NULL)
    {
        printf("the list is empty\n");
        return head;
    }
    if(pos>=1 && pos<=(count_nodes(head)+1))
    {
        if(pos==1)
        {
            head=insert_at_beg(head,n);
            return head;
        }
        if(pos==(count_nodes(head)+1))
        {
            head=insert_at_end(head,n);
            return head;
        }
        for(i=1;i<pos-1;i++)
        {
            temp=temp->nxt;
        }
        p->nxt=temp->nxt;
        temp->nxt=p;

        return head;
    }
    else
    {
        printf("invalid position\n");
        return head;
    }

}
int count_nodes(struct node *head)
{
    int c=0;
    NODE temp=head;
    if(head==NULL)
    {
        printf("list is empty\n");
        return c;
    }
    while(temp->nxt!=head)
    {
        c++;
        temp=temp->nxt;

    }
    c++;
    return c; 


}
NODE delete_At_beg(NODE head)
{
    NODE temp=head;
    if(head==NULL)
    {
        printf("list empty\n");
        return head;
    }
    while(temp->nxt!=head)
    {
        temp=temp->nxt;
    }
    temp->nxt=head->nxt;
    free(head);
    head=temp->nxt;
    return head;

}
NODE delete_At_end(NODE head)
{
    NODE temp=head;
    NODE prev=NULL;
    if(head==NULL)
    {
        printf("list is empty\n");
        return head;
    }
    while(temp->nxt!=head)
    {
        prev=temp;
        temp=temp->nxt;
    }
    prev->nxt=temp->nxt;
    free(temp);
    return head;

}
NODE delete_At_specific(NODE head,int pos)
{
    NODE temp=head;
    NODE prev=NULL;
    if(head==NULL)
    {
        printf("list is empty\n");
        return head;
    }
    if(pos<1 && pos>count_nodes(head))
    {
        printf("invalid position");
        return head;

    }
    if(pos==1)
    {
        head=delete_At_beg(head);
        return head;
    }
    if(pos==count_nodes(head))
    {
        head=delete_At_end(head);
        return head;
    }
    int i;
    for(i=1;i<pos;i++)
    {
        prev=temp;
        temp=temp->nxt;
    }
    prev->nxt=temp->nxt;
    free(temp);
    return head;

}