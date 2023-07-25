#include<stdio.h>
#include<math.h>

int main()
{
    int n;
    printf("enter the number\n");
    scanf("%d",&n);
    int i;
    if(n==1 || n==0)
    {
        printf("non-prime\n");

    }
    else 
    for(i=2;i<=sqrt(n);i++)
    {
          if(n%i==0)
          printf("non-prime\n");
          break;

    }
    printf("prime\n");



}