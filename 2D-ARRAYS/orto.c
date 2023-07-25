#include<stdio.h>
#define row 10
#define col 10
void multiplymatrix(int a[row][col],int r1,int c1,int b[row][col],int r2,int c2,int res[row][col]);
void transpose(int a[row][col],int r,int c,int b[row][col]);
void readmatrix(int a[row][col],int r,int c);
int identity(int res[row][col],int r,int c);
void display(int a[row][col],int r, int c);
int main()
{
    int a[row][col];
    int b[row][col];
    int res[row][col]={0};
    int r,c,y;
    printf("enter order: \n");
    scanf("%d%d",&r,&c);
    if(r<0||r>row||c<0||c>col)
    {
        printf("Invalide input\n");
        return 0;
    }
    readmatrix(a,r,c);
    display(a,r,c);
    transpose(a,r,c,b);
    multiplymatrix(a,r,c,b,c,r,res);
    y=identity(res,r,r);
    if(y==1)
        printf("object will be rotated\n");
    else 
        printf("object will be in rigid motion\n");
    return 0;
}
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
    }

    void display(int a[row][col],int r, int c)
    {
        int i,j;
        for(i=0;i<r;i++)
        {
            for(j=0;j<c;j++)
            {
                printf("%d\t",a[i][j]);
            }
            printf("\n");
        }
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
    }

    void multiplymatrix(int a[row][col],int r1,int c1,int b[row][col],int r2,int c2,int res[row][col])
    {
        int i,j,k;
        for(i=0;i<r1;i++)
        {
            for(j=0;j<c2;j++)
            {
                for(k=0;k<r2;k++)
                {
                    res[i][j]=res[i][j]+(a[i][k]*b[k][j]);
                }
            }
        }
    }

    int identity(int res[row][col],int r,int c)
    {
        int i,j;
        for(i=0;i<r;i++)
        {
            for(j=0;j<c;j++)
            {
                if(i==j && res[i][j]!=1)
                    return 0;
                else if(i!=j && res[i][j]!=0)
                    return 0;
            }
        }
        return 1;
    }