#include<stdio.h>
#include<math.h>
void read(int a[10][10],int r,int c);
void display(int a[10][10],int r,int c);
void count_prime(int a[10][10],int r,int c);
int count_prime1(int a[10],int c);
int isprime(int a);
void read(int a[10][10],int r,int c)
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
void count_prime(int a[10][10],int r,int c)
{
    int i,j,z;
    int d[r];
    
    for(i=0;i<r;i++)
    {
       d[r]=count_prime1(a[i],c);
       printf("%d\n",d[r]);
    }
}

int count_prime1(int a[10],int c)
{
   int j,cnt=0,p;
   
    for(j=0;j<c;j++)
   {
        if(a[j]<=1)
        continue;
      
       p=isprime(a[j]);
       if(p==1)
        { 
            cnt++;
        }
   }

   return cnt;
}


int isprime(int a)
{
    int i;
     
    for(i=2;i<=sqrt(a);i++)
    {
       if(a%i==0)
       return 0;
    }

    return 1;
}


int main()
{
    int a[10][10],r,c;
    printf("enter rows and columns\n");
    scanf("%d%d",&r,&c);
    read(a,r,c);
    display(a,r,c);
    count_prime(a,r,c);



    return 0;
}