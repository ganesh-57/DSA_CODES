#include<stdio.h>
void read(int a[10][10],int r,int c);
void display(int a[10][10],int r,int c);
void sum(int a[10][10],int r,int c);
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
        printf("%d ",a[i][j]);
      }

    printf("\n");
    
    }
 return;


}
void sum(int a[10][10],int r,int c)
{
    int SD=0,UT=0,LT=0;
    int i,j;
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            if(i==j)
            SD=SD+a[i][j];
            else if(i<j)
            LT=LT+a[i][j];
            else if(i>j)
            UT=UT+a[i][j];
        }


    }
    printf("%d\n%d\n%d",SD,LT,UT);

return;
}

int main()
{
    int a[10][10],r,c;
    printf("enter the  order of matrix\n");
    scanf("%d%d",&r,&c);
    read(a,r,c);
    display(a,r,c);
    sum(a,r,c);

 return 0;

}