/******************************************************************************
Name - Iram Abid,
Faculty roll no. - 20COB051
Enrolment no. -GJ8239
Serial no- 06
                        Unordered Priority Queue
*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Queue
{
    int size;
    int front;
    int rear;
    int *data;
};

void create(struct Queue *q, int size)
{
    q->size = size;
    q->front = q->rear = -1;
    q->data = (int *)malloc(q->size * sizeof(int));
}

void enqueue(struct Queue *q, int data)
{
    if (q->rear == q->size - 1)
    {
        printf("Queue is full\n");
    }
    else
    {
        q->rear++;
        q->data[q->rear] = data;
    }
}

void Display(struct Queue q)
{
    int i;
    for (i = q.front + 1; i <= q.rear; i++)
    {
        if (i != q.rear)
            printf("[%d] --> ", q.data[i]);
        else
            printf("[%d]", q.data[i]);
    }
    printf("\n");
}

char dequeue(struct Queue *q)
{
    int x;
    int prn;
    int prnIndex = q->front + 1;
    if (q->front == q->rear)
    {
        printf("Queue is Empty\n");
    }
    else
    {
        prn = q->data[q->front + 1];
        for (int i = q->front + 1; i <= q->rear; i++)
        {
            if (prn > q->data[i])
            {
                prn = q->data[i];
                prnIndex = i;
            }
        }
        x = prn;
        for (int i = prnIndex + 1; i <= q->rear;)
        {
            q->data[prnIndex++] = q->data[i++];
        }
        q->rear--;
    }
    return x;
}

char randomNumGenerator()
{
    int data;
    data =  rand() % 100; // random capital alphabet is generated
    return data;
}

int main()
{
    struct Queue q;
    int data;
    int A[10];
    create(&q, 10);
    srand(time(0));
    for (int i = 0; i < 10; i++)
    {
        data= randomNumGenerator();
        enqueue(&q, data);
    }
    
    printf("\n<======================Elements enqueued in queue in order=======================>\n\n");
    Display(q);
    printf("\n\n\n");
    printf("<=====Elements dequeued from queue in order of decresing order of ASCII code=====>\n\n");
    for (int i = 0; i <= 9; i++)
    {
        A[i] = dequeue(&q);

            printf("[%d] <-- ", A[i]);
       
    }
    printf("\n\n\n");
    free(q.data);
    return 0;
}