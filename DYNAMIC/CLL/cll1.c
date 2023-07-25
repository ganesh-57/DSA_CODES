#include<stdio.h>
#include<stdlib.h>
typedef struct letter
{
    char name[25];
    long int ph;
    int hno;
    char area[100];
    struct letter *next; 
}*NODE;
NODE getnode(void);
NODE insert_end(NODE head);
NODE read(NODE newnode);
void display(NODE head);
NODE insert_front(NODE head);
int count(NODE head);
NODE specific_pos(NODE head,int pos);
NODE delete(NODE head,int pos);
int main()
{
    NODE head=NULL;  //creation of the linked list 
    int n;
    NODE newnode;
    int i;
    int p;
    printf("enter the number nodes to be created\n");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
     head=insert_end(head);
    }
    display(head);
    printf("1.INSERT END\n2.INSERT FRONT\n3.COUNT\n4.SPECIFIC POSITION\n5.DELETE\n6.EXIT\n");
    int a;
    scanf("%d",&a);
    switch(a)
    {
        case 1: head=insert_end(head);
                   display(head);
                      break;
        case 2: head=insert_front(head);
                   display(head);
                     break;
        case 3:   p=count(head);
                  printf("%d",p);   
                     break; 
        case 4:   printf("enter the postion\n");
                  scanf("%d",&p);
                  head=specific_pos(head,p);   
                  display(head);
                  break;  
        case 5:   printf("enter the postion to be deleted\n");
                  scanf("%d",&p); 
                  head=delete(head,p);
                  display(head);
                  break;
        default : exit(0);                           
    }
    //display(head);


}
NODE getnode(void)
{
    NODE temp;
    temp=(NODE)malloc(sizeof(struct letter));
    if(temp==NULL)
    {
        printf("insufficient memory\n");
        return NULL;
    }
     temp->next=temp;
    return temp; 
}
NODE insert_end(NODE head)
{
    NODE newnode=getnode();
    NODE temp=head;
    newnode=read(newnode);
    
    if(head==NULL)
    {
        head=newnode;
        return head;
    }
    while(temp->next!=head)
    {
        temp=temp->next;
    }
    temp->next=newnode;
    newnode->next=head;
    return head;
}
NODE read(NODE newnode)
{
    //printf("enter the info:");
    printf("enter the name:");
    scanf("%s",newnode->name);
    printf("enter the house number:");
    scanf("%d",&newnode->hno);
    printf("enter the area:");
    scanf("%s",newnode->area);
    printf("enter the mobile number:");
    scanf("%ld",&newnode->ph);

    return newnode;

}
void display(NODE head)
{
    NODE temp=head;
    printf("\nname\tho.no\tarea\tph.no\n");
    while(temp->next!=head)
    {
        printf("%s\t%d\t%s\t%ld\n",temp->name,temp->hno,temp->area,temp->ph);
        temp=temp->next;
    }
   
    printf("%s\t%d\t%s\t%ld\n",temp->name,temp->hno,temp->area,temp->ph);

}

NODE insert_front(NODE head)
{
    NODE newnode=getnode();
    NODE temp=head;
    newnode=read(newnode);
    
    if(head==NULL)
    {
        head=newnode;
        return head;
    }
    while(temp->next!=head)
    {
        temp=temp->next;
    }
    temp->next=newnode;
    newnode->next=head;
    head=newnode;
    return head;
}
int count(NODE head)
{
    int c=0;
   NODE temp=head;
   if(head==NULL)
     return 0;
    do
    {
       c++;       
       temp=temp->next;

    }while(temp!=head);
    //printf("%d",c);
    return c;
}
NODE specific_pos(NODE head,int pos)
{
    NODE temp=head;
    NODE prev=NULL;
    int n=count(head);
    //printf("%d",n);
    int i;
    if(head=NULL)
    {
        printf("the list is empty\n");
    }

    
    if(pos>=1 && pos<=n+1)
    {
        if(pos==1)
       { head=insert_front(head);
        return head;
       }
        if(pos==n+1)
        {
            head=insert_end(head);
        return head;
        }
        
        
            for(i=1;i<pos;i++)
            {
                prev=temp;
                temp=temp->next;
            }
           NODE newnode=getnode();
           newnode=read(newnode);
           prev->next=newnode;
           newnode->next=temp;
           return head;
        
    }
      
    else
     printf("invalid postion\n");
    
    
    
}
NODE delete(NODE head,int pos)
{
    NODE temp=head;
    NODE prev=NULL;
    int n=count(head);
    int i;
    if(head==NULL)
    {
        printf("the given list empty\n");
        return 0;
    }
    if(head->next==head)
    {
        free(head);
        return 0;
    }
    if(pos<1 || pos>n)
    {
        printf("invalid input\n");
        return head;
    }
    if(pos==1)
    {
        while(temp->next!=head)
        {
            temp=temp->next;
        }
        temp->next=head->next;
        free(head);
        head=temp->next;
      return head;
    }
    if(pos==n)
    {
        while(temp->next!=head)
        {
            prev=temp;
            temp=temp->next;

        }
        prev->next=temp->next;
        free(temp);
        return head;

    }
    for(i=1;i<pos;i++)
    {
     prev=temp;
     temp=temp->next;
     }
     prev->next=temp->next;
     free(temp);

     return head;


}
