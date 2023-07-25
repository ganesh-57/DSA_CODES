#include<stdio.h>
#define row 10
#define col 10
void read(int a[row][col],int r,int c);
void print_ele(int a[row][col],int r,int c);
void trans(int a[row][col],int r,int c,int b[row][col]);
void multi(int a[row][col],int r1,int c1,int b[row][col],int r2,int c2,int res[row][col]);
int ortho(int a[row][col],int r,int c);
int main()
{
    int r,c,p;
    int a[row][col];
    int b[row][col];
    int z[row][col]={0};
    printf("enter the order of elements\n");
    scanf("%d%d",&r,&c);
    read(a,r,c);
    trans(a,r,c,b);
    multi(a,r,c,b,c,r,z);
    p=ortho(z,c,c);
    if(p==1)
    {
    printf("orthogonal\n");
    }


return 0;
}

void read(int a[row][col],int r,int c)
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
void print_ele(int a[row][col],int r,int c)
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
void trans(int a[row][col],int r,int c,int b[row][col])
{
    int i,j;
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            b[j][i]=a[i][j];
        }
    
    }
    
    

return;
}

void multi(int a[row][col],int r1,int c1,int b[row][col],int r2,int c2,int res[row][col])
{

   int i,j,k;
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


return;
}
int ortho(int a[row][col],int r,int c)
{
     int i,j;
     for(i=0;i<r;i++)
     {
         for(j=0;j<c;j++)
         {

         if(i==j && a[i][j]!=1)
         return 0;
         else if(i!=j && a[i][j]!=0)
         return 0;
         
         }
     
     }
     return 1;

}


/*int main()
{
    int r,c,p;
    int a[row][col];
    int b[row][col];
    int z[row][col]={0};
    printf("enter the order of elements\n");
    scanf("%d%d",&r,&c);
    read(a,r,c);
    trans(a,r,c,b);
    multi(a,r,c,b,c,r,z);
    p=ortho(z,c,c);
    if(p==1)
    {
    printf("orthogonal\n");
    }

}*/
