/******************************************************************************
Name - Iram Abid,
Faculty roll no. - 20COB051
Enrolment no. -GJ8239
Serial no- 06
                       Ordered Priority Queue
*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
int size;


// function to delete
void Delete_fromQueue(int pq[size][5],int front[size],int rear[size])
{
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < 5; j++)
            {
                if (pq[i][j] != 'a'){
                    pq[i][j]='a';
                    printf("ELEMENT IS DELETED!\n");
                    return;
                }
            }
        }
        printf("NO ELEMENT IN THE QUEUE!\n");
}
//function to  insert
void Insert_inQueue(int pq[size][5],int front[size],int rear[size])
{
    printf("<============ENTER THE ELEMENT YOU WANT TO INSERT===========>\n");
    int temp;
    scanf("%d", &temp);
    printf("<========ENTER THE PRIORITY OF THE NUMBER========>\n");
    int p;
    scanf("%d", &p);
    if (rear[p] == 4)
    {
        printf("Overflow!\n");
    }
    else
    {
        if (rear[p] == -1)
        {
            front[p] = 0;
            rear[p] = 0;
        }
        else
        {
            rear[p]++;
        }
        pq[p][rear[p]] = temp;
      printf("ELEMENT IS INSERTED");  
    }
}
// function to display
void print(int pq[size][5],int front[size],int rear[size])
{
    printf("<======================PRIORITY QUEUE==================>\n");
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (pq[i][j] == 'a')
               printf(" ");
            else
                printf("%d\n", pq[i][j]);
        }
       
    }
    printf("\n");
}

int main()
{
    printf("ENTER THE SIZE OF THE PRIORITY\t");
    scanf("%d",&size);
    int pq[size][5];
    int front[size];
    int rear[size];
    for(int i=0;i<size;i++){
        front[i]=-1;
        rear[i]=-1;
        for(int j=0;j<5;j++)
        {
            pq[i][j]='a';
        }
    }

    label:;
    int choice;
    printf("\n1 - INSERT AN ELEMENT TO THE QUEUE");
    printf("\n2 - DELETE AN ELEMENT FROM THE QUEUE");
    printf("\n3 - DISPLAY THE QUEUE");
    printf("\n4 - EXIT\n");
    printf("ENTER YOUR CHOICE NUMBER\t");
    scanf(" %d", &choice);
    printf("\n");
    if (choice == 1)
        Insert_inQueue(pq,front,rear);
    else if (choice == 2)
        Delete_fromQueue(pq,front,rear);
    else if (choice == 3)
        print(pq,front,rear);
    else
        exit(0);
    goto label;
}