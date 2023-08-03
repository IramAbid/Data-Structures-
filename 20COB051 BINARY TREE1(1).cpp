/******************************************************************************
Name - Iram Abid,
Faculty roll no. - 20COB051
Enrolment no. -GJ8239
Serial no- 06
               
                                BINARY TREE
*******************************************************************************/
#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;

class BinaryTree_sequential
{
private:
    int height;
    int size;
    int *P;

public:
    BinaryTree_sequential(int height);
    void Create(int a, char x, int element);
    int Delete(int index);
    void Display();
    int Search(int b);
    void preorder(int index);
    void inorder(int index);
    void postorder(int index);
};

BinaryTree_sequential::BinaryTree_sequential(int height)
{
    this->height = height;
    size = (int)pow(2, height + 1) - 1;
    P = new int[size]{0};
}

void BinaryTree_sequential::Create(int a, char x, int element)
{
    if (P[0] == 0)
    {
    P[0] = element;
    }
    else if (P[0] != 0 && x == 'l' || P[0] != 0 && x == 'L')
    {
        int li = 2 * a + 1;
        try
        {
            if (li >= size)
            {
                throw "OUT_OF_BOUND";
            }
            P[li] = element;
        }
        catch (const char *exception)
        {
            cout << "\n-----------------------------------------------------\n";
            cout << "EXCEPTION : " << exception << '\n';
            cout << "\n-----------------------------------------------------\n";
        }
    }
    else if (P[0] != 0 && x == 'r' || P[0] != 0 && x == 'R')
    {
        // index = Search(ele);
        int ri = 2 * a + 2;
        try
        {
            if (ri >= size)
            {
                throw "OUT_OF_BOUND";
            }
            P[ri] = element;
        }
        catch (const char *exception)
        {
            cout << "EXCEPTION : " << exception << '\n';
        }
    }
}

int BinaryTree_sequential::Search(int b)
{
    int i = 0;
    while (i < size)
    {
        if (P[i] == b)
        {
            return i;
        }
        i++;
    }
    cout << "ELEMENT NOT FOUND\n";
    return -1;
}

int BinaryTree_sequential::Delete(int index)
{
    int lastnode = P[0];
    for (int i = 1; i < size; i++)
    {
        if (P[i] != 0)
        {
            lastnode = P[i];
        }
    }
    if (P[index] == 0)
    {
        cout << "ELEMENT NOT FOUND!!" << endl;
    }
    else
    {
       P[index] = lastnode;
    }
}

void BinaryTree_sequential::Display()
{
    int h = 5; // by changing value of h we can set the tree printing to greater heights
    for (int i = 0; i < height + 1; i++)
    {
        int n = (int)pow(2, h);
        for (int j = (int)pow(2, i) - 1; j < (int)pow(2, i + 1) - 1; j++)
        {
            cout << setw(n) << P[j] << setw(n) << " ";
        }
        h--;
        cout << "\n\n";
    }
}

void BinaryTree_sequential::preorder(int index)
{
    if (P[index] != 0 && index < size)
    {
        cout << P[index] << " ";
        preorder(2 * index + 1);
        preorder(2 * index + 2);
    }
}

void BinaryTree_sequential::inorder(int index)
{
    if (P[index] != 0 && index < size)
    {
        inorder(2 * index + 1);
        cout << P[index] << " ";
        inorder(2 * index + 2);
    }
}

void BinaryTree_sequential::postorder(int index)
{
    if (P[index] != 0 && index < size)
    {
        postorder(2 * index + 1);
        postorder(2 * index + 2);
        cout << P[index] << " ";
    }
}

int main()
{
    system("clear");
    int height = 0;
    int element;
    char side;
    int parent;
    int index = 0;
    int ch;

    cout << "\nENTER THE HIEGHT OF THE BINARY TREE :\t ";
    cin >> height;

    BinaryTree_sequential t1(height);
    cout << "ENTER THE ROOT ELEMENT :\t ";
    cin >> element;
    t1.Create(0, ' ', element);

    while (1)
    {   cout<<"<====================================================================================>\n";
        cout<<"\t\t\t\t\tMENU\n";
        cout << "1.INSERT\t\t 2.DELETE\t\t  3.SEARCH\t\t 4.DISPLAY\n5.PREORDER\t\t 6.INORDER\t \t  7.POSTORDER\t\t 8.EXIT" << endl;
        cout << "ENTER THE NUMBER OF YOUR CHOICE :\n";
        cin >> ch;
        switch (ch)
        {
        case 1:
            do
            {
                cout << "________________________________________________________________________________\n";
                cout << "________________________________________________________________________________\n";

                cout << "ENTER THE PARENT OF THE ELEMENT YOU WANT TO INSERT : ";
                cin >> parent;
                index = t1.Search(parent);
                if (index == -1)
                    cout << "ENTER THE VALID PARENT \n";
            } while (index == -1);
            cout << "ENTER EITHER 'L' fOR LEFT OR 'R' FOR RIGHT TO SELECT THE SIDE OF THE PARENT NODE : ";
            cin >> side;
            cout << "ENTER THE NUMBER YOU WANT TO INSERT :\t";
            cin >> element;
            t1.Create(index, side, element);
            cout << "________________________________________________________________________________\n";
            cout << "________________________________________________________________________________\n";

            break;
        case 2:
            do
            {
            cout << "________________________________________________________________________________\n";
            cout << "________________________________________________________________________________\n";

                cout << "ENTER THE NUMBER YOU WANT TO DELETE :\t";
                cin >> element;
                index = t1.Search(element);
                if (index == -1)
                    cout << "ENTER THE VALID INPUT \n";
            } while (index == -1);
            t1.Delete(index);
            cout << "________________________________________________________________________________\n";
            cout << "________________________________________________________________________________\n";

            break;
        case 3:
            cout << "________________________________________________________________________________\n";
            cout << "________________________________________________________________________________\n";

            cout << "ENTER THE NUMBER YOU WANT TO SEARCH :\t";
            cin >> element;
            index = t1.Search(element);
            if (index != -1)
                cout << "ELEMENT AT INDEX : " << index << endl;
            cout << "________________________________________________________________________________\n";
            cout << "________________________________________________________________________________\n";

            break;
        case 4:
             cout << "________________________________________________________________________________\n";
            cout << "________________________________________________________________________________\n";

            cout<<"BINARY TREE DISPLAYED!!!\n";
            t1.Display();
            cout << "________________________________________________________________________________\n";
            cout << "________________________________________________________________________________\n";

            break;
        case 5:
             cout << "________________________________________________________________________________\n";
            cout << "________________________________________________________________________________\n";

            cout << "PREORDER :\t";
            t1.preorder(0);
             cout << "\n________________________________________________________________________________\n";
            cout << "________________________________________________________________________________\n";
            break;
        case 6:
             cout << "\n________________________________________________________________________________\n";
            cout << "________________________________________________________________________________\n";
            cout << "INORDER :\t";
            t1.inorder(0);
             cout << "\n________________________________________________________________________________\n";
            cout << "________________________________________________________________________________\n";
            break;
        case 7:
             cout << "________________________________________________________________________________\n";
            cout << "________________________________________________________________________________\n";
            cout << "POSTORDER :\t ";
            t1.postorder(0);
             cout << "\n________________________________________________________________________________\n";
            cout << "________________________________________________________________________________\n";
            break;
        case 8:
            exit(0);
            break;

        default:
            cout << "INVALID CHOICE" << endl;
            break;
        }
    }
    return 0;
}