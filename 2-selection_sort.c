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
 * selection_sort - Sorts an array using selection sort algorithm
 * @array: Array of integers
 * @size: Array's size
*/
void selection_sort(int *array, size_t size)
{
	size_t i, j, ind_min;

	if (array == NULL || size == 0)
		return;

	for (i = 0; i < size; i++)
	{
		ind_min = i;
		for (j = i + 1; j < size; j++)
			if (array[j] < array[ind_min])
				ind_min = j;

		if (ind_min != i)
		{
			swap(array, i, ind_min);
			print_array(array, size);
		}
	}
}
