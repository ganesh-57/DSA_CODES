#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define size 100
void internal_evaluation(int a[size][size],int n,int m);
void student_average(int a[size][size],int n,int m);
int main() 
{
    int n,m;
    scanf("%d%d",&n,&m);
    if(n<=0 || m<=0)
    {
        printf("Invalid input");
        exit(0);
    }
    int i;
    int j;
    int a[size][size]={0};
    for(i=0;i<n;i++)
    {
     
        for(j=0;j<m;j++)
       {
         scanf("%d",&a[i][j]);
       
        }
    
    }
    student_average(a,n,m);
    internal_evaluation(a,n,m);
    

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    return 0;
}
void student_average(int a[size][size],int n,int m)
{
    int i;
    int j;
    int sum=0;
    for(i=0;i<n;i++)
    {
        sum=0;
        for(j=0;j<m;j++)
        {
            sum=sum+a[i][j];
        }
        printf("%f ",(float)sum/m);
    }
    
}
void internal_evaluation(int a[size][size],int n,int m)
{
    int i;
    int j;
    int sum=0;
    for(i=0;i<m;i++)
    {
        sum=0;
        for(j=0;j<n;j++)
        {
            sum=sum+a[j][i];
        }
        printf("%f ",(float)sum/n);
    }
}
