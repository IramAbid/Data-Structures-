/******************************************************************************
Name – Iram Abid,
Faculty roll no. - 20COB051
Enrolment no. -GJ8239
Serial no- 06
                      Iterative or Non-Recursive Merge Sort
*******************************************************************************/
#include<iostream>
#include <ctime>
#include <cstdlib>
using namespace std;
int i,n,size, Arr[50], N_array[50],p=1;
void Gen_Array()
{
    cout<<"\nENTER THE SIZE OF THE ARRAY:\t";
    cin>>size;
    cout<<"\nGENERATED ARRAY BEFORE SORTING:\t";
    
    srand(time(0)); 
    int array[size];
    for(i=0;i<size;i++){
        Arr[i]= (rand() % 100);
    }
}
//function to print the array
void Print_Array()
{
    
    for ( i = 0; i < size; i++)
    {
        cout<<"\t"<<Arr[i];
    }
    //cout<<endl;
}
/* function to merge and display intermediate output*/
void Merge(int Arr[], int  N_array[], int lb1, int ub1, int lb2, int ub2)
{
    int i=lb1, j=lb2, k=lb1;
    while(i <= ub1 && j <= ub2)
    {
        if (Arr[i] < Arr[j])
        {
            N_array[k] = Arr[i];
            i++;
            k++;
        }
        else
        {
            N_array[k] = Arr[j];
            j++;
            k++;
        }

    }
    while(i <= ub1)
    {
        N_array[k] = Arr[i];
            i++;
            k++;
    }
    while(j <= ub2)
    {
        N_array[k] = Arr[j];
            j++;
            k++;
    }
    
    for ( i = lb1; i <= ub2; i++)
    {
        Arr[i]=N_array[i];
    }
    
    cout<<"\nINTERMEDIATE OUTPUT AFTER PASS "<<p<<":\t";
    for ( i = 0; i < size; i++)
    {
        cout<<Arr[i]<<"\t";
    }
    cout<<"\n";
    
    p++;
}

void MergePass(int Arr[],int  N_array[], int n, int size)
{
    int lb1=0, lb2, ub1, ub2;
    while(lb1 + n < size)
    {
        lb2 = lb1 + n; 
        ub1 = lb1 + n - 1;
        ub2 = lb2 + n - 1;
        if ( ub2 >= size)
        {
            ub2 = size - 1 ; 
        }
        Merge(Arr,N_array, lb1 ,ub1, lb2, ub2);
        lb1 = ub2 + 1;
        }
}

void MergeSort(int Arr[],int size)
{
    n = 1;
    while(n < size)
    {
        MergePass(Arr, N_array,n,size);
        n = n * 2;
    }
}

int main()
{
    cout<<"\nITERATIVE MERGE SORT PROGRAM\n";
    Gen_Array();
    Print_Array();
    cout<<"\n";
    MergeSort(Arr,size);
    cout<<"\n\nTHE SORTED ARRAY IS :";
    Print_Array();
    
}