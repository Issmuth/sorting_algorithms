#include "sort.h"

/**
 * shell_sort - sorts an array of integers using shell sorting algorithm
 * with knuth sequence.
 * @array: array to be sorted
 * @size: size of array
 */
void shell_sort(int *array, size_t size)
{
	int i, j, space;
	int n = (int)size, kmax, temp;

	if (!array || size < 2)
		return;

	n = (int)size;
	for (space = 1; space < n; space = (space * 3) + 1)
		kmax = space;

	for (space = kmax; space > 0; space = (space - 1) / 3)
	{
		i = space;
		while (i < n)
		{
			temp = array[i];
			for (j = i; j >= space && array[j - space] > temp; j -= space)
			{
				array[j] = array[j - space];
			}
			array[j] = temp;
			i++;
		}
		print_array(array, size);
	}
}
