/******************************************************************************
Name - Iram Abid,
Faculty roll no. - 20COB051
Enrolment no. -GJ8239
Serial no- 06
                 Program to perform different operations in linked list
                      (Insert,delete,find,length,isempty,display)
*******************************************************************************/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

struct Node
{
    int data;
    struct Node *NEXT;
}*first=NULL;               

/*Generating linked list*/

void Generate_LinkedList(int array[], int n)
{
    int i;
    struct Node *temp, *last;
    first = (struct Node *)malloc(sizeof(struct Node));
    first->data = array[0];
    first->NEXT = NULL;
    last=first;
    for(i=1;i<n;i++)
    {
        temp=(struct Node*)malloc(sizeof(struct Node));
        temp->data=array[i];
        temp->NEXT=NULL;
        last->NEXT=temp;
        last=temp;
    }
}

/*Calculating length of the Linked List*/
int Length(struct Node *p)
{
    int count = 0;
    while(p != NULL)
    {
        count++;
        p = p->NEXT;
    }
    return count;
}

/*Checking whether the Linked List is empty or not*/
int isempty(struct Node *p)
{
    int count = 0;
    while(p != NULL)
    {
        count++;
        p = p->NEXT;
    }
    if(count == 0)
        return 1;
    else
        return 0;
}

/*Finding the element in the Linked List*/
int Find(struct Node *p, int key)
{
    int count = 0;
    while(p != NULL)
    {
        count++;
        if(p->data == key)
        {
            return count-1;
            break;
        }
        p = p->NEXT;
    }
    return 0;
}

/*func for Inserting element in the Linked List*/
int Insert(struct Node *p, int loc, int key)
{
    struct Node *temp;
    temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = key;
    int i;
    if(loc<0 || loc>Length(p))
        return -1;
    else if(loc == 0)
    {
        temp->NEXT = first;
        first = temp;
    }
    else
    {
        for(i=0; i<loc-1; i++)
            p = p->NEXT;
        temp->NEXT = p->NEXT;
        p->NEXT = temp;
    }
}

/* Deletimg an element from the Linked List*/
int Delete(struct Node*p, int loc)
{
    int i, x=0;
    struct Node *temp;
    if(loc==1)
    {
        temp=first;
        x=first->data;
        first=first->NEXT;
        free(temp);
        return x;
     }
     else
     {
        for(i=0;i<loc;i++)
        {
            temp=p;
            p=p->NEXT;
        }
        temp->NEXT=p->NEXT;
        x=p->data;
        free(p);
        return x;
     }
}

/* displaying the Linked List*/
void display(struct Node *p)
{
    while(p!=NULL)
    {
        printf("%d\t",p->data);
        p = p->NEXT;
    }
}
 void Operations(){
     int choice,x,m,k,more;
         //Creating a list type info for functions of linked list
    printf("\nSelect the number of operation you want to perform.");
    printf("\n1 for Insert(k,x), insert a new element x just after the k th element.");
    printf("\n2 for Delete(k,x), delete the kth element and return it in x.");
    printf("\n3 for Display(), to print the complete linked list.");
    printf("\n4 for find(x), return the position of x in the linked list, return 0 if x is not found.");
    printf("\n5 for Isempty(), return true if the list is empty, false otherwise.");
    printf("\n6 for Length(), return the number of elements in the linked list.");

    printf("\n\nEnter your choice:");
    scanf("%d",&choice);

    if(choice == 1)
    {
        int num, location;
        printf("\nEnter the number you want to insert:");
        scanf("%d",&num);
        printf("\nEnter the location at which you want to insert:");
        scanf("%d",&location);
        Insert(first, location, num);  //Calling Insert function
        printf("\nLinked-list after inserting element: \t");
        display(first); //Calling display function
    }
    else if(choice == 2)
    {
        int location;
        printf("\nEnter the location from where you want to delete an element:");
        scanf("%d",&location);
        printf("\nThe deleted element is:%d\n\n",Delete(first,location));  //Calling Delete function
        printf("\nLinked-list after inserting element: \t");
        display(first); //Calling display function
    }
    else if(choice==3)
    {
        printf("Linked-list of the provided elements is: \t");
        display(first); //Calling display function
    }
    else if(choice == 4)
    {
        printf("\n\nEnter the number you want to search in the linked list:");
        scanf("%d",&x);
        m = Find(first, x); //Calling Search function
        if(m==0)
            printf("\n\nElement %d not found in the linked list.",x);
        else
            printf("\n\nElement %d found at the location %d in the linked list.\n\n", x, m);
    }
    else if(choice == 5)
    {
        k = isempty(first);//Calling Isempty function
        if(k==0)
            printf("\n\nGenerated Linked list is not empty.");
        else
            printf("\n\nGenerated Linked list is empty");
    }
    else if(choice == 6)
    {
        //Calling Length function to calculate length of Linked List
        printf("\n\nLength of the created linked list is:%d",Length(first));
    }
    printf("\nWant to perform more operations?\nType 1 for YES and 0 for NO.\n");
    scanf("%d",&more);
    if(more==1){
        Operations();
    }

 }

int main()
{
    int n, i;
    printf("Enter the size of the Linked List:\t");
    scanf("%d",&n);
    int array[n],more;
    srand(time(0));
    for(i=0;i<n;i++)
        array[i] = rand()%100;  //Generating elements randomly
    Generate_LinkedList(array, n); //Calling generating function to generate a Linked List
    printf("\nThe linked list generated :\t");
    display(first);  //Calling Display function
    printf("\n");
    Operations();
    return 0;
}
