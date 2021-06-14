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
	if (arr_buff == NULL)
		return;

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
	int middle;

	if (lower >= upper)
		return;

	middle = (lower + upper - 1) / 2;

	solve_merge(array, arr_buff, lower, middle);
	solve_merge(array, arr_buff, middle + 1, upper);
	merge(array, arr_buff, lower, middle, middle + 1, upper);
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

	for (i = lo_left; i <= up_left; i++)
		arr_buff[i] = array[i];
	for (i = lo_right; i <= up_right; i++)
		arr_buff[i] = array[i];

	printf("Merging...\n");
	printf("[left]: ");
	print_array(&array[lo_left], up_left - lo_left + 1);
	printf("[right]: ");
	print_array(&array[lo_right], up_right - lo_right + 1);

	while (ind_left <= up_left && ind_right <= up_right)
	{
		if (arr_buff[ind_left] <= arr_buff[ind_right])
			array[ind_arr++] = arr_buff[ind_left++];
		else
			array[ind_arr++] = arr_buff[ind_right++];
	}

	while (ind_left <= up_left)
		array[ind_arr++] = arr_buff[ind_left++];
	while (ind_right <= up_right)
		array[ind_arr++] = arr_buff[ind_right++];

	printf("[Done]: ");
	print_array(&array[lo_left], up_right - lo_left + 1);
}
