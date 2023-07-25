#include<stdio.h>
#include<stdlib.h>
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
void multi(int a[row][col],int r1,int c1,int b[row][col],int r2,int c2,int res[row][col])
{

 int i,j,k;
 for(i=0;i<r1;i++)
 {
   for(j=0;j<c2;j++)
   {
     for(k=0;k<c1;k++)

     {
       res[i][j]=res[i][j]+a[i][k]*b[k][j];
     }

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
            printf(" %d",a[i][j]);
     }

     printf("\n");
    }        
   return;

}
int main()
{
  int a[row][col];
  int b[row][col];
  int res[row][col]={0};
  int r1,c1,r2,c2;
  printf("enter the order of matrix 1\n");
  scanf("%d%d",&r1,&c1);
  printf("enter the order of matrix 2\n");
  scanf("%d%d",&r2,&c2);
  if(c1!=r2)
  {
    printf("not possible\n");
    exit(0);
  }
   

  read(a,r1,c1);
  read(b,r2,c2);
  multi(a,r1,c1,b,r2,c2,res);
  print_ele(res,r1,c2);

  return 0;
}

