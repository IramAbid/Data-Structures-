/****************************************************************************************************************************************************************
 NAME - IRAM ABID
 FACULTY ROLL NO- 20COB051
 ENROLLMENT NO- GJ8239
 
                /----------------Quicksort using first element as pivot------------------/
                
***************************************************************************************************************************************************************/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
 int count1=0;
void quickSort(int arr[], int left, int right, int size) {

      int i = left, j = right;

      int tmp;

      int pivot = arr[left]; // taking first element as the pivot

      /* code for partition */
      int count=0;
      while (i <= j) {

            while (arr[i] < pivot)

                  i++;

            while (arr[j] > pivot)

                  j--;

            if (i <= j) {
                
                  
                  tmp = arr[i];

                  arr[i] = arr[j];

                  arr[j] = tmp;

                  i++;

                  j--;
                  count++;
                 
           }
          
                  
      };
        count1=count1+count;
        
        printf("\nTHE INTERMEDIATE ARRAY AFTER EACH PASS:\t" );
    
    for(int i=0;i<size;i++)
    {
        printf("\t%d",arr[i]);
        
    }
    printf("\tTHE NO. OF COMPARISION:\t%d",count );
    
      /* recursively calling the function */

      if (left < j)
      {
            quickSort(arr, left, j, size);
            }
     else if (i < right)
           {
            quickSort(arr, i, right,size);
           }
     else
      printf("\n\nTHE TOTAL NUMBER OF THE COMPARISION:\t%d",count1);

}

int main()
{
    int n,right,left,pivot;
    printf("\n<-----------------QUICKSORT USING FIRST ELEMENT AS THE PIVOT------------------>\n\n");
    printf("ENTER THE SIZE OF THE ARRAY:\t");
    scanf("%d",&n);
    printf("\n\n"); 
    int arr[n];
    
    srand(time(0));
    
    for(int i=0;i<n;i++)
    {
        arr[i]=rand()%100;
    }
    
    printf("<----------------THE UNSORTED ARRAY------------------>\n" );
    
    for(int i=0;i<n;i++)
    {
        printf("%d\t",arr[i]);
       
    }
        printf("\n\n"); 
    quickSort(arr,0,n-1,n);
    
   
     
 
    printf("\n"); 
    printf("\n<-------------------THE SORTED ARRAY-------------------->\n" );
    
    for(int i=0;i<n;i++)
    {
        printf("%d\t",arr[i]);
        
    }
    
}