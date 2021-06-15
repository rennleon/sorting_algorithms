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
 * bmerge - Merges a sub array using a half size step each time its called
 * @array: Main array of integers
 * @start_ind: Index at which the subarray starts
 * @size: Subarray's size
 * @direction: Integer that indicates the sorting order (Inc=1/Dec=0)
*/
void bmerge(int *array, int start_ind, int size, int direction)
{
	int i, step;

	if (size <= 1)
		return;

	step = size / 2;

	for (i = start_ind; i < start_ind + step; i++)
		if (direction == (array[i] > array[i + step]))
			swap(array, i, i + step);

	bmerge(array, start_ind, step, direction);
	bmerge(array, start_ind + step, step, direction);
}

/**
 * bsort - Divides an array into halves and then applies bmerge
 * @array: Main array of integers
 * @arr_size: Main array's size
 * @start_ind: Index at which the subarray starts
 * @size: Subarray's size
 * @direction: Integer that indicates the sorting order (Inc=1/Dec=0)
*/
void bsort(int *array, size_t arr_size, int start_ind, int size, int direction)
{
	int half_size;
	char *dir = "UP";

	if (size <= 1)
		return;

	if (direction == 0)
		dir = "DOWN";

	half_size = size / 2;

	printf("Merging [%d/%ld] (%s):\n", size, arr_size, dir);
	print_array(array + start_ind, size);

	bsort(array, arr_size, start_ind, half_size, 1);
	bsort(array, arr_size, start_ind + half_size, half_size, 0);
	bmerge(array, start_ind, size, direction);

	printf("Result [%d/%ld] (%s):\n", size, arr_size, dir);
	print_array(array + start_ind, size);
}

/**
 * bitonic_sort - Sorts an array using bitonic sort
 * @array: Array of integers
 * @size: Size of the array
*/
void bitonic_sort(int *array, size_t size)
{
	if (array == NULL || size <= 1)
		return;

	bsort(array, size, 0, size, 1);
}
