#include "sort.h"

/**
 * swap - swaps to integers' address
 * @i: ...
 * @j: ...
 */

void swap(int *i, int *j)
{
	int temp;

	temp = *i;
	*i = *j;
	*j = temp;
}

/**
 * quick_sort - sorts an array of integers
 * using the quick sort algorithm under the
 * Lomuto partition scheme.
 *
 * @array: array to be sorted
 * @size: size of array
 */

void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	
