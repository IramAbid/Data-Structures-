/******************************************************************************
Name – Iram Abid,
Faculty roll no. - 20COB051
Enrolment no. -GJ8239
Serial no- 06
                      Iterative or Non-Recursive Merge Sort
                      Tabbing with Binary Search
*******************************************************************************/
#include<iostream>
#include <math.h>
#include<ctime>
using namespace std;
void display(int [],int );
int binary_search(int array[],int lower_limit, int upper_limit, int x) //Function for Binary search.
{
   int l = lower_limit, h = upper_limit, mid;
    mid=(l+h)/2;
    while(l<=h)
    {
        mid=(l+h)/2;
        if(x==array[mid])
        {
            return mid;
            break;
        }
        else if(x<array[mid])
            h=mid-1;
        else
            l=mid+1;
    }
}
void tabbing(int A[],int s1,int s2,int e1,int e2,int B[])   //Function for Tabbing.
{
    cout<<"\nTabbing fuction is called here\n";
    int num_tab=ceil((double)(e1-s1)/(double)(e2-s2));
    int n1=s1, i=s2, k=s1, LBT, temp, x;
    for(i=s2; i<e2; i++)
    {
        int j = s1;                                     //stores upper bound of a tab
        int m = k;
        while(j < e1)                                   //finding the tab
        {
            if(A[i] < A[j])
                break;
            if(j + num_tab >= e1)
            {
                LBT = j;
                j = e1 - 1;
                break;
            }
            LBT = j;
            j += num_tab;
        }
        if(A[i] <= A[j])
        {
            temp = A[i];
            if(j == s1)
                B[n1++] = A[i];

            else
            {
                k = binary_search(A, LBT, j, temp);     //Calling Binary Search Function.
                for(x = m; x < k; x++)
                    B[n1++] = A[x];
                B[n1++] = A[i];
            }
        }
        else
            break;
    }
    while(k != e1)                                       //Copying the remaining elements.
        B[n1++] = A[k++];
    while(i<e2)
        B[n1++] = A[i++];
}


void merge(int L[],int n1,int n2,int size1,int size2,int R[])      //Function of Merge.
{
    int i=n1;
    while(i<size2)
    {
        if(L[n1]<L[n2])
        {
            R[i]=L[n1];
            i++;
            n1++;
        }
        else
        {
            R[i]=L[n2];
            i++;
            n2++;
        }
        if(n1==size1)
        {
            while(n2<size2)
            {
                R[i]=L[n2];
                n2++;
                i++;
            }
            break;
        }
        if(n2==size2)
        {
            while(n1<size1)
            {
                R[i]=L[n1];
                n1++;
                i++;
            }
            break;
        }
    }
 

}
void merge_pass(int a[],int n,int l,int b[])       //Function to Call Merge Or Tabbing.
{
    int lb=0, ub=2*l, numpair=n/(2*l);             //variable declaration and assignment_of_values.
    int k=1;
    while(k<=numpair)
    {
        merge(a,lb,lb+l,lb+l,ub,b);
        k++;
        lb=ub;
        ub+=(2*l);
    }
    if(n%(2*l)>0)                                  //Condition for the tabbing or merging to occur.
    {
        if(n%(2*l)>l)
            (n-lb-l)>(l+n-lb-l)?merge(a,lb,lb+l,lb+l,n,b):tabbing(a,lb,lb+l,lb+l,n,b);
        else
        {
            while(lb<n)
            {
                b[lb]=a[lb];
                lb++;
            }
        }
    }
    cout<<"\nINTERMEDIATE OUTOUT:\t";
    display(b, n);                                 //Calling display Function.
}
void mergesort(int a[],int n)                //Function to MergeSort.
{
     int b[n],l;
     for( l=1;l<n;l*=4)
     {
        merge_pass(a,n,l,b);
        merge_pass(b,n,2*l,a);
     }
}


void display(int arr[], int n)                     //Function to display array elements.
{
    int i;
    cout<<"\t";
    for(i=0;i<n;i++)
    {
        if(i!=0)
            cout<<"\t";
        cout<<arr[i];
    }
    cout<<"\n";
}

int main()                                          //Main Function.
{
    int n, i;                                       //variable declaration
    cout<<"ENTER THE SIZE OF THE ARRAY:";
    cin>>n;
    cout<<"\n";
    int a[n];
    srand(time(0));
    for(i=0;i<n;i++)
    {
        a[i]=rand()%100;                                 //Generating the array elements randomly.
    }
    cout<<"GENERATED ARRAY BEFORE SORTING:";
    display(a, n);                                       //Calling display Function.
    
    mergesort(a, n);                                    //Calling MergeSort.
    cout<<"\nSORTED ARRAY IS:\t";
    display(a, n);
    return 0;
}