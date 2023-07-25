#include<stdio.h>
#include<stdlib.h>
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
int main()
{
    int i;
    int n;
    NODE head=NULL,newnode;
    scanf("%d",&n);
    for(i=0;i<=n;i++)
    {
     newnode=get
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

}//creation of node and returing it 
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

printf("NAME %s\nDIAMETER %f\nMOONS %d\n",temp->name,temp->diameter,temp->moons);

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
            temp->next=newnode;
        }
    }
    return head;
}
