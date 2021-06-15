#include "sort.h"

/**
 * apply_counting_sort - Apply counting sort algorithm based on num's digits
 * @array: Attay of integeres
 * @size: Array's size
 * @arr_copy: Array t keep a copy of 'array'
 * @counting_arr: Array to handle the corresponding number indexes using count
 * @power10: Integer that indicates which digit we want to select as key
*/
void apply_counting_sort(int *array, size_t size, int *arr_copy,
	int *counting_arr, int power10)
{
	size_t i;
	int rev_i;
	int digit_index, num_index;

	for (i = 0; i < 10; i++)
		counting_arr[i] = 0;

	for (i = 0; i < size; i++)
		arr_copy[i] = array[i];

	for (i = 0; i < size; i++)
	{
		digit_index = (array[i] / power10) % 10;
		counting_arr[digit_index] += 1;
	}

	for (i = 1; i < 10; i++)
		counting_arr[i] += counting_arr[i - 1];

	for (rev_i = size - 1; rev_i >= 0; rev_i--)
	{
		digit_index = (arr_copy[rev_i] / power10) % 10;
		num_index = --counting_arr[digit_index];
		array[num_index] = arr_copy[rev_i];
	}
}

/**
 * radix_sort - Sorts an array using LSD radiz sort
 * @array: Array of integers
 * @size: Size of the array
*/
void radix_sort(int *array, size_t size)
{
	size_t i;
	int *counting_arr, *arr_copy, max_num = 0;
	int power10 = 1;

	if (array == NULL || size <= 1)
		return;

	for (i = 0; i < size; i++)
		if (array[i] > max_num)
			max_num = array[i];

	counting_arr = malloc(sizeof(*counting_arr) * 10);
	if (counting_arr == NULL)
		return;

	arr_copy = malloc(sizeof(*arr_copy) * size);
	if (arr_copy == NULL)
	{
		free(counting_arr);
		return;
	}

	for (power10 = 1; max_num / power10 > 0; power10 *= 10)
	{
		apply_counting_sort(array, size, arr_copy, counting_arr, power10);
		print_array(array, size);
	}

	free(counting_arr);
	free(arr_copy);
}
