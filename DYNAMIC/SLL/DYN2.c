#include<stdio.h>
#include<stdlib.h>
struct emp
{
    int eid;
    char name[20];
    float salary;
};

int main()
{
  struct emp *ptr;
  printf("%d\n",&ptr);
  ptr=(struct emp*)malloc(sizeof(struct emp));
  printf("%d\n",ptr);
  printf("enter the details of the employes\n");
  scanf("%d%s%f",&ptr->eid,ptr->name,&ptr->salary);
  printf("the employee details are\n");
  printf("EID=%d\nNAME=%s\nSALARY=%f\n",ptr->eid,ptr->name,ptr->salary);

  ptr=(struct emp*)malloc(sizeof(struct emp));
  printf("%d\n",ptr);
  printf("enter the details of the employes\n");
  scanf("%d%s%f",&ptr->eid,ptr->name,&ptr->salary);
  printf("the employee details are\n");
  printf("EID=%d\nNAME=%s\nSALARY=%f\n",ptr->eid,ptr->name,ptr->salary);


  


}