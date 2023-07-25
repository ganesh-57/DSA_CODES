#include<stdio.h>
#include<stdlib.h>
#define row 100
#define col 100
void read_array(int a[row][col],int r,int c);
void dis_array(int a[row][col],int r,int c);
void add(int a[row][col],int r,int c,int b[row][col],int res[row][col]);
int main()
{
   int a[row][col];
   int b[row][col];
   int res[row][col]={0};
   int r1,c1;
   int r2,c2;
   printf("enter the order of the matrix\n");
   scanf("%d%d",&r1,&c1);
   printf("enter the order of the matrix\n");
   scanf("%d%d",&r2,&c2);
   if(r1!=r2 && c1!=c2)
   {
    printf("Addition is not possible\n");
   
   }
   else 
   {
    read_array(a,r1,c1);
   dis_array(a,r1,c1);
   read_array(b,r2,c2);
   dis_array(b,r2,c2);
   add(a,r1,c1,b,res);
   printf("the added matrix is \n");
   dis_array(res,r1,c1);
   }

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
void add(int a[row][col],int r,int c,int b[row][col],int res[row][col])
{
    int i,j;
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            res[i][j]=a[i][j]+b[i][j];
        }
    }
}