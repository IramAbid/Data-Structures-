/******************************************************************************
Name – Iram Abid,
Faculty roll no. - 20COB051
Enrolment no. -GJ8239
Serial no- 06
      Question-b)(i)Standard Insertion Sort Algorithm 
*******************************************************************************/

#include<stdio.h>
#include<stdlib.h>  
#include<time.h>
int main()
{
    
  int n, i, j;

    printf("Enter the size of the array = ");
    scanf("%d",&n);
    
//Generating numbers using Random Number enerator

    int array[n], temp, count=0, TotalCount=0;
    srand(time(0));
    for(i=0;i<n;i++)
    {
        array[i]=rand()%100;
    }

//Sorting array using Standard Insertion Sort Algorithm

    for (i = 1; i < n; i++)
    {
        temp = array[i];
    j = i - 1; 
        while (j >= 0 && array[j] > temp)
        
        { 
            count++;
            TotalCount++;
            array[j + 1] = array[j]; 
            j = j - 1; 
        } 
        
        array[j + 1] = temp; 
        
        printf("\nThe sorted array becomes:");
        for(int i=0;i<n;i++)
        {
        printf("%d ",array[i]);
        }
       printf("\nThe total number of comparisions are %d \n",count);
         count=0; 
    }
    printf("\n");
    printf("\nThe total number of comparisions are %d \n",TotalCount);
    printf("The Final Sorted Array is:");   
    for(int i=0;i<n;i++)
    {
        printf("%d ",array[i]);
    }

}
   
