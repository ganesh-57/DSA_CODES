#include<stdio.h>
#include<stdlib.h>
#include<specific.h>
typedef struct WAR
{
    char name[30];
    char gen[10];
    int age;
    struct WAR *next;
}*NODE;
NODE getnode(void);
void display(NODE head);
NODE read(NODE temp);
NODE war(NODE head, NODE newnode);
int main()
{
int n;
NODE head=NULL;
NODE newnode;
printf("enter they number of male soldiers\n");
scanf("%d",&n);
int i;
for(i=0;i<n;i++)
{
 newnode=getnode();
 newnode=read(newnode);
 head=insert_end(head,newnode);
}




}
NODE getnode(void)
{
    NODE temp;
    temp=(NODE)malloc(sizeof(struct WAR));
    if(temp===NULL)
    {
        printf("insufficient memory\n");
    }

    temp->next=NULL;

    return temp;
}
NODE read(NODE temp)
{
    printf("enter name:");
    scanf("%s",temp->name);
    printf("enter gender:");
    scanf("%s",temp->gen);
    printf("enter age:");
    scanf("%d",&temp->age);

    return temp;

}
void display(NODE head)
{
    NODE temp=head;
    if(head=NULL)
    {
        printf("the list is empty\n");

    }
    while(temp!=NULL)
    {
        printf("%s\t%s\t%d\n",temp->name,temp->gen,temp->age);
        temp=temp->next;
    }
return;
}
NODE war(NODE head, NODE newnode)
{
    NODE temp=head;
    int pos=0;
    if(head=NULL)
    {
        printf("list is empty\n");
        head=newnode;
        pos=1;
        return head;
    }
    if(head->next=NULL)
    {
        if(head->age==newnode->age)
        {
            pos=1;
            head=specific_pos(head,pos,newnode);
            printf("the postioin of the female soldier %d\n",pos);
            return head;
        }
    }
    while(temp!=NULL)
    {
        pos++;
        if(temp->age==newnode->age)
        {
            head=specific_pos(head,pos,newnode);
            return head;
        }
        temp=temp->next;
    }
}