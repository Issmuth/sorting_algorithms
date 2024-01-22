#include "sort.h"


/**
 * swap_int - swaps two integers
 * @a: ...
 * @b: ...
 */

void swap_int(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * selection_sort - sorts an array of integers based
 * on the selection sort algorithm
 *
 * @array: array to be sorted
 * @size: size of the arary
 */


void selection_sort(int *array, size_t size)
{
	size_t i, j, min;

	if (!array || size < 2)
		return;

	for (i = 0; i < size; i++)
	{
		min = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min])
			{
				min = j;
			}
		}
		if (min == i)
			continue;

		swap_int(&(array[i]), &(array[min]));
		print_array(array, size);
	}
}
