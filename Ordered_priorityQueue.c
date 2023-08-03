/******************************************************************************
Name - Iram Abid,
Faculty roll no. - 20COB051
Enrolment no. -GJ8239
Serial no- 06
                       Ordered Priority Queue
*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Node
{
    char ch;
    int prn;
    struct Node *next;
};

struct queue
{
    struct Node *front;
    struct Node *rear;
};

void enqueue(struct queue *q, char ch, int prn)
{
    struct Node *temp;
    temp = (struct Node *)malloc(sizeof(struct Node));
    if (temp == NULL)
    {
        printf("Queue is FULL(since no memory is allocated by compiler)\n");
        return;
    }
    else
    {
        temp->ch = ch;
        temp->prn = prn;
        temp->next = NULL;
        if (q->front == NULL)
        {
            q->front = q->rear = temp;
        }
        else if (q->front != NULL && prn < q->front->prn)
        {
            temp->next = q->front;
            q->front = temp;
        }
        else if (q->front != NULL && prn >= q->front->prn)
        {
            struct Node *t, *tailing;
            tailing = q->front;
            t = tailing;
            tailing = tailing->next;
            while (tailing != NULL)
            {
                int t1 = t->prn;
                int t2 = tailing->prn;
                if (prn >= t->prn && prn < tailing->prn)
                {
                    t->next = temp;
                    temp->next = tailing;
                    t = t->next;
                }
                tailing = tailing->next;
                t = t->next;
            }
            q->rear = t;
            if (prn >= q->rear->prn)
            {
                q->rear->next = temp;
                q->rear = temp;
            }
        }
    }
}

char dequeue(struct queue *q)
{
    char x;
    struct Node *t;
    if (q->front == NULL)
        printf("Queue is empty\n");
    else
    {
        x = q->front->ch;
        t = q->front;
        q->front = q->front->next;
        free(t);
    }
    return x;
}

void displayQueue(struct queue q)
{
    struct Node *t;
    t = q.front;
    while (t != NULL)
    {
        if (t->next != NULL)
            printf("[%c]-->", t->ch);
        else
            printf("[%c]", t->ch);
        t = t->next;
    }
    printf("\n");
}

char randomCharGenerator()
{
    char ch;
    ch = 65 + rand() % 26; // random capital alphabet is generated
    return ch;
}

int prnCreator(char ch)
{
    return ch; // priority numer is generated based on ASCII value of charecter
}

int main()
{
    char ch;
    int prn;
    char A[10];
    struct queue q;
    q.front = NULL;
    q.rear = NULL;
    srand(time(0));
   
    printf("\n\n\n<=======================Elements randomly generated in order====================>\n\n");
    for (int i = 0; i < 10; i++) // enqueuing 10 randomly generated values in a queue
    {
        ch = randomCharGenerator();
        prn = prnCreator(ch);
        enqueue(&q, ch, prn);
        if (i != 9)
            printf("%c, ", ch);
        else
            printf("%c ", ch);
    }
    printf("\n\n\n");
    printf("\n<============Elements Enqueued in queue based on priority of ASCII code==========>\n\n");
    displayQueue(q);
  
    printf("\n\n\n<========Elements Dequeued from queue in decresing order of priority number======>\n\n");
    for (int i = 0; i < 10; i++)
    {
        A[i] = dequeue(&q);
        if (i != 9)
            printf("%c, ", A[i]);
        else
            printf("%c ", A[i]);
    }
    
    return 0;
}