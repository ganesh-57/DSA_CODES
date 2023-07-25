#include<stdio.h>
#include<stdlib.h>
#include<strings.h>
typedef struct Date
{
    int d,m,y;

}DATE;
typedef struct song
{
    char name[100];
    char singer[50];
    DATE date;
}SONG;
typedef struct node
{
    struct node *prev;
    SONG data;
    struct node *next;
}*NODE;
void display(NODE head);
void display_rev(NODE head);
int count_by_search(NODE head,char str[20]);
void readSong(SONG *s);
NODE addAtbeg(NODE head,SONG s);
NODE insertATpos(NODE head,int pos,SONG S);
NODE getNode(void);
NODE deleteAtBeg(NODE head);
NODE insertAtEnd(NODE head,SONG s);
NODE deleteAtEnd(NODE head);
NODE deleteATpos(NODE head,int c);

int count_nodes(NODE head);
int main()
{
    NODE head=NULL;
    int ch;
    int c=0;
    SONG s;
    char str[20];
    while(1)
    {
        printf("1.Add song to the front\n");
        printf("2.Display the list\n");
        printf("3.Delete at Beginning\n");
        printf("4.Delete at end\n");
        printf("5.Insert at end\n");
        printf("6.Count number of songs\n");
        printf("7.Display in reverse\n");
        printf("8.Count of songs sung by singer\n");
        printf("9.Insert at any postion\n");
        printf("10.Delete at Specific position\n");
        printf("11.Exit\n");












        scanf("%d",&ch);
        switch (ch)
        {
         case 1: readSong(&s);
                 head=addAtbeg(head,s);
                 break;
         case 2: display(head);
                 break;
         case 3: head=deleteAtBeg(head);
                 break;
         case 4: head=deleteAtEnd(head);
                 break;
         case 5: readSong(&s);
                 head=insertAtEnd(head,s);
                 break;
         case 6: c=count_nodes(head);
                 printf("%d\n",c);
                 break;
         case 7: display_rev(head);
                  break;
         case 8: printf("Enter the singer name\n");
                 scanf("%s",str);
                 c=count_by_search(head,str);
                 printf("The number of songs sung by the singer %d\n",c);
                 break;
         case 9: printf("Enter the postion\n");
                 scanf("%d",&c);
                 readSong(&s);
                 head=insertATpos(head,c,s);
                 break;
         case 10:printf("Enter the position\n");
                 scanf("%d",&c);
                 head=deleteATpos(head,c);
                 break;
         case 11: exit(0);
                 




        }
    }

}
void readSong(SONG *s)
{
    printf("Enter the song name:");
    scanf("%s",s->name);
    printf("Enter the singer name:");
    scanf("%s",s->singer);
    printf("Enter the date:");
    scanf("%d%d%d",&s->date.d,&s->date.m,&s->date.y);

}
NODE addAtbeg(NODE head,SONG s)
{
    NODE p;
    p=getNode();
    p->prev=NULL;
    p->next=NULL;
    p->data=s;
    if(head!=NULL)
    {
        p->next=head;
        head->prev=p;
        
    }
    head=p;
    return head;

}
void display(NODE head)
{
    NODE cur=head;
    if(head==NULL)
    {
        printf("List is empty\n");
        exit(0);
    }
    while(cur!=NULL)
    {
     printf("%s\t",cur->data.name);
     printf("%s\t",cur->data.singer);
     printf("%d-%d-%d\n",cur->data.date.d,cur->data.date.m,cur->data.date.y);
     cur=cur->next;
    }



}
NODE getNode(void)
{
    NODE p;
    p=(NODE)malloc(sizeof(struct node));
    return p;
}
NODE deleteAtBeg(NODE head)
{
    NODE cur=head;
    if(head->next==NULL)
    {
         free(head);
         head=NULL;
         return head;
    }
    else if(head!=NULL)
    {
        head=cur->next;
        free(cur);
        head->prev=NULL;
        return head;
    }
    else
    {
        printf("list is empty\n");
        return 0;
    }
}
NODE deleteAtEnd(NODE head)
{
    NODE cur=head;
    NODE prev=NULL;
    if(head==NULL)
    {
        printf("List empty\n");
        return head;
    }
    if(head->next==NULL)
    {
        free(head);
        head=NULL;
        return head;
    }
    if(head!=NULL)
    {
        while(cur->next!=NULL)
        {
            prev=cur;
            cur=cur->next;
        }
        prev->next=NULL;
        free(cur);
        return head;

    }
    
}
NODE insertAtEnd(NODE head,SONG s)
{
NODE cur=head;
NODE p=getNode();
p->next=NULL;
p->prev=NULL;
p->data=s;
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
if(head!=NULL)
{
   while(cur->next!=NULL)
   {
    cur=cur->next;

   }
   cur->next=p;
   p->prev=cur;
   return head;
}
}
int count_nodes(NODE head)
{
    NODE cur=head;
    int c=0;
    while(cur!=NULL)
    {
      c++;
      cur=cur->next;
    }

    return c;

}
void display_rev(NODE head)
{
  NODE cur=head;
  if(head==NULL)
  {
    printf("List is empty\n");
    return ;
  }
  while(cur->next!=NULL)
  {
    cur=cur->next;
  }
  while(cur!=NULL)
  {
     printf("%s\t",cur->data.name);
     printf("%s\t",cur->data.singer);
     printf("%d-%d-%d\n",cur->data.date.d,cur->data.date.m,cur->data.date.y);
     cur=cur->prev;
  }
 

}
int count_by_search(NODE head,char str[20])
{
 NODE cur=head;
 int c=0;
 if(head==NULL)
 {
    printf("List is empty\n");
    return 0;
 }
 while(cur!=NULL)
 {
    if(strcasecmp(cur->data.singer,str)==0)
    {
      c++;
     printf("%s\t",cur->data.name);
     printf("%s\t",cur->data.singer);
     printf("%d-%d-%d\n",cur->data.date.d,cur->data.date.m,cur->data.date.y);
      
    }


    cur=cur->next;

 }

 return c;

}
NODE insertATpos(NODE head,int pos,SONG S)
{
int cnt;
int i;
NODE cur=head;
NODE prev=NULL;
cnt=count_nodes(head);
NODE p=getNode();
p->next=NULL;
p->prev=NULL;
p->data=S;
if(pos>=1 && pos<=cnt+1
)
{
 if(pos==1)
 {
    head=addAtbeg(head,S);
    return head;
 }
 if(pos==cnt+1)
 {
   head=insertAtEnd(head,S);
   return head;
 }
for(i=1;i<pos;i++)
{
prev=cur;  
cur=cur->next;
}
prev->next=p;
cur->prev=p;
p->next=cur;
p->prev=prev;
return head;
}
}
NODE deleteATpos(NODE head,int c)
{
 NODE cur=head;
 NODE prev=NULL;
 NODE next=NULL;
 int i;
 int n=count_nodes(head);
 if(c<1 || c>n)
 {
    printf("Invalid position\n");
    return head;
 }
 
 if(c==1)
 {
   head=deleteAtBeg(head);
   return head;
 }
 if(c==n)
 {
    head=deleteAtEnd(head);
    return head;
 }

for(i=1;i<c;i++)
{
   prev=cur;
   cur=cur->next;
   

}

cur->prev->next=cur->next;
cur->next->prev=cur->prev;
free(cur);
return head;
 
 
 



}
NODE deletePat(NODE head,char str[30])
{
    NODE cur=head;
    if(head==NULL)
    {
        printf("Empty list\n");
        return 0;
    }
    if(head->next==NULL)
    {
        if(strcasecmp(head->data.name,str)==0)
        {
            free(head);
            head=NULL;
            return 0;
        }
        else
        {
         printf("Not found\n");
         return 0;


        }
    
    }







}





