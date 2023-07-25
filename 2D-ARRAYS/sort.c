#include<stdio.h>
#define row 10
#define col 10
void read(int a[row][col],int r,int c);
void print_ele(int a[row][col],int r,int c);
void sortmat(int a[row][col],int r,int c);
void bubblesort(int b[],int n);
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
            printf(" %d",a[i][j]);
     }

     printf("\n");
    }        
   return;
}
void sortmat(int a[row][col],int r,int c)
{
    int i,j;
    for(i=0;i<r;i++)
    {
        bubblesort(a[i],c);
    }
return;
}
void bubblesort(int b[],int n)
{
    int i,j,temp=0;
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-1-i;j++)
        {
           if(b[j]>b[j+1])
            {
             temp=b[j];
             b[j]=b[j+1];
             b[j+1]=temp;
            }
        }
    }
return;
}
int main()
{
    int a[row][col],r,c;
    printf("enter the order of matrix\n");
    scanf("%d%d",&r,&c);
    read(a,r,c);
    sortmat(a,r,c);
    print_ele(a,r,c);  

    return 0;
}