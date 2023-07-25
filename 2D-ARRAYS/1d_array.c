#include<stdio.h>
void read(int a[10],int n)
{
    int i;
    for(i=0;i<n;i++)
    {
      scanf("%d",&a[i]);        
    }

 return;   
}
void display(int a[10],int n)
{
    int i,cnt=0,y;
    for(i=0;i<n;i++)
    {
      printf("%d\n",a[i]);
      y=prime(a[i]);
      if(y==1)
       cnt++;
    }
    
    printf("%d",cnt);


 return;
}
int prime(int a)
{
    int i,flag=0;
    if(a==0||a==1)
    {
        flag=1;
    }
    
    for(i=2;i<a-1;i++)
    {
       if(a%i==0)
       { 
        flag=1;
        break;
       }      
    }


    if(flag==0)
     return 1;
    else
     return 0;
  
}



int main()
{
    int a[10],n;
    printf("enter n\n");
    scanf("%d",&n);
    read(a,n);
    display(a,n);


    return 0;

    
}