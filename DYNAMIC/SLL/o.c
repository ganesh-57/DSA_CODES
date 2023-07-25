#include<stdio.h>
#include<stdlib.h>
typedef struct data
{
    char str[40];
    int amount;
}DATA;
typedef struct node 
{
    struct node *prev;
    struct node *next;
    DATA D;
}*NODE;
void display(struct data d);
void read(struct data *f);
int main()
{
    printf("Enter name and amount\n");
    struct data d;
    read(&d);
    display(d);

}
void read(struct data *f)
{
  scanf("%s",f->str);
  scanf("%d",&f->amount);
}
void display(struct data d)
{
    printf("%s %d",d.str,d.amount);
    return;
}