#include <stdlib.h>
#include <stdio.h>

/**
 * merge_sort - sorts an array of integers in ascending order
 * using the Merge Sort algorithm
 *
 * @array: the array to be sorted
 * @size: number of elements in the array
 */
void merge_sort(int *array, size_t size)
{
    int *temp;
    size_t i;

    temp = malloc(sizeof(int) * size);
    if (!temp)
        return;

    for (i = 1; i < size; i *= 2)
    {
        size_t j, k;
        for (j = 0; j < size - i; j += i * 2)
        {
            size_t left, right;
            left = j;
            right = j + i;
            for (k = j; k < j + 2 * i && k < size; ++k)
            {
                if (right >= size || (left < j + i && array[left] < array[right]))
                    temp[k] = array[left++];
                else
                    temp[k] = array[right++];
            }
        }
        for (j = 0; j < size; ++j)
            array[j] = temp[j];
    }

    free(temp);
}
