#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define size 100000
void print_array(int a[size],int n);                       //display the array
void read_array(int a[size],int n);                        //reading the array 
void bubble_sort(int a[size],int n);                       //bubble sort
void selection_sort(int a[size],int n);                    //selection sort
void rand_numbers(int n,int lower,int upper,FILE *fp);     //printing the random numbers 
void read_array_file(int *a,FILE *fp,int n);               //reading the numbers from file
void print_num_file(int n,int *a,FILE *fp);                //printing the numbers in file 
void merge(int arr[], int p, int q, int r);
void merge(int arr[], int p, int q, int r);
void mergeSort(int arr[], int l, int r);
void main()
{
 FILE *fp; 
 FILE *fp1;
 FILE *fp2; 
 int a[size];
 int n,low,hig;
 printf("enter the number of random numbers to be written:");
 scanf("%d",&n);
 printf("enter the lower the range of the number:");
 scanf("%d",&low);
 printf("enter the higher range of number:");
 scanf("%d",&hig);
 fp=fopen("input.txt","w");
 rand_numbers(n,low,hig,fp); 
 fclose(fp);
 fp1=fopen("input.txt","r");
 read_array_file(&a[0],fp1,n);
 fclose(fp1);
 //print_array(a,n);           
 bubble_sort(a,n);          
 //selection_sort(a,n);
 //mergeSort(a,0,n-1);
 //printf("\n");
 //print_array(a,n);
 fp2=fopen("output.txt","w");
 print_num_file(n,&a[0],fp2);
 fclose(fp1);



}
void bubble_sort(int a[size],int n)
{
    int i;
    int j;
    int temp;
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(a[j]>a[j+1])
            {
             temp=a[j];
             a[j]=a[j+1];
             a[j+1]=temp;
            }
        }
    }
}
void read_array(int a[size],int n)
{
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
}
void print_array(int a[size],int n)
{
    for(int i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
}
void selection_sort(int a[size],int n)
{
    int i;
    int j;
    int temp;
    for(i=0;i<n-1;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(a[i]>a[j])
            {
               temp=a[j];
               a[j]=a[i];
               a[i]=temp;
            }
        }
    }
}
void rand_numbers(int n,int lower,int upper,FILE *fp)
{
    int num;
for(int i=0;i<n;i++)
{  
    num=lower+rand()%(upper-lower+1);
    fprintf(fp,"%d ",num); //printing the numbers in input file 
      
}
}
void read_array_file(int *a,FILE *fp,int n)
{
    int num;
for(int i=0;i<n;i++)
{
    fscanf(fp,"%d",&num);
    *(a+i)=num;
}
}
void print_num_file(int n,int *a,FILE *fp)
{
int i;
for(i=0;i<n;i++)
{
    fprintf(fp,"%d ",*(a+i));

}

}
// Merge sort in C

// Merge two subarrays L and M into arr
void merge(int arr[], int p, int q, int r) 
{

  // Create L ← A[p..q] and M ← A[q+1..r]
  int n1 = q - p + 1;
  int n2 = r - q;

  int L[n1], M[n2];

  for (int i = 0; i < n1; i++)
    L[i] = arr[p + i];
  for (int j = 0; j < n2; j++)
    M[j] = arr[q + 1 + j];

  // Maintain current index of sub-arrays and main array
  int i, j, k;
  i = 0;
  j = 0;
  k = p;

  // Until we reach either end of either L or M, pick larger among
  // elements L and M and place them in the correct position at A[p..r]
  while (i < n1 && j < n2) {
    if (L[i] <= M[j]) {
      arr[k] = L[i];
      i++;
    } else {
      arr[k] = M[j];
      j++;
    }
    k++;
  }

  // When we run out of elements in either L or M,
  // pick up the remaining elements and put in A[p..r]
  while (i < n1) {
    arr[k] = L[i];
    i++;
    k++;
  }

  while (j < n2) {
    arr[k] = M[j];
    j++;
    k++;
  }
}

// Divide the array into two subarrays, sort them and merge them
void mergeSort(int arr[], int l, int r) 
{
  if (l < r) {

    // m is the point where the array is divided into two subarrays
    int m = l + (r - l) / 2;

    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);

    // Merge the sorted subarrays
    merge(arr, l, m, r);
  }
}



