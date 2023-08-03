
/******************************************************************************
Name – Iram Abid,
Faculty roll no. - 20COB051
Enrolment no. -GJ8239
Serial no- 06
                      Assignment 3- bubbleSort Classes in c++
*******************************************************************************/
#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

class lets_BubbleSort
{
    private:
    int n,Array[100];
    void GenerateArray(); //Generates an Array
    public:
    lets_BubbleSort() //constructor
    {
        GenerateArray();
    }
    void BubbleSortArray(); // to BubbleSort Array
    void Swap(int *a,int *b); // to swap elements
    void PrintArray();// to print the array
};
void lets_BubbleSort :: GenerateArray()
{
    cout << "Enter the size of the array:";
    cin >> n;
    int i;
     srand(time(0)); 
    for(i=0;i<n;i++){
        Array[i]= (rand() % 100);
    }
}
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void lets_BubbleSort :: BubbleSortArray() //
{
    for ( int i = 0; i < n - 1; i++)
    {
        for ( int j = 0 ; j < n - i - 1; j++)
        {
            if(Array[j]>Array[j+1])
            {
                swap(&Array[j],&Array[j+1]);
            }
           
        }
        
    }
}
void lets_BubbleSort :: PrintArray()
{
   
    for ( int i = 0; i < n ; i++)
    {
        cout<<"\t "<<Array[i];
    }
}
int main()
{
    lets_BubbleSort obj;

    cout<<"\nINITIAL ARRAY: ";
    obj.PrintArray();
    obj.BubbleSortArray();
    cout<<"\n SORTED ARRAY: ";
    obj.PrintArray();
    return 0;
}