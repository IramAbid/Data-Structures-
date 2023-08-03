/****************************************************************************************************************************************************************
 NAME - IRAM ABID
 FACULTY ROLL NO- 20COB051
 ENROLLMENT NO- GJ8239
 
                /----------------Quicksort using middle element as pivot------------------/
                
***************************************************************************************************************************************************************/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void quickSort(int arr[], int left, int right, int size) {

      int i = left, j = right;

      int tmp,count1;

      int pivot = arr[(left + right) / 2]; // taking middle element as the pivot

      /* code for partition */

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
          
           }
           count1++;
                  
      };
      
        printf("\nTHE INTERMEDIATE ARRAY AFTER EACH PASS:\t" );
    
    for(int i=0;i<size;i++)
    {
        printf("\t%d",arr[i]);
        
    }
    
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
      printf("\nTHE TOTAL NUMBER OF THE COMPARISION:\t%d",count1);

}

int main()
{
    int n,right,left,pivot,count1=0;

    printf("\n<-----------------QUICKSORT USING MIDDLE ELEMENT AS THE PIVOT------------------>\n\n");

    printf("ENTER THE SIZE OF THE ARRAY:\t");

    scanf("%d",&n);

    printf("\n\n"); 

    int arr[n];
    
    srand(time(0));
    
    for(int i=0;i<n;i++)

    {
        arr[i]=rand()%100;
    }
    
    printf("THE UNSORTED ARRAY :\t" );
    
    for(int i=0;i<n;i++)
    {
        printf("%d\t",arr[i]);
       
    }
        printf("\n\n"); 

    quickSort(arr,0,n-1,n);
    
   
     
 
    printf("\n"); 

    printf("\n  THE SORTED ARRAY :\t" );
    
    for(int i=0;i<n;i++)

    {
        printf("%d\t",arr[i]);
        
    }
    
}