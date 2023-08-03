/******************************************************************************
Name – Iram Abid,
Faculty roll no. - 20COB051
Enrolment no. -GJ8239
Serial no- 06
      Question-a)(i) Standard Bubble Sort Algorithm 
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
    //Sorting array using Bubble Sort Algorithm
    for(i=0;i<n;i++)
    {
        array[i]=rand()%100;
    }

//Sorting array using Bubble Sort Algorithm
int count=0,Totalcount=0;
for(int i=0; i<n-1; i++)
    {
       for(int j=0; j<n-i-1; j++)
       
       {    Totalcount++;
           count++;
          if(array[j]>array[j+1])
          {
             int temp = array[j+1];
             array[j+1] = array[j];
             array[j] = temp;
             
          }
         
       }
        
        printf("\nThe sorted array after pass %d becomes :",i+1);
            for(int i=0;i<n;i++)
                {
                printf("%d ",array[i]);
                }
        printf("\nThe total number of comparisions in this %d \n",count);
        count=0;
       
       
    }
    
    printf("\n");
    printf("\nThe total number of comparisions are %d \n",Totalcount);
    printf("The Final Sorted Array is:");
    
    for(int i=0;i<n;i++)
    {
        printf("%d ",array[i]);
    }

}