#include<stdio.h>
#include<stdlib.h>
#include"specific.h"
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
int main()
{
    NODE head;
    NODE newnode;
    int n;
    head=getnode();
    head=read(head);
    newnode=getnode();
    newnode=read(newnode);
    printf("enter the postion where new node is to be inserted:");
    scanf("%d",&n);
    head=specific_pos(head,n,newnode);
    display(head);
    
    
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
    }
    return head;
}
/*NODE specific_pos(NODE head,int pos,NODE newnode)
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
    NODE temp;
    while(temp!=NULL)
    {
        cnt++;
        temp=temp->next;
        
    }
    printf("%d\n",cnt);
return cnt;
}     */     