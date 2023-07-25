#include<stdio.h>
#include<math.h>

int main()
{
    int i,a,flag=0;
    printf("enter the number\n");
    scanf("%d",&a);
    if(a==0 || a==1)
     flag=1;
    else
    for(i=2;i<=sqrt(a);i++)
    {
        if(a%i==0)
        flag=1;
        break;
    }


}