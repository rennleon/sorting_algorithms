#include "sort.h"

/**
 * bubble_sort - function that sorts an array
 * of integers in ascending order.
 *
 * @array: data to be sorted.
 * @size: size of array.
 *
 * Return: void
 */
void bubble_sort(int *array, size_t size)
{

	size_t idx = 0, tmp = 0, count;

	if (array == NULL || size < 2)
	{
		return;
	}

	for (count = 1; count < size; count++)
	{
		for (idx = 0; idx < size - 1; idx++)
		{
			if (array[idx] > array[idx + 1])
			{
				tmp = array[idx];
				array[idx] = array[idx + 1];
				array[idx + 1] = tmp;

				print_array(array, size);
			}
		}
	}
}

