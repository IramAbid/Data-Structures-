/****************************************************************************************************************************************************************
 NAME - IRAM ABID
 FACULTY ROLL NO- 20COB051
 ENROLLMENT NO- GJ8239
 
                /----------------QUICKSORT USING MEDIAN OF FIRST, LAST AND MIDDLE ELEMENT AS THE PIVOT------------------/
                
***************************************************************************************************************************************************************/
#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

int n;
void Display_Array(int arr[], int k)
{
    cout<<"\n\nTHE INTERMEDIATE OUTPUT AFTER EACH PASS:\t";
    for(int i = 0; i < k; i++)
    {
        cout<<arr[i]<<"\t";
    }
   
}

int count=0;

int Partition(int arr[], int left, int right)
{
    int count1=0;
    int pivot = arr[right];
    int pIndex = left;
    for (int i = left; i < right ; i++)
    {
        
        if (arr[i] < pivot)
        {
            count++;
            count1++;
            swap(arr[i],arr[pIndex]);
            
            
            pIndex++;
        }
    }
    swap(arr[right],arr[pIndex]);
    Display_Array(arr,n);
    cout<<"NO. OF COMPARIDIONS:\t"<<count1<<"\n";
    return pIndex;
}
 
int Partition_Middle(int arr[], int left, int right)
{
    int middle = (left + right)/2;
    if ((arr[left] <= arr[middle] <= arr[right]) || (arr[right] <= arr[middle] <= arr[left]))
    { 
        swap(arr[middle], arr[right]);
        return Partition(arr,left,right);
    }
    else
    {
        if ((arr[right] <= arr[left] <= arr[middle]) || (arr[middle] <= arr[left] <= arr[right]))
        {
        swap(arr[middle],arr[left]);
        }
        else if ((arr[left] <= arr[right] <= arr[middle]) || (arr[middle] <= arr[right] <= arr[left]))
        {
        swap(arr[middle],arr[right]);
        }
    swap(arr[middle], arr[right]);
    return Partition(arr,left,right);
    }
}

void QuickSort(int arr[], int left, int right)
{
   if (left < right )
    {
        int p =  Partition_Middle(arr, left, right);
        QuickSort(arr, left , p - 1);
        QuickSort(arr, p + 1 , right);
    }
}

int main()
{
     cout<<"\n<------------------------------------QUICKSORT USING MEDIAN OF FIRST, LAST AND MIDDLE ELEMENT AS THE PIVOT------------------------------->\n\n";

    cout<<"ENTER THE SIZE OF THE ARRAY:\t";

    cin>>n;

    cout<<"\n\n"; 

    int arr[n];
    
    srand(time(0));
    
    for(int i=0;i<n;i++)

    {
        arr[i]=rand()%100;
    }
    
    cout<<"\n<-----------------<<UNSORTED ARRAY AFTER QUICKSORT>>------------------>\n\n";
    
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<"\t";
       
    }
       cout<<"\n\n"; 
 
    
    QuickSort(arr,0,n-1);

   

    cout<<"\n<-----------------<<SORTED ARRAY AFTER QUICKSORT>>------------------>\n\n";
   for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<"\t";
       
    }
        cout<<"\n\n"; 
 
    cout<<"\n";
    cout<<"\nTOTAL NO. OF COMPARISIONS:\t"<<count<<"\n";

}