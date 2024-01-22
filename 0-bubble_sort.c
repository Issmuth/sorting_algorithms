#include "sort.h"

/**
 * bubble_sort - bubble sort algorithm implementation
 * @array: array to sort
 * @size: size of the array
 */

void bubble_sort(int *array, size_t size)
{
	int temp;
	size_t i, j;

	if (!array || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		for (j = 0; j < (size - i - 1); j++)
		{
			if (array[j + 1] && (array[j] > array[j + 1]))
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
				print_array(array, size);
			}
		}
	}
}
