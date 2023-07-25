#include<stdio.h>
#define row 10
#define col 10
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
void sum(int a[row][col],int r1,int c1,int b[row][col],int r2,int c2,int res[row][col])
{
    int i,j;
    for(i=0;i<r1;i++)
    {
      for(j=0;j<c1;j++)
      {
          res[i][j]=res[i][j]+a[i][j]+b[i][j];
      }
    }

    return;
}
void print_ele(int a[row][col],int r,int c)
{
    int i,j;
    for(i=0;i<r;i++)
    {
     { for(j=0;j<c;j++)
            printf("%d ",a[i][j]);
     }

     printf("\n");
    }        
   return;

}
int main()
{
    int r1,c1;
    int r2,c2;
    int a[row][col];
    int b[row][col];
    int c[row][col]={0};
    printf("enter the order os matrix\n");
    scanf("%d%d",&r1,&c1);
    scanf("%d%d",&r2,&c2);
    if(r1==r2 && c1==c2)
    {
    read(a,r1,c1);
    read(b,r2,c2);
    sum(a,r1,c1,b,r2,c2,c);
    print_ele(c,r1,c1);
    }
    return 0;
}