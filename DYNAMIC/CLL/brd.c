#include<stdio.h>
#include<stdlib.h>
struct data
{
    int year;
    char str[40];

};
typedef struct node
{
    struct node *next;
    struct data D;

}*NODE;
NODE getnode(void);
void read(struct data *s);
NODE insert_at_end(NODE head,struct data f);
void display(NODE head);
void search(NODE head,int y);
int main()
{
    int n;
    int i;
    scanf("%d",&n);
    struct data f;
    NODE head=NULL;
    for(i=0;i<n;i++)
    {
        read(&f);
        head=insert_at_end(head,f);

    }
    int k;
    scanf("%d",&k);
    display(head);
    search(head,k);
}
NODE getnode(void)
{
    NODE P;
    P=(NODE)malloc(sizeof(struct node));
    if(P==NULL)
     return NULL;
     else
     {
     P->next=P;
     return P;
     }
}
void read(struct data *s)
{
    scanf("%s",s->str);
    scanf("%d",&s->year);
}
NODE insert_at_end(NODE head,struct data f)
{
    NODE temp=head;
    NODE P;
    P=getnode();
    P->D=f;
    if(head==NULL)
    {
     head=P;
     return head;
    }
    while(temp->next!=head)
    {
        
        
        temp=temp->next;
    }
    temp->next=P;
    P->next=head;
    return head;
}
void display(NODE head)
{
    NODE temp=head;
    while(temp->next!=head)
    {
        printf("%s %d",temp->D.str,temp->D.year);
        printf("\n");
        temp=temp->next;
    }
    printf("%s %d",temp->D.str,temp->D.year);
    
}
void search(NODE head,int y)
{
    int count=0;
    NODE temp=head;
    if(head->next==head)
    {
        if(head->D.year==y)
        {
            count++;
            printf("\n");
            printf("%s %d",head->D.str,head->D.year);
            
        }
        printf("\n");
        printf("%d",count);
        return;
    }
    while(temp->next!=head)
    {
        if(temp->D.year==y)
        {
            printf("\n");
            printf("%s %d",temp->D.str,temp->D.year);
            count++;
        }
        temp=temp->next;
    }
    if(temp->D.year==y)
        {
            printf("\n");
            printf("%s %d",temp->D.str,temp->D.year);
            count++;
        }
    
    printf("\n");
    printf("%d",count);
     
    

}
