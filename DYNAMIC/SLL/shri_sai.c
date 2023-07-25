#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef struct sai
{
 int age;
 struct sai *next;
    
    
}*NODE;
NODE insert_front(NODE head,NODE insert);
NODE getnode(void);
NODE read(NODE temp);
int max(NODE head);
NODE FREE(NODE head,int n);
void display(NODE head);
int main() 
{
    int n;
    scanf("%d",&n);
    NODE head=NULL;
    if(n<1 || n> 100)
    {
        printf("Invalid");
          exit(0);
    }
    int i;
    for(i=0;i<n;i++)
    {
        NODE temp;
        temp=getnode();
        temp=read(temp);
        head=insert_front(head,temp);
        
    }
    
    int m;
    m=max(head);
    printf("Allowed for worship: %d\n",m);
    head=FREE(head,m);
    display(head);
    
    
    
    
    
return 0;
}
NODE getnode(void)
{
    NODE temp;
    temp=(NODE)malloc(sizeof(struct sai));
    if(temp==NULL)
    {
        printf("Insufficient Memory");
        return 0;
    }
    
    temp->next=NULL;
    return temp;
}
NODE insert_front(NODE head,NODE insert)
{
    if(head==NULL)
    {
        head=insert;
        return head;
        
    }
    insert->next=head;
    head=insert;
    return head;
    
}
NODE read(NODE temp)
{
    scanf("%d",&temp->age);
    return temp;
}
int max(NODE head)
{
    NODE temp=head;
    int m=head->age;
    while(temp!=NULL)
    {
        if(m<temp->age)
        {
            m=temp->age;
        }
        temp=temp->next;
    }
    
    
    return m;
}
NODE FREE(NODE head,int n)
{
    NODE temp=head;
    NODE prev=NULL;
    while(temp!=NULL)
    {
        prev=temp;
        if(temp->age==n)
        {
         prev->next=temp->next;
         free(temp);
          return head;
        }
        
        temp=temp->next;
        
    }
    
    return head;
}
void display(NODE head)
{
 NODE temp=head;
    printf("Remaining devotees: ");
    while(temp!=NULL)
    {
        printf("%d ",temp->age);
        temp=temp->next;
    }
    
}