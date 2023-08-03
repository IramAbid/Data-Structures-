# include <iostream>
using namespace std;
int size;
void print_array(int myarray[], int size)
    {
        for(int i=0;i<size;i++)
       {
        cout<<myarray[i]<<" ";
       }
    }
void Swap(int *a, int *b)
{
   int temp = *a;
   *a = *b;
    *b = temp;
}
//sorting algorithm
int count=0;
int partition(int arr[], int l, int r){
    int pivot = arr[r];
    int pIndex = l;

    for(int i = l; i<r; i++)
    {
        count++;
        if(arr[i]<pivot)
        { 
          Swap(&arr[i],&arr[pIndex]);
          print_array(arr,size);
          cout<<"\tCOMPARISONS :"<<count<<"\n";
          pIndex++;   
        }
    }
    Swap(&arr[r],&arr[pIndex]);
    print_array(arr,size);
    cout<<"\tCOMPARISONS :"<<count<<"\n";
    count++;
    return pIndex;
}

int Partition_Middle(int arr[], int l, int r){
    int middle = (l + r)/2;
    Swap(&arr[middle], &arr[r]);
    return partition(arr, l, r);
}

void QuickSort( int arr[],int l, int r) {
    if(l<r)
    {
        int pi = Partition_Middle(arr,l,r);
        QuickSort(arr, l, (pi-1)); //call for left part
        QuickSort(arr, (pi+1), r); //call for right part
    }
}

int main(){
    
    cout<<"Size of Array: "<<endl;
    cin>>size;
    int arr[size];
    cout<<"Enter "<<size<<" integrs in any order: "<<endl;
    for(int i=0;i<size;i++)
    {
        cin>>arr[i];
    }
    cout<<"Before sorting"<<endl;
    print_array(arr,size);
    cout<<endl;
    QuickSort(arr,0,(size-1)); //calling Quick Sort
    cout<<"\nTOTAL COMPARISIONS: \n"<<count<<"\n";
    cout<<"After Sorting"<<endl;
    print_array(arr,size);
    return 0;
}