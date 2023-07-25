#include<stdio.h>
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
            printf("%d ",a[i][j]);
     }

     printf("\n");
    }        
   return;

}
void find_avg(int a[10][10], int r)
{
    int i,j,sum=0;
    float avg[4];
    for(j=0;j<4;j++)
    {
        for(i=0;i<r;i++)
       {
        sum=sum+a[i][j];
         
       }
       a[j]=sum(float)/r;
       printf("%f\n",a[j]);   
    }


return;
}


int main()
{
    int a[10][10],r,c;
    printf("enter the rows and columns\n");
    scanf("%d%d",&r,&c);
    read_ele(a,r,c);
    print_ele(a,r,c);
    find_avg(a,r);
    return 0;




}