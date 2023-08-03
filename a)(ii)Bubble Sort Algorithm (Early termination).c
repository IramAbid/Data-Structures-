/******************************************************************************
Name – Iram Abid,
Faculty roll no. - 20COB051
Enrolment no. -GJ8239
Serial no- 06
      Question-a)(ii)Bubble Sort Algorithm (Early termination)
*******************************************************************************/

#include<stdio.h>
#include<stdlib.h>  
#include<time.h>
int main()
{
    
  int n, i, j;

    printf("Enter the size of the array = ");
    scanf("%d",&n);
    
//Generating numbers using random number generator

    int array[n], temp;
    srand(time(0));

//Sorting array using Bubble Sort Algorithm(Early termination)
    for(i=0;i<n;i++)
    {
        array[i]=rand()%100;
    }
  
    int count=0,count1=0;
    for(i=0; i<n-1; i++)
    {
        
        int flag = 0;
        
        for(j=0; j<n-i-1; j++)
       { count++;
       count1++;
          if(array[j]>array[j+1])
          {
             flag = 1;
             int temp = array[j+1];
             array[j+1] = array[j];
             array[j] = temp;
          }
       }
      // No Swapping happened, array is sorted(Early Termination)
      if(flag==0)
      {
         break;
      }
       printf("\nThe sorted array after pass %d becomes:",i+1);
        for(int i=0;i<n;i++)
        {
            printf("%d ",array[i]);
        }
         printf("\nThe total number of comparisions are %d \n",count1);
         count1=0;

       
   }
    printf("\n");
    printf("\nThe total number of comparisions are %d \n",count);
    printf("The Final Sorted Array is:");
    
    for(int i=0;i<n;i++)
    {
        printf("%d ",array[i]);
    }

}