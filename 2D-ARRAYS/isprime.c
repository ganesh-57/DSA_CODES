#include<stdio.h>
#include<math.h>
#define row 100
#define col 100
void read(int a[row][col],int r,int c);
void print_ele(int a[row][col],int r,int c);
int isprime(int a);
int count(int a[row][col],int r,int c);
int main()
{
    int a[row][col];
    printf("enter the order of matrix\n");
    int r,c;
    scanf("%d%d",&r,&c);
    read(a,r,c);
    print_ele(a,r,c);
    count(a,r,c);



}

void read(int a[row][col],int r,int c)
{
   int i,j;
   for(i=0;i<r;i++)
   {
    
    for(j=0;j<c;j++)
    {
      scanf("%d",&a[i][j]);
    }
   
   }

return;

}
void print_ele(int a[row][col],int r,int c)
{
    int i,j;
    for(i=0;i<r;i++)
    {
      for(j=0;j<c;j++)
     {
        printf("%d ",a[i][j]);
     }     

     printf("\n");
    
    }        
   return;

}
int isprime(int a)
{
    int i;
    if(a==0 || a==1)
    {
        return 0;
    }
    for(i=2;i<=sqrt(a);i++)
    {
        if(a%i==0)
        return 0;
    }
    
    


    return 1;

}
int count(int a[row][col],int r,int c)
{
    int i,j;
    int g;
    int cnt=0;

    for(i=0;i<r;i++)
    {
        for(j=0,cnt=0;j<c;j++)
        {
            g=isprime(a[j][i]);
            if(g==1)
             cnt++;
        }
        printf("%d ",cnt);
        

    }
}