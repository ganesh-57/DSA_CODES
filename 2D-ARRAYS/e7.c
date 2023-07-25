#include<stdio.h>
#define row 100
#define col 100
void max(int a[row][col],int r,int c); 
void read_array(int a[row][col],int r,int c);
void display_array(int a[row][col],int r,int c);
void sum(int a[row][col],int r,int c);
int main()
{
    int a[row][col];
    int r,c;
    printf("enter row and columns\n");
    scanf("%d%d",&r,&c);
    read_array(a,r,c);
    display_array(a,r,c);
    max(a,r,c);
  //sum(a,r,c);

return 0;
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
void sum(int a[row][col],int r,int c)
{
    float k=0;
    float z[row];
    int i,j;
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            k=k+a[i][j];

        }
        z[i]=k;

        //printf("sum is %d\n",k);
        k=0.0;
        

    }
    for(i=0;i<r;i++)
        {
            printf("%f\n",z[i]/c);
        }
}

/*
void sum(int a[row][col],int r,int c)
{
    int k=0;
    int i,j;
    for(j=0;j<c;j++)
    {
        for(i=0;i<r;i++)
        {
            k=k+a[i][j];

        }
        printf("sum is %d\n",k);
        k=0;

    }
}
*/

/*void max(int a[row][col],int r,int c)
{
 int i,j;
 int m;
   for(i=0;i<r;i++)
   {
       for(j=0;j<c;j++)
         {
             m=a[i][0]; 
             if(a[i][j]>m)
             {
                 m=a[i][j];
             }
        }
        printf("%d\n",m);

   }

}*/
void max(int a[row][col],int r,int c)
{
 int i,j;
 int m;
   for(j=0;j<c;j++)
   {
       for(i=0;i<r;i++)
         {
             m=a[0][j]; 
             if(a[i][j]>m)
             {
                 m=a[i][j];
             }
        }
        printf("%d\n",m);

   }
}

