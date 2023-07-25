#include<stdio.h>
int main()
{
    int n;
    printf("enter the number of hrs worked by the worker\n");
    scanf("%d",&n);
    if(n>=2 && n<=3)
    printf("efficient worker\n");
    else if(n>=3 && n<=4)
    printf("iMPROVE SPEED\n");
    else if(n>=4 && n<=5)
    printf("training required\n");
    else
    printf("the worker is terminated\n");
    

    return 0;
}