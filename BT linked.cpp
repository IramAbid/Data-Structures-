/******************************************************************************
Name - Iram Abid,
Faculty roll no. - 20COB051
Enrolment no. -GJ8239
Serial no- 06
               
                                BINARY TREE
*******************************************************************************/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class linkedlistBST
{
	public :
        int data;
        linkedlistBST*left, *right;
        linkedlistBST *root, *p;
        linkedlistBST()
        {
            root = NULL;NULL;
            p = NULL;
            left = NULL;
            right = NULL;
        }
        void create(char X);
        void display(linkedlistBST *n);
        void search(linkedlistBST *p,int V);
};
void linkedlistBST::create (char X)
{
    int n;
    cout << "Enter the root element : ";
    cin >> n;
    if(root == NULL)
    {
        root = new linkedlistBST;
        root->data = n;
        root->left = NULL;
        root->right = NULL;
        cout << "first node added." << endl;
    }
    else
    {
        cout << "Enter the element : ";
        p = root;
        while(true)
        {
            if(X == 1 && p->left == NULL)
            {
                p->left = new linkedlistBST;
                p = p->left;
                p->data = n;
                p->left = NULL;
                p->right = NULL;
                cout << "Node added." << endl;
                break;
            }
            if(p->left != NULL && X == 1)
                p = p->left;
            if(X == 2 && p->right == NULL)
            {
                p->right = new linkedlistBST;
                p = p->right;
                p->data = n;
                p->left = NULL;
                p->right = NULL;
                cout<<"Node added."<< endl;
                break;
            }
            if(p->right != NULL && X == 2)
               p = p->right;
        }
    }
}
void linkedlistBST::display(linkedlistBST *n)
{
    if(n != NULL)
    {
        cout << n->data << "   ";
        display(n->left);
        display(n->right);
    }
}
void linkedlistBST::search(linkedlistBST *p,int V)
{
    if(p != NULL)
    {
        if(V == p->data)
        {
            cout << "Element is found." << endl;
        }
        else
        {
            search(p->left,V);
            search(p->right,V);
        }
    }
}

linkedlistBST li;  
void menu(int ch){
    int s,ele;
    switch(ch){
	    
    case 1:
	{
		cout << "Enter 1 for adding on left or 2 for adding on right : ";
		cin >> s;
		li.create(s);
        cout<<endl;
        cout<<"--------------------------------------------------------------\n";
		
	}
	cout<<endl;
	cout << "1.Insert\n2.Diplay\n3.Search\n4.Exit\n";
	cin >> ch;
	menu(ch);
	break;
	case 2:
    
	cout << "Displayig Binary tree elements" << endl;
	li.display(li.root);
	

    cout<<endl;
    cout<<"--------------------------------------------------------------\n";
    cout << "1.Insert\n2.Diplay\n3.Search\n4.Exit\n";
	cin >> ch;
	menu(ch);
    break;
    case 3:
	cout << "\nEnter the element you want to searched : ";
	cin >> ele;
	li.search(li.root,ele);
	cout<<"--------------------------------------------------------------\n";
	cout << "1.Insert\n2.Diplay\n3.Search\n4.Exit\n";
	cin >> ch;
	menu(ch);
	break;
	case 4:
            exit(0);
            break;

    default:
            cout << "INVALID CHOICE" << endl;
            break;
}
}
int main()
{
	
	int ch;
	cout << "\n\nlinked list representation of the binary tree " << endl;
	cout<<"--------------------------------------------------------------\n";

	li.create(0);
	cout << "1.Insert\n2.Diplay\n3.Search\n4.Exit\n";
	cin >> ch;
	menu(ch);
}
