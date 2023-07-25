#include<stdio.h>
#define row 100
#define col 100
void read_array(int a[row][col],int r,int c);
void dis_array(int a[row][col],int r,int c);
void pro(int a[row][col],int r1,int c1,int b[row][col],int r2,int c2,int res[row][col]);

int main()
{
    int a[row][col];
    int b[row][col];
    int z[row][col]={0};

    
    int r1,c1;
    int r2,c2;
    printf("enter the order of matrix 1\n");
    scanf("%d%d",&r1,&c1);
    printf("enter the order of matrix 2\n");
    scanf("%d%d",&r2,&c2);
    if(c1==r2)
    {
    printf("enter the elements of 1st marix\n");
    read_array(a,r1,c1);
    dis_array(a,r1,c1);
    printf("enter the elements of 2nd marix\n");
    read_array(b,r2,c2);
    dis_array(b,r2,c2);
    pro(a,r1,c1,b,r2,c2,z);
    dis_array(z,r1,c2);
    }
    else 
    printf("multiplication is invalid\n");


    
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
    int i,j,k;
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            printf("%d ",a[i][j]);
            
        }
        printf("\n");

    }
}
void pro(int a[row][col],int r1,int c1,int b[row][col],int r2,int c2,int res[row][col])
{
    int i,j;
    int k;
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
    

}