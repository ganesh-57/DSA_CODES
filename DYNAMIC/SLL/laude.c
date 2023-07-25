#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define size 100
void count(int a[size],int n);
int main() 
{
  int n;
    int a[size];
    int i;
    scanf("%d",&n);
    if(n<0)
        printf("Invalid");
     exit(0);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    count(a,n);
    
    
    
    
    
    

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    return 0;
}
void count(int a[size],int n)
{
    int i;
    int cnt=0;
    int j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(a[i]==a[j])
            { cnt++;
            }
            
        }
        if(cnt%2!=0)
        {
           printf("%d",a[i]);
           exit(0);
        }
    }
    
 return;
}
