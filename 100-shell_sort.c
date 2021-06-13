#include "sort.h"

/**
 * shell_sort - Sorts an array using shell sort algorithm with knuth's sequence
 * @array: Array of integers
 * @size: Array's size
*/
void shell_sort(int *array, size_t size)
{
	size_t gap = 1, i, j;
	int curr;

	if (array == NULL || size == 0)
		return;

	while (gap < size)
		gap = (gap * 3) + 1;

	for (gap = (gap - 1) / 3; gap > 0; gap = (gap - 1) / 3)
	{
		for (i = gap; i < size; i++)
		{
			curr = array[i];
			for (j = i; j >= gap && array[j - gap] > curr; j -= gap)
				swap(array, j, j - gap);
		}
		print_array(array, size);
	}
}
