#include<stdio.h>
#define row 100
#define col 100
void read_array(int a[row][col],int r,int c);
void display_array(int a[row][col],int r,int c);
void trans(int a[row][col],int r,int c);
int main()
{
  
    int a[row][col];
    int r,c;
    printf("enter row and columns\n");
    scanf("%d%d",&r,&c);
    read_array(a,r,c);
    display_array(a,r,c);
    trans(a,r,c);
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
void display_array(int a[row][col],int r,int c)
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


}
void trans(int a[row][col],int r,int c)
{
        int i,j;
         int b[row][col];
        for(i=0;i<r;i++)
        {
            for(j=0;j<c;j++)
            {
               b[j][i]=a[i][j];

            }
        }

        display_array(b,r,c);

        return;
}