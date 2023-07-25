#include<stdio.h>
#define row 100
#define col 100
void read_array(int a[row][col],int r,int c);
void dis_array(int a[row][col],int r,int c);
int test(int a[row][col],int r,int c);
int main()
{
    int a[row][col];
    int r,c;
    
    printf("enter the order of matrix\n");
    scanf("%d%d",&r,&c);
    if(r==c)
    {
    read_array(a,r,c);
    dis_array(a,r,c);
    int l;
    l=test(a,r,c);
    if(l==1)
    {
        printf("identity\n");

    }
    else 
    printf("not identity\n");
    }
    else 
    printf("not valid for the given matrix\n");
    
    
}
void read_array(int a[row][col],int r,int c)
{
    int i,j;
    for(i=0;i<r;i++)
    {
         for(j=0;j<c;j++)
         {
         scanf("%d",&a[i][j]);
         }
    }
}
void dis_array(int a[row][col],int r,int c)
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
}
int test(int a[row][col],int r,int c)
{
    int i,j,f=0;
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
       {
           if(a[i][j]==1 && i==j)
               f++;

       }
       
    }
    if(r==f)
    {
        return 1;

    }
    else 

    return 0;
}