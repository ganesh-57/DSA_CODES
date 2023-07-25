#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct PLANET
{
    char name[20];
    float diameter;
    int moons;
    struct PLANET *next;
}*NODE;
//typedef struct PLANET* NODE;
NODE getnode(void);
NODE read(NODE temp);
void display(NODE temp);
NODE insert_end(NODE head,NODE newnode);
int count(NODE head);
NODE specific_pos(NODE head,int pos,NODE newnode);
NODE deleteAtPOS(NODE head,int pos);
NODE deleteNAME(char str[20],NODE head);
int main()
{
    NODE head=NULL;
    NODE newnode;
    int n;
    int i;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        newnode=getnode();
        newnode=read(newnode);
        head=insert_end(head,newnode);
    }
    display(head);
    char str[20];
  
    for(i=0;i<3;i++)
    {
    printf("enter the name of the planet\n");
    scanf("%s",str);
    head=deleteNAME(str,head);
    display(head);
    }

    
}
NODE getnode(void)
{
    NODE temp;
    temp=(NODE)malloc(sizeof(struct PLANET));
    if(temp==NULL)
    {
        printf("insufficent memory\n");

    }
    else 
    {
        temp->next=NULL;
         return temp;
    }

}
NODE read(NODE temp)
{
    printf("enter the details\n");
    printf("enter the name:");
    scanf("%s",temp->name);
    printf("enter the diameter:");
    scanf("%f",&temp->diameter);
    printf("enter the moons:");
    scanf("%d",&temp->moons);
     return temp;

}
void display(NODE temp)
{
    while(temp!=NULL)
    {
        printf("%s\t%f\t%d\n",temp->name,temp->diameter,temp->moons);
        temp=temp->next;
    }
}
NODE insert_end(NODE head,NODE newnode)
{
    NODE temp=head;
    if(head==NULL)
    {
        head=newnode;
    }
    else
    {
        while(temp->next!=NULL)
        {
            temp=temp->next;
            
        }
        temp->next=newnode;
        newnode->next=NULL;
    }
    return head;
}
NODE specific_pos(NODE head,int pos,NODE newnode)
{
    int i;
    NODE temp;
    temp=head;
    int n;
    n=count(head);
    //printf("%d",n);
    if(pos>=1 && pos<=n+1)
    {
        if(pos==1)
        {
            newnode->next=head;
            head=newnode;
            return head;
        }
        if(pos==n+1)
        {
            while(temp->next!=NULL)
            {
                temp=temp->next;
            }
            temp->next=newnode;
            return head;
        }
        if(pos>1 && pos<n+1)
        {
            for(i=1;i<pos;i++)
            {
                temp=temp->next;
            }
        newnode->next=temp->next;
        temp->next=newnode;
        return head;
        }
    }
    else 
    {
        printf("invalid position\n");
        return head;
    }

}
int count(NODE head)
{
    int cnt=0;
    NODE temp=head;
    while(temp!=NULL)
    {
        cnt++;
        temp=temp->next;
        
    }
    printf("%d\n",cnt);
return cnt;
}          
NODE deleteAtPOS(NODE head,int pos)
{
    int a=count(head);
    if(pos<1 || pos>a)
    {
        printf("invalid position\n");
        return head;
    }
    NODE cur=head;
    NODE prev=NULL;
    if(pos==1)
    {
        head=head->next;
        printf("NAME:%s\nMOONS:%d\nDIAMETER:%f\n",cur->name,cur->moons,cur->diameter);
        free(cur);
        return head;
    }
    int i;
    for(i=1;i<pos;i++)
    {
        prev=cur;
        cur=cur->next;
    }
    prev->next=cur->next;
    printf("NAME:%s\nMOONS:%d\nDIAMETER:%f\n",cur->name,cur->moons,cur->diameter);
    free(cur);
    return head;
}

NODE deleteNAME(char str[20],NODE head)
{
  NODE cur=head;
  NODE prev=NULL;
  while(cur!=NULL && strcasecmp(cur->name,str)!=0)
  {
           prev=cur;
           cur=cur->next;

  }
  if(cur==head)
  {
      head=head->next;
      printf("NAME:%s\nMOONS:%d\nDIAMETER:%f\n",cur->name,cur->moons,cur->diameter);
      free(cur);
      return head;
  }
  else if(cur==NULL)
  {
     printf("no data found\n");
     return head;
  }

  else
  {
      
      prev->next=cur->next;
      printf("NAME:%s\nMOONS:%d\nDIAMETER:%f\n",cur->name,cur->moons,cur->diameter);
      free(cur);

      return head;
 }
    
}
