/****************************************************************************************************************************************************************
 NAME - IRAM ABID
 FACULTY ROLL NO- 20COB051
 ENROLLMENT NO- GJ8239
 
                /----------------Quicksort using random element as pivot------------------/
                
***************************************************************************************************************************************************************/
#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;
int k=0;

int Partition(int a[], int low, int high) {
   int pivot, index, i;
   index = low;
   pivot = high;
   for(i=low; i < high; i++) {
      // finding index of pivot.
      if(a[i] < a[pivot]) {
         swap(a[i], a[index]);
         index++;
         k++;
      }
   }
   swap(a[pivot], a[index]);
   return index;
}
int RandomPivotPartition(int a[], int low, int high){
   // Random selection of pivot.
   int pvt, n, temp;
   n = rand();
   pvt = low + n%(high-low+1); // Randomizing the pivot value from sub-array.
   swap(a[high], a[pvt]);
   return Partition(a, low, high);
}
void quick_sort(int arr[], int p, int q,int n) {
   
   int pindex;
   if(p < q) {
      pindex = RandomPivotPartition(arr, p, q); //randomly choose pivot
      // Recursively implementing QuickSort.
      cout << "\n\nAFTER EACH PASS THE INTERMEDIATE ARRAY:\t";
      
    for (int i = 0; i < n; i++)
    cout<<arr[i] << "\t";
      quick_sort(arr, p, pindex-1,n);
    quick_sort(arr, pindex+1, q,n);
}
}
int main() 
{
    int i,n;
    cout<<"\n<-----------------QUICKSORT USING RANDOM ELEMENT AS THE PIVOT------------------>\n\n";
    cout<<"ENTER THE SIZE OFF THE ARRAY:\t";
    cin>>n;
    srand(time(0));
    int arr[n];
    for (i = 0;i <n; i++)
    arr[i] = rand()%100;
    cout << "\nTHE UNSORTED ARRAY:\t";
    for (i = 0; i < n; i++)
    cout<<arr[i] << "\t";

    quick_sort(arr, 0, n - 1,n); //sort the elements of array
    cout << "\n\nTHE TOTAL NUMBER OF COMPARISONS :\t"<<k;
     cout << "\nTHE SORTED ARRAY:\t";
    for (int i = 0; i < n; i++)
    cout<<arr[i] << "\t";
    cout << endl;
    return 0;
}