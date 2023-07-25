#include<stdio.h>
#define row 10
#define col 10
void read(int a[row][col],int r,int c);
void print_ele(int a[row][col],int r,int c);
void trans(int a[row][col],int r,int c,int b[row][col]);
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
     { for(j=0;j<c;j++)
            printf("%d ",a[i][j]);
     }

     printf("\n");
    }        
   return;

}
void trans(int a[row][col],int r,int c,int b[row][col])
{
    int i,j;
    //int b[row][col];
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            b[j][i]=a[i][j];
        }
    }
    
    
    print_ele(b,r,c);

return;
}


int main()
{
    int r,c;
    int a[row][col];
    int b[row][col];
    printf("enter the order of matrix\n");
    scanf("%d%d",&r,&c);
    read(a,r,c);
    trans(a,r,c,b);

}
