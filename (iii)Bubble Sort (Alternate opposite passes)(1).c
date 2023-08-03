/******************************************************************************
Name – Iram Abid,
Faculty roll no. - 20COB051
Enrolment no. -GJ8239
Serial no- 06
      Question-a)(iii)Bubble Sort (Alternate opposite passes) 
*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
    int index, j, n, k = 1, l = 0, index_2, temporary, swaps = 0, count = 0;

    printf("\nEnter the size of the array: ");
    scanf("%d", &n);

    int a[n];

    srand(time(0));

    for (index = 0; index < n; index++)
    {
        a[index] = rand() % 100;
    }
    for (index = 0; index < n; index++)
    {
        printf("%d\t", a[index]);
    }
    printf("\n");
    for (index = 0; index < n - 1; index++)
    {
        if (index % 2 == 0)
        {
            for (j = 0; j < n - index + l; j++)
            {

                if (a[j] > a[j + 1])
                {
                    temporary = a[j];
                    a[j] = a[j + 1];
                    a[j + 1] = temporary;
                    swaps++;
                }
                count++;
            }
            l++;
            if (swaps == 0)
            {
                break;
            }
            swaps = 0;

            printf("\n");
            printf("Intermediate output %d\t\t", index + 1);
            for (index_2 = 0; index_2 < n; index_2++)
            {
                printf("%d  ", a[index_2]);
            }
            printf("\nNo of Comparisons made= %d\n", count);
            index_2 = 0;
            count = 0;
        }
        else
        {
            for (j = n - 1; j >= k; j--) // alternate
            {

                if (a[j] < a[j - 1])
                {
                    temporary = a[j];
                    a[j] = a[j - 1];
                    a[j - 1] = temporary;
                    swaps++;
                }
                count++;
            }
            k++;
            if (swaps == 0)
            {
                break;
            }
            swaps = 0;

            printf("\n");
            printf("Intermediate output %d\t\t", index + 1);
            for (index_2 = 0; index_2 < n; index_2++)
            {
                printf("%d  ", a[index_2]);
            }
            printf("\nNo. of Comparisons made = %d\n", count);
            index_2 = 0;
            count = 0;
        }
    }

    printf("\nFINAL SORTED ARRAY:\n");
    for (index = 0; index < n; index++)
    {
        printf("%d  ", a[index]);
    }

    return 0;
}
