#include "sort.h"

/**
 * swap - Swaps two values inside an array
 * @arr: Array of integers
 * @i: Index 1
 * @j: Index 2
*/
void swap(int *arr, int i, int j)
{
	int aux = arr[i];

	arr[i] = arr[j];
	arr[j] = aux;
}

/**
 * partition - Divides an array into two parts and returns the partition index
 * @array: Array of integers
 * @size: Array's size
 * @lower: Sub-array's lower index
 * @upper: Sub-array's upper index
 *
 * Return: Last pivot position
*/
int partition(int *array, size_t size, int lower, int upper)
{
	int i = lower - 1, j;
	int pivot = array[upper];

	for (j = lower; j < upper; j++)
		if (array[j] <= pivot)
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

	return (i);
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
	int pivot_pos;

	if (lower >= upper)
		return;

	pivot_pos = partition(array, size, lower, upper);

	solve_quick(array, size, lower, pivot_pos - 1);
	solve_quick(array, size, pivot_pos + 1, upper);
}

/**
 * quick_sort - Sorts an array using quick sort algorithm
 * @array: Array of integers
 * @size: Array's size
*/
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size <= 1)
		return;

	solve_quick(array, size, 0, size - 1);
}
