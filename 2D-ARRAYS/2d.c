#include<stdio.h>
#include<ctype.h>
#include<string.h>
void read_ele(int a[10][10],int r,int c)
{
    int i,j;
    printf("enter the elements\n");
    for(i=0;i<r;i++)
      for(j=0;j<c;j++)
      scanf("%d",&a[i][j]);

   return;

}
void print_ele(int a[10][10],int r,int c)
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
int sum(int a[10][10],int r,int c)
{
    int i,j,l=0;
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        l=l+a[i][j];
    }


    return l;

}
int max(int a[10][10],int r,int c)
{
    int i,j;
    int z;
    z=a[0][0];

    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        if(a[i][j]>z)
           z=a[i][j];

    }
    return z;
}
int min(int a[10][10],int r,int c)
{
    int i,j;
    int z;
    z=a[0][0];

    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        if(a[i][j]<z)
           z=a[i][j];

    }
    return z;
}
int main()
{
    int a[10][10],r,c,k;

    printf("enter the colums and rows\n");
    scanf("%d%d",&c,&r);
    read_ele(a,r,c);
    print_ele(a,r,c);
    k=sum(a,r,c);
    printf("sum %d\n",k);
    

    printf("max %d\n",max(a,r,c));
    printf("min %d\n",min(a,r,c));

 return 0;   

} 