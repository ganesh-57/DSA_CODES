#include<stdio.h>
#include<stdlib.h>
struct EMP
{
    int eid;
    char name[20];
    float sal;
};
void read(struct EMP *ptr,int n);
void display(struct EMP *ptr,int n);
int main()
{
    struct EMP *ptr;
    int n;
    printf("enter the number of employees\n");
    scanf("%d",&n);
    printf("%u\n",&ptr);
    ptr=(struct EMP*)malloc(n*sizeof(struct EMP));
    printf("%d\n",ptr);
    read(ptr,n);
    display(ptr,n);
    
}
void read(struct EMP *ptr,int n)
{
    int i;
    for(i=0;i<n;i++)
    {
     //ptr=(ptr+i);
     scanf("%d%s%f",&ptr->eid,ptr->name,&ptr->sal);
     
     i++;

    
    }
}
void display(struct EMP *ptr,int n)
{
    int i;
    for(i=0;i<n;i++)
    {
      //ptr=(ptr+i);
     printf("%d\n%s\n%f\n",ptr->eid,ptr->name,ptr->sal);
     i++;
    
    }
}