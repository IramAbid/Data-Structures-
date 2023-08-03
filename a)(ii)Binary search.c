/******************************************************************************
Name – Iram Abid,
Faculty roll no. - 20COB051
Enrolment no. -GJ8239
Serial no- 06
                      Question-a) (ii) binary Search
*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
 
int main()
{
int n, numb, i, j;

printf("Enter the size of array:");
scanf("%d", &n);

int array[n];
for (i=0;i<n;i++)
{
  array[i]=rand() % 100; 
}
 
 
 //sorting the element in order-

for(i=0;i<n;i++)
{
    for(j=i+1;j<n;j++)
    
        if(array[i]>array[j])
        {
            int temp;
            temp = array[i];
            array[i]=array[j];
            array[j]=temp;
        }
}

printf("Enter the number for search:"); 
scanf("%d", &numb);
  
 
int l=0, r=n-1, mid;
int cmpr = 0;

while (l<= r)
{
  cmpr++;
  mid=(l + r) / 2;
  if (numb==array[mid])
  { 
      printf("Number matched and index is %d\n",mid);
      printf("Number of comparisons are %d\n", cmpr);
      
    break;
  }
  
  else if (numb<array[mid])
  {
    r = mid - 1;
  }
 else

 {
  l=mid+1;
 }
 if(l>r)
 {
  printf("Number not found in the array.");
 }
}
return 0;
}
