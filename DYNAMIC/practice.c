#include<stdio.h>
#include<stdlib.h>
typedef struct data
{
    int d;
}DATA;
typedef struct hydrate
{
    struct hydrate *prev;
    DATA D;
    struct hydrate *next;
}*NODE;
void read(DATA *S);
NODE getnode(void);
NODE addATbeg(NODE head,DATA S);
void display(NODE head);
NODE addAtend(NODE head,DATA S);
NODE requiredFun(NODE head,int n);
void display_reverse(NODE head);
int count_nodes(NODE head);
NODE insertATpos(NODE head,int pos,DATA s);
NODE deleteATbeg(NODE head);
int main()
{
int ch;
int n;
DATA R;
NODE head=NULL;
while(1)
{
printf("1.Add at beginning\n");
printf("2.Add at end\n");
printf("3.Display the list\n");
printf("4.Required Function\n");
printf("5.Display in reverse\n");
printf("6.Insert at any position\n");
printf("7.Delete At beginning\n");




scanf("%d",&ch);

switch(ch)
{
    case 1:read(&R);
           head=addATbeg(head,R);
           break;
    case 2: read(&R);
            head=addAtend(head,R);
            break;
    case 3: display(head);
            break; 
    case 4: scanf("%d",&n);
            head=requiredFun(head,n);
            break;
    case 5:display_reverse(head);
           break;
    case 6:read(&R);
           printf("enter the position\n");
           scanf("%d",&n);
           head=insertATpos(head,n,R);
           break;
    case 7:deleteATbeg(head);
           break;
    


}
}
}

NODE getnode(void)
{
    NODE p;
    p=(NODE)malloc(sizeof(struct hydrate));
    if(p==NULL)
    {
        printf("insufficient memory\n");
        return 0;
    }

    return p;
}
void read(DATA *S)
{
    printf("enter the hydrated value\n");
    scanf("%d",&S->d);

}
NODE addATbeg(NODE head,DATA S)
{
NODE p;
p=getnode();
p->next=NULL;
p->prev=NULL;
p->D=S;
if(head==NULL)
{
 head=p;
 return p;
}

p->next=head;
head->prev=p;
head=p;
return p;



}
void display(NODE head)
{
NODE cur=head;
if(head==NULL)
{
    printf("list is empty\n");
    exit(0);
}
while(cur!=NULL)
{
    printf("%d\n",cur->D.d);
    cur=cur->next;

}
}
NODE addAtend(NODE head,DATA S)
{
    NODE p;
    NODE cur=head;
    p=getnode();
    p->prev=NULL;
    p->next=NULL;
    p->D=S;

    if(head==NULL)
    {
      head=p;
      return head;
    }
    if(head->next==NULL)
    {
      head->next=p;
      p->prev=head;
      return head;
    }

    while(cur->next!=NULL)
    {
        cur=cur->next;
    }
    cur->next=p;
    p->prev=cur;
    return head;
}
NODE requiredFun(NODE head,int n)
{
    NODE cur=head;
    int i;
    for(i=0;i<n;i++)
    {
        cur->D.d--;
        cur=cur->next;
    }
    while(cur!=NULL)
    {
        cur->D.d++;
        cur=cur->next;

    }

    return head;

}
void display_reverse(NODE head)
{
    NODE cur=head;
    while(cur->next!=NULL)
    {
     cur=cur->next;
    }
    while(cur!=NULL)
    {
       printf("%d\n",cur->D.d);
        cur=cur->prev;
    }
}
NODE insertATpos(NODE head,int pos,DATA s)
{
    NODE cur=head;
    int i;
    NODE p=getnode();
    p->next=NULL;
    p->prev=NULL;
    p->D=s;
    NODE prev=NULL;
    int n=count_nodes(head);
if(pos>=1 || pos<=n+1)
{
  if(pos==1)
  {
    head=addATbeg(head,s);
    return head;
  }
  if(pos==n+1)
  {
    head=addAtend(head,s);
    return head;
  }


    for(i=1;i<pos;i++)
    {
        prev=cur;
        cur=cur->next;

    }
    p->prev=cur->prev;
    cur->prev=p;
    prev->next=p;
    p->next=cur;

    return head;
}

else 
{
    printf("invalid position\n");
    return NULL;
}
}





int count_nodes(NODE head)
{
    NODE cur=head;
    int cnt=0;
    while(cur!=NULL)
    {
        cur=cur->next;
        cnt++;
    }

    return cnt;
}
NODE deleteATbeg(NODE head)
{
    NODE cur=head;

    if(head==NULL)
    {
        printf("List is empty\n");
        return 0;
    }
    if(head->next==NULL)
    {
        free(head);
        head=NULL;
        return head;;
    }

    head=cur->next;
    free(cur);
    head->prev=NULL;
    return head;
 
}

NODE deleteATpos(NODE head,int pos)

{

}

