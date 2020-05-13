#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int cmpfunc(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}
int main()
{
    int arr[7] = {0};
    printf("Enter 7 elements:\n");
    int i = 0;
    while (i<7)    
    {
        int num;
        scanf("%d", &num);
        int flag = 0;
        // search for num
        for(int j=0; j<7; j++)
        {
            if(arr[j] == num)
            {
                printf("It is a duplicate element, please enter a different element\n");
                flag = 1;
                break;
            }
        }
        if(flag == 0)
        {
            arr[i] = num;
            i++;
        }
    }
    // print the array
    for(int i=0; i<7; i++)
    {
        printf("%d ", arr[i]);
    }

    // now sort

    for(int i=0; i<6; i++)
    {
        int min = i;
        for (int j = i + 1; j < 7; j++)
        {
            if(arr[j] < min)
                min = j;
        }

        int temp = min;
        arr[i] = arr[min];
        arr[min] = arr[i];
    }

    // print the median
    printf("Median = %d", arr[3]);
}