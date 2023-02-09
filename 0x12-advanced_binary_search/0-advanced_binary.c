#include "search_algos.h"

/**
 * print_array - Prints an array of integers
 * 
 * @array: the array to be printed
 * @left: the left index of the subarray to be printed
 * @right: the right index of the subarray to be printed
*/

void print_array(int *array, int left, int right) 
{
	printf("Searching in array: ");
	for(int i = left; i <= right; i++)
		printf(" %d%c", array[i], i == right ? '\n' : ',');
}

/**
 * advanced_binary - Searches for a value in a sorted array of integers
 *
 * @array: A pointer to the first element of the array to search in
 * @size: The number of elements in array
 * @value: The value to search for
 *
 * Return: The index of the value, or -1 if the value is not present in array
 */

int advanced_binary(int *array, size_t size, int value)
{
    int left = 0, right = size - 1;
    int mid;

    while (left <= right)
    {
        print_array(array, left, right);
        mid = (left + right) / 2;
        if (array[mid] == value)
            return (mid);
        if (array[mid] < value)
            left = mid + 1;
        else
            right = mid - 1;
    }

    return (-1);
}