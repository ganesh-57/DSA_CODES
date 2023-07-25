#include<stdio.h>
#include<string.h>
#include<strings.h>
#include<stdlib.h>
typedef struct GYM
{
    char name[30];
    int n;
    struct GYM *next;
}*Node;
Node getnode(void);
Node read(Node temp);
void display(Node head);
Node insertend(Node head,Node newnode);
Node delete(Node head,char B[30]);
int main()
{
 Node head=NULL;
 Node newnode;
 int i;
 char B[30];
 int n;
 printf("enter the number of excerxise did:");
 scanf("%d",&n);
 for(i=0;i<n;i++)
 {
   newnode=getnode();
   newnode=read(newnode);
   head=insertend(head,newnode);

}
display(head);
printf("enter the excerise to be deleted\n");
scanf("%s",B);
head=delete(head,B);
display(head);


return 0;

}
Node getnode(void)
{
    Node temp;
    temp=(Node)malloc(sizeof(struct GYM));
    if(temp==NULL)
    {
        printf("insufficient memory\n");
        return 0;
    }
 
     temp->next=NULL;

      return temp;

}
Node read(Node temp)
{
    printf("enter the excercise type and number");
    scanf("%s%d",temp->name,&temp->n);
    return temp;
}
void display(Node head)
{
    Node temp=head;
    printf("TYPE\tNUMBER\n");
    while(temp!=NULL)
    {
        printf("%s\t%d\n",temp->name,temp->n);
        temp=temp->next;
    }

return;
}

Node insertend(Node head,Node newnode)
{
   Node temp=head;
   if(head==NULL)
   {
    head=newnode;
    return head;
   }

   while(temp->next!=NULL)
   {
    temp=temp->next;
   }
   temp->next=newnode;
   newnode->next=NULL;
   

return head;

}
Node delete(Node head,char B[30])
{
  Node temp=head;
  Node prev=NULL;
  Node newnode;
  if(head==NULL)
  {
    printf("the list is empty\n");
     return 0;
  }
  if(head->next==NULL)
  {
    if(strcasecmp(head->name,B)==0)
    {
        free(head);
        return 0;
    }
  }
  if(strcasecmp(head->name,B)==0)
  {
    temp=head;
    head=head->next;
    free(temp);
    return head;
  }

  while(temp!=NULL)
  {
   
   if(strcasecmp(temp->name,B)==0)
   { 
     
     prev->next=temp->next;
     free(temp);
     //temp=prev->next;
     //return head;
   }
    

   prev=temp;
   temp=temp->next;

  

}


return  head;
}
