#include<stdio.h>
#define size 100
int binarysearch(int a[size],int x,int low,int high)
{
while(low<=high)
{
  int mid=(low+high)/2;
    if(a[mid]==x)
    return mid;
    if(a[mid]<x)
     low=mid+1;
     else 
     high=mid-1;
}

return -1;

}
int main()
{
    int a[size];
    int i;
    int c,n,x;
    printf("enetr the size of an array\n");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);

    }
    printf("enter the element to be searched\n");
    scanf("%d",&x);
    
    c=binarysearch(a,x,0,n-1);
    if(c==-1)
    {
        printf("not found\n");

    }
    else 
    printf("element is found at %d\n",c);



    
}