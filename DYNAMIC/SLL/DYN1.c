#include<stdio.h>
#include<stdlib.h>
int main()
{
    int *p;
    printf("the value=%u\n",&p);
    p=(int*)malloc(sizeof(int));
    printf("the value=%u\n",p);
    printf("enter the value\n");
    scanf("%d",p);
    printf("the value=%d\n",p);
    printf("the value=%u\n",*p);
    
}