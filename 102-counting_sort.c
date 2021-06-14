#include "sort.h"

int *setup_counting_array(int *array, size_t size, int max_num);

/**
 * counting_sort - Sorts an array using counting sort algorithm
 *								assumed that all numbers are positive
 * @array: Array of integers
 * @size: Array's size
*/
void counting_sort(int *array, size_t size)
{
	size_t i;
	int *counting_arr, *arr_copy, max_num = 0, num, arr_pos;

	if (array == NULL || size <= 1)
		return;

	for (i = 0; i < size; i++)
		if (array[i] > max_num)
			max_num = array[i];

	counting_arr = setup_counting_array(array, size, max_num);
	if (counting_arr == NULL)
		return;

	/* Print the counting array */
	print_array(counting_arr, max_num + 1);

	/* Create a copy of the array */
	arr_copy = malloc(sizeof(*array) * size);
	if (arr_copy == NULL)
	{
		free(counting_arr);
		return;
	}

	/* Copy array values */
	for (i = 0; i < size; i++)
		arr_copy[i] = array[i];

	/* Iterate over the copy of the array to sort the elements */
	for (i = 0; i < size; i++)
	{
		num = arr_copy[i];
		arr_pos = --counting_arr[num];
		array[arr_pos] = num;
	}

	free(arr_copy);
	free(counting_arr);
}

/**
 * setup_counting_array - Creates an array to count the repeated values
 * @array: Array of integers from which to count the repeated values
 * @size: Size of 'array'
 * @max_num: Maximun number found on 'array'
 *
 * Return: Pointer to an array of integers
*/
int *setup_counting_array(int *array, size_t size, int max_num)
{
	size_t i;
	int *counting_arr;

	/* Create counting array with 'max_num'(included) size*/
	counting_arr = malloc(sizeof(*array) * (max_num + 1));
	if (counting_arr == NULL)
		return (NULL);

	/* Initialiize array values to '0' */
	for (i = 0; (int)i <= max_num; i++)
		counting_arr[i] = 0;

	/* Iterate over the array to be sorted */
	for (i = 0; i < size; i++)
		counting_arr[array[i]] += 1;

	/* Sum up all values */
	for (i = 1; (int)i <= max_num; i++)
		counting_arr[i] += counting_arr[i - 1];

	return (counting_arr);
}
