#include "sort.h"


void solve_quick(int *array, size_t size, long lower, long upper);

/**
 * quick_sort - Sorts an array using quick sort algorithm
 * @array: Array of integers
 * @size: Array's size
*/
void quick_sort(int *array, size_t size)
{
	size_t lower, upper, pivot_ind;

	if (array == NULL || size == 0)
		return;

	solve_quick(array, size, 0, size - 1);
}

/**
 * solve_quick - Sorts an array using quick sort
 * @array: Array of integers
 * @size: Array's size
 * @lower: Lower bound from wich the partitions starts
 * @upper: Upper bound on which the partition ends
*/
void solve_quick(int *array, size_t size, long lower, long upper)
{
	long i = lower - 1, j;
	int pivot = array[upper];

	if (lower >= upper)
		return;

	for (j = lower; j < upper; j++)
		if (array[j] < pivot)
		{
			if (++i == j)
				continue;

			swap(array, i, j);
			print_array(array, size);
		}

	if (++i != upper)
	{
		swap(array, i, upper);
		print_array(array, size);
	}

	solve_quick(array, size, lower, i - 1);
	solve_quick(array, size, i + 1, upper);
}
