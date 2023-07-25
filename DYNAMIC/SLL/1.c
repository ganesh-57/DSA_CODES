#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
}*NODE;

NODE add_at_end(NODE head,int n);
NODE getnode(void);
NODE add_at_beg(NODE head,int n);
int count_nodes(NODE head);
NODE add_at_specific(NODE head,int pos,int n);
void display(NODE head);
NODE delete_at_beg(NODE head);
NODE delete_at_specific(NODE head,int pos);
NODE delete_at_end(NODE head);
int main()
{
    int e;
    int u;
    int pos;
    NODE head=NULL;
    int n;
    while(1)
    {
        printf("\n1.Add at beginning\n");
        printf("2.Add at end\n");
        printf("3.display\n");
        printf("4.Add at specific position\n");
        printf("5.Delete at beginning\n");
        printf("6.Delete at End\n");
        printf("7.Delete at specific\n");
        printf("8.exit\n");
        scanf("%d",&e);
        

        switch(e)
        {
            case 1: printf("enter data:");
                    scanf("%d",&u);
                    head=add_at_beg(head,u);
                    break;
            case 2: printf("enter data:");
                    scanf("%d",&u);
                    head=add_at_end(head,u);
                    break;
            case 3: display(head);
                    break;
            case 4: printf("enter data:");
                    scanf("%d",&u);
                    printf("enter pos:");
                    scanf("%d",&pos);
                    head=add_at_specific(head,pos,u);
                    break;
            case 5: head=delete_at_beg(head);
                    break;
            case 6: head=delete_at_end(head);
                    break;
            case 7:printf("enter pos:");
                   scanf("%d",&pos);
                   head=delete_at_specific(head,pos);
                   break;
            case 8:exit(0);


               

        }

    }
}
NODE add_at_end(NODE head,int n)
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
    while(temp->next!=NULL)
    {
        temp=temp->next;

    }
    temp->next=p;
    return head;
}
NODE getnode(void)
{
    NODE p;
    p=(NODE)malloc(sizeof(struct node));
    if(p==NULL)
    {
     printf("insufficient memeory\n");
    return NULL;
    }
    else
    {
    p->next=NULL;
    return p;
    }
    
}
NODE add_at_beg(NODE head,int n)
{
    NODE p;
    p=getnode();
    p->data=n;
    if(head==NULL)
     {
      head=p;
      return head;
     }

     p->next=head;
     head=p;
     return head;

}
void display(NODE head)
{ 
    NODE temp=head;
    if(head==NULL)
    {
        printf("list empty\n");
        return;
    }
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->next;

    }
}
NODE add_at_specific(NODE head,int pos,int n)
{
    NODE temp=head;
    NODE p=getnode();
    p->data=n;

    if(head==NULL)
   {
    printf("list is empty\n");
    return head;
   }
   int i;
   if(pos>=1 && pos<=count_nodes(head)+1)
   {

   for(i=1;i<pos-1;i++)
   {
    temp=temp->next;

   
   }
   p->next=temp->next;
   temp->next=p;
   return head;
   }
   else 
   printf("invalid postion\n");
   return head;

   

    
 
}
int count_nodes(NODE head)
{
     int c=0;
    NODE temp=head;
    if(head==NULL)
    {
    printf("list is empty\n");
    return 0;
    }
    while(temp!=NULL)
    {
        c++;
        temp=temp->next;
    }
    return c;

}
NODE delete_at_beg(NODE head)
{
    NODE temp=head;
    if(head==NULL)
    {
     printf("list empty\n");
     return NULL;
    }
    temp=temp->next;
    free(head);
    head=temp;
    return head;


}
NODE delete_at_end(NODE head)
{
    NODE temp=head;
    NODE cur=NULL;
    if(head==NULL)
    {
     printf("list empty\n");
      return head;
    }
    while(temp->next!=NULL)
    {
        cur=temp;
        temp=temp->next;
    }
    free(temp);
    cur->next=NULL;
    return head;
}
NODE delete_at_specific(NODE head,int pos)
{
    int i;
    NODE temp=head;
    NODE cur=NULL;
    if(head==NULL)
    {
     printf("list is empty\n");
     return head;
    }
    if(pos>=1 && pos<=count_nodes(head))
    {
        if(pos==1)
        {
            head=delete_at_beg(head);
            return head;
        }
        if(pos==count_nodes(head))
        {
            head=delete_at_end(head);
            return head;
        }
     for(i=1;i<pos;i++)
     {
       cur=temp;
       temp=temp->next;

     }
     cur->next=temp->next;
     free(temp);
     return head;
 


    }
    else
    {
     printf("invalid position\n");
     return head;
    }

}

