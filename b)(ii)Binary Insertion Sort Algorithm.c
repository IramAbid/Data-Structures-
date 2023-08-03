/******************************************************************************
Name – Iram Abid,
Faculty roll no. - 20COB051
Enrolment no. -GJ8239
Serial no- 06
      Question-b)(ii)Binary Insertion Sort Algorithm 
*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
    int i, j, n, temp, swap = 0, low, high, mid, number, position, m, k = 0, flag = 0, comparisons = 0;

    printf("\nEnter the size of the array: ");
    scanf("%d", &n);

    int a[n];

    srand(time(0));

    for (i = 0; i <n; i++)
    {
        a[i] = rand() % 100;
        printf("%d\t", a[i]);
    }
    printf("\n");

    for (i = 1; i <n; i++)
    {
        low = 0;
        high = i - 1;
        while (low <= high)
        {
            mid = (low + high) / 2;
            if (a[i] == a[mid])
            {
                flag = 1;
                comparisons++;
                break;
            }
            else if (a[i] < a[mid])
            {
                high = mid - 1;
                comparisons++;
            }
            else if (a[i] > a[mid])
            {
                low = mid + 1;
                comparisons++;
            }
        }
        if ((low > high && a[i] < a[low]) || flag == 1)
        {
            position = low;
            temp = a[i];
            j = i - 1;
            while (j >= position)
            {
                a[j + 1] = a[j];
                j--;
            }
            a[j + 1] = temp;
            k++;
            printf("\nIntermediate Output %d\t", k);
            for (m = 0; m < n; m++)
            {
                printf("%d\t", a[m]);
            }
            printf("searching the proper location of next element");
            printf("\n\nElements required to move after pass %d = %d\n", k, i - position);
            printf("Comparisons made in  after pass %d = %d\n", k, comparisons);
            comparisons = 0;
            m = 0;
        }
        else
        {
            k++;
            printf("\nIntermediate Output %d\t", k);
            for (m = 0; m <n; m++)
            {
                printf("%d\t", a[m]);
            }
            printf("searching the proper location of next element");
            printf("\n\nElements required to move after pass %d = %d\n", k, i - position);
            printf("Comparisons made in  after pass %d = %d\n", k, comparisons);        }
    }

    printf("\n\n FINAL SORTED ARRAY:\n\n");
    for (i = 0; i < n; i++)
    {
        printf("%d\t", a[i]);
    }
    printf("\n\n");
    return 0;
}