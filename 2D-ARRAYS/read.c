#include<stdio.h>
void read(int a[10][10],int r,int c)
{
    int i,j;
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        scanf("%d",&a[i][j]);
    }


    return;
}

void display(int a[10][10],int r,int c)
{
    int i,j;
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            printf(" %d",a[i][j]);
        }
    
    printf("\n");
    
    }
return;
}

int main()
{
    int a[10][10],r,c;
    scanf("%d%d",&r,&c);
    read(a,r,c);
    display(a,r,c);


    return 0;
}
.