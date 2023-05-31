#include<stdio.h>
#include<stdlib.h>
void read_ele_matrix(int a[10][10],int row,int col);
void print_ele_matrix(int a[10][10],int row,int col);
void multi_matrix(int a[10][10],int b[10][10],int row1,int col1,int row2,int col2);
void main()
{
int a[10][10];
int b[10][10];
int c[10][10]={0};
int ch;
int row1,col1;
int row2,col2;
int i,j;
while(1)
{
    printf("1.ENTER THE DATA OF MATRIX 1\n");
    printf("2.ENTER THE DATA OF MATRIX 2\n");
    printf("3.DISPLAY MATRIX 1\n");
    printf("4.DISPLAY MATRIX 2\n");
    printf("5.MULTIPLICATION OF MATRICES 1 AND 2\n");
    printf("6.EXIT\n");
    scanf("%d",&ch);
    switch(ch)   
    {
     case 1:printf("enter row:");
            scanf("%d",&row1);
            printf("enter col:");
            scanf("%d",&col1);
            read_ele_matrix(a,row1,col1);    
            break;
     case 2:
            printf("enter row:");
            scanf("%d",&row2);
            printf("enter col:");
            scanf("%d",&col2);
            read_ele_matrix(b,row2,col2);
            break;
     case 3:print_ele_matrix(a,row1,col1);
            break;
     case 4:print_ele_matrix(b,row2,col2);
            break;
     case 5:multi_matrix(a,b,row1,col1,row2,col2);
            break;
     

     }
}


}


void read_ele_matrix(int a[10][10],int row,int col)
{
int i;
int j;
for(i=0;i<row;i++)
{
 for(j=0;j<col;j++)
 {
  scanf("%d",&a[i][j]);

 }

}

}
void print_ele_matrix(int a[10][10],int row,int col)
{
    int i;
    int j;
    for(i=0;i<row;i++)
    {
        for(j=0;j<col;j++)
        {
            printf("%d ",a[i][j]);
        }
        printf("\n");

    }

}

void multi_matrix(int a[10][10],int b[10][10],int row1,int col1,int row2,int col2)
{
    int i;
    int j;
    int k;
    int c[10][10]={0};
    if(col1!=row2)
    {
        printf("matrix multiplication is not possible\n");
        return;
    }
    for(i=0;i<row1;i++)
    {
        for(j=0;j<col2;j++)
        {
            for(k=0;k<col1;k++)
            {
                c[i][j]=c[i][j]+a[i][k]*b[k][j];
            }
        }
    }
    print_ele_matrix(c,row1,col2);


}

