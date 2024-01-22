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
 * segment - partitions the array based on the
 * pivot chosen using the lomuto scheme.
 *
 * @array: ...
 * @size: ...
 * @low: ...
 * @high: ...
 *
 * Return: segment index
 */

int segment(int *array, size_t  size, int low, int high)
{
	int i, j, *pivot = array + high;

	for (i = j = low; j < high; j++)
	{
		if (array[j] < *pivot)
		{
			if (i < j)
			{
				swap(&array[i], &array[j]);
				print_array(array, size);
			}
			i++;
		}
	}
	if (array[i] > *pivot)
	{
		swap(&array[i], pivot);
		print_array(array, size);
	}
	return (i);
}

/**
 * sort - calls the partition function recursively
 * and until right is less than left
 *
 * @array: array to be sorted
 * @size: size of array
 * @low: leftmost element in the partition
 * @high: rightmost element in the partition
 */

void sort(int *array, size_t size, int low, int high)
{
	int seg;

	if (low < high)
	{
		seg = segment(array, size, low, high);
		sort(array, size, low, (seg - 1));
		sort(array, size, (seg + 1), high);
	}
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

	sort(array, size, 0, (size - 1));
}
