#include<stdio.h>
#define row 100
#define col 100
void display_matrix(int a[row][col],int r,int c);
void read_matrix(int a[row][col],int r,int c);
void add_matrix(int a[row][col],int b[row][col],int r,int c);
int main()
{ 
    int r,c;
    int a[row][col];
    int b[row][col];

    printf("enter the order of matrix\n");
    scanf("%d%d",&r,&c);
    read_matrix(a,r,c);
    display_matrix(a,r,c);
    read_matrix(b,r,c);
    display_matrix(b,r,c);
      add_matrix(a,b,r,c);

}
void read_matrix(int a[row][col],int r,int c)
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
void display_matrix(int a[row][col],int r,int c)
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
void add_matrix(int a[row][col],int b[row][col],int r,int c)
{
    int i,j;
    int z[row][col];
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
             z[i][j]=a[i][j]+b[i][j];
        }
    }

    display_matrix(z,r,c);
}
