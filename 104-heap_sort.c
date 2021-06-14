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
 * build_down - Moves an element down to the heap until its right position
 * @array: Array of integers
 * @size: Array's size
 * @p_ind: Index from which to start building down
 * @last_ind: Last heap's valid index
*/
void build_down(int *array, size_t size, int p_ind, int last_ind)
{
	int l_ind, r_ind, ind_max;

	l_ind = (p_ind * 2) + 1;
	r_ind = (p_ind * 2) + 2;

	while (l_ind <= last_ind)
	{
		ind_max = l_ind;
		if (r_ind <= last_ind && array[r_ind] > array[l_ind])
			ind_max = r_ind;

		if (array[p_ind] >= array[ind_max])
			break;

		swap(array, p_ind, ind_max);
		print_array(array, size);

		p_ind = ind_max;
		l_ind = (p_ind * 2) + 1;
		r_ind = (p_ind * 2) + 2;
	}
}

/**
 * heapify_max - Creates a max heap with the values of array
 * @array: Array of integers
 * @size: Size of the array
*/
void heapify_max(int *array, size_t size)
{
	int p_ind;
	int last_ind = size - 1;

	for (p_ind = (last_ind - 1) / 2; p_ind >= 0; p_ind--)
		build_down(array, size, p_ind, last_ind);
}

/**
 * heap_sort - Sorts an array using heap sort algorithm
 * @array: Array of integers
 * @size: Array's size
*/
void heap_sort(int *array, size_t size)
{
	int last_index;

	if (array == NULL || size <= 1)
		return;

	heapify_max(array, size);

	for (last_index = size - 1; last_index > 0; last_index--)
	{
		swap(array, 0, last_index);
		print_array(array, size);
		build_down(array, size, 0, last_index - 1);
	}
}
