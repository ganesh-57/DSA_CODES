#include<stdio.h>
#include<string.h>
#include<strings.h>
int main()
{
    char f[20];
    int i;
    int n;
    int c_apple=0;
    int c_orange=0;
    float a,s,t,b;
    printf("enter the corrdinates of tree apple\n");
    scanf("%f",&a);
    printf("enter the corrdinates of tree orange\n");
    scanf("%f",&b);
    printf("enter the coordinates of the house\n");
    scanf("%f%f",&s,&t);
    float d;

    printf("enter the number of fruits fallen");
    scanf("%d",&n);
    for(i=0;i<n;i++)
{
 printf("enter the type of fruit fallen\n");
 scanf("%s",f);
 printf("enter the distance falllen by the fruit\n");
 scanf("%f",&d);
 if(strcasecmp(f,"APPLE")==0)
 {
    if(d>0)
    {
        if(d>=s-a && d<=a+t)
         c_apple++;
         
    }
 }
 else if(strcasecmp(f,"ORANGE")==0)
 {
       if(d<0)
    {
        d=-d;
        
        if(d>=b-t && d<=b-s) 
            c_orange++;

         
    }
 
 }
 else
 {
    printf("invalid input\n");
 }
}
 printf("the number od apples fallen in house %d",c_apple);
 printf("the number od oranges fallen in house %d",c_orange);
}
