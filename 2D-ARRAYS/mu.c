#include<stdio.h>
#define row 10
#define col 10
void readmatrix(int a[row][col],int r,int c);
void displaymatrix(int a[row][col],int r,int c);
void multipy(int a[row][col],int r1,int c1,int b[row][col],int r2,int c2,int res[row][col]);
void transpose(int a[row][col],int r,int c,int b[row][col]);
int identity(int a[row][col],int r,int c);
void readmatrix(int a[row][col],int r,int c)
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
void displaymatrix(int a[row][col],int r,int c)
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
void multipy(int a[row][col],int r1,int c1,int b[row][col],int r2,int c2,int res[row][col])
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
void transpose(int a[row][col],int r,int c,int b[row][col])
{
    int i,j;
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            b[j][i]=a[i][j];
        }
    }


return;
}
int identity(int a[row][col],int r,int c)
{
      int i,j;
      for(i=0;i<r;i++)
       {
          for(j=0;j<c;j++)
            {
              if(i==j && a[i][j]!=1)
                  return 0;
              else if(i!=j && a[i][j]!=0)
                  return 0;
            }
        }

      return 1;

}



int main()
{
 
  int r,c,k;
  int a[row][col];
  int b[row][col]={0};
  int p[row][col]={0};
   printf("enter the order of matrix\n");
   scanf("%d%d",&r,&c);
   readmatrix(a,r,c);
   displaymatrix(a,r,c);
   transpose(a,r,c,b);
   multipy(a,r,c,b,c,r,p);
   displaymatrix(p,r,r);
   k=identity(p,r,r);
   
   if(k==1)
   printf("orthtogonal\n");
   
   
return 0;
}

