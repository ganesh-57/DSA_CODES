#include<stdio.h>
#include<string.h>
#include<strings.h>
#include<ctype.h>
int max_array(int a[],int n);

void main()
{
    FILE *fp;
    int max;
    int i=0;
    char str1[100]={"ould"};
    char str[100];
    int array[10];
    fp=fopen("GANES.txt","r");
    while(!feof(fp))
    {
     fgets(str,sizeof(str),fp);
     array[i]=strlen(str);
     i++;
    }
    fp=fopen("GANES.txt","r");
    max=max_array(array,i);
    while(!feof(fp))
    {   
     fgets(str,sizeof(str),fp);
     if(strlen(str)==max)
     {
        puts(str);
     }
    }
    fp=fopen("GANES.txt","r");
    while(!feof(fp))
    {
        i=0;
        fgets(str,sizeof(str),fp);
         while(str[i]!='\0')
         {
           // if(strcasecmp(str[i],"O")&& strcasecmp(str[i+1],"U") && strcasecmp(str[i+2],"L") && strcasecmp(str[i+3],"D"))
           if(toupper(str[i])=='O' && toupper(str[i+1])=='U'&& toupper(str[i+2])=='L'&& toupper(str[i+3])=='D')
          {
            puts(str);
            i++;   
          }
           i++;

         }



    }
    

    fclose(fp);
}
int max_array(int a[],int n)
{
    int i;
    int pos;
    int max=a[0];
    for(i=0;i<n;i++)
    {
        if(max<a[i])
        {
            max=a[i];
        }
    }

    return max; 
}
