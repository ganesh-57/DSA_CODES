#include<stdio.h>
#include<stdlib.h>
typedef struct num
{
    int data;
    struct num *net;
}*node;
int main()
{

}
node getnode(void)
{
   node temp;
   temp=(node)malloc(sizeof(struct num));
   if(temp==NULL)
   printf("inssuficient memory\n");
   


}