#include "sort.h"


void solve_merge(int *array, int *arr_buff,
	int lower, int upper);
void merge(int *array, int *arr_buff,
	int lo_left, int up_left, int lo_right, int up_right);

/**
 * merge_sort - Sorts an array using merge sort algorithm
 * @array: Array of integers
 * @size: Array's size
*/
void merge_sort(int *array, size_t size)
{
	int *arr_buff;

	if (array == NULL || size <= 1)
		return;

	arr_buff = malloc(sizeof(*arr_buff) * size);
	solve_merge(array, arr_buff, 0, size - 1);
	free(arr_buff);
}

/**
 * solve_merge - Sorts an array using quick sort
 * @array: Array of integers
 * @arr_buff: Array of integers used as buffer to merge the solutions
 * @lower: Lower bound from wich the partitions starts
 * @upper: Upper bound on which the partition ends
*/
void solve_merge(int *array, int *arr_buff,
	int lower, int upper)
{
	int middle, bounds_sum;

	if (lower >= upper)
		return;

	/* To ensure that left's size is always less than right's */
	bounds_sum = lower + upper;
	middle = bounds_sum / 2;
	if (bounds_sum % 2 == 0)
		middle -= 1;

	/* Call for left side */
	solve_merge(array, arr_buff, lower, middle);
	/* Call for right side */
	solve_merge(array, arr_buff, middle + 1, upper);
	/* Merge left and right */
	printf("Merging...\n");
	printf("[Left]: ");
	print_array(&array[lower], middle - lower + 1);
	printf("[Right]: ");
	print_array(&array[middle + 1], upper - middle);

	merge(array, arr_buff, lower, middle, middle + 1, upper);

	printf("[Done]: ");
	print_array(&array[lower], upper - lower + 1);
}

/**
 * merge - Merges two array's parts into the main one in order
 * @array: Main array of integers
 * @arr_buff: Array of integers used as buffer to merge the solutions
 * @lo_left: Lower bound for left part of the solution
 * @up_left: Upper bound for left part of the solution
 * @lo_right: Lower bound for right part of the solution
 * @up_right: Upper bound for right part of the solution
*/
void merge(int *array, int *arr_buff,
	int lo_left, int up_left, int lo_right, int up_right)
{
	int i;
	int ind_arr = lo_left;
	int ind_left = lo_left;
	int ind_right = lo_right;

	/* Copy left array values */
	for (i = lo_left; i <= up_left; i++)
		arr_buff[i] = array[i];
	/* Copy right array values */
	for (i = lo_right; i <= up_right; i++)
		arr_buff[i] = array[i];

	/* Fill array with ordered values */
	while (ind_left <= up_left && ind_right <= up_right)
	{
		if (arr_buff[ind_left] < arr_buff[ind_right])
			array[ind_arr++] = arr_buff[ind_left++];
		else
			array[ind_arr++] = arr_buff[ind_right++];
	}

	/* copy remaining values (left) */
	while (ind_left <= up_left)
		array[ind_arr++] = arr_buff[ind_left++];
	/* copy remaining values (right) */
	while (ind_right <= up_right)
		array[ind_arr++] = arr_buff[ind_right++];
}
