/******************************************************************************
Name – Iram Abid,
Faculty roll no. - 20COB051
Enrolment no. -GJ8239
Serial no- 06
                      Question-a) (i) Linear Search
*******************************************************************************/

#include<stdio.h>
#include<stdlib.h>

int main()
{
    
int n, numb, i, j;

printf("Enter the size of the array = ");
scanf("%d",&n);

int array[n], temp;

for(int i=0;i<n;i++)
  {
    array[i]=rand()%100;
  }

//sorting the element in order-

for(i=0;i<n;i++)
{
    for(j=i+1;j<n;j++)
    
        if(array[i]>array[j])
        {
            temp = array[i];
            array[i]=array[j];
            array[j]=temp;
        }
}

//Searching the entered number-

printf("\nEnter the number = ");

scanf("%d",&numb);

for(i=0;i<n;i++)
 {
    if (numb==array[i]) 
     {
        printf("Number is found and have index: %d\n",i);
        printf("Number of comparisions are: %d",i+1);
        break;
     }
    else if(i==n-1)
     {
        printf("Number not found in array");
     }
 }

}

