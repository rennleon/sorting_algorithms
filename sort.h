#ifndef SORT_H
#define SORT_H

#include <stdio.h>
#include <stdlib.h>

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

/* Function prototypes */
void print_array(const int *array, size_t size);
void print_list(const listint_t *list);

/* Sorting functions (Mandatory) */
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);

/* Sorting functions (Aadvanced) */
void shell_sort(int *array, size_t size);
void cocktail_sort_list(listint_t **list);

/* Utils */
void swap(int *arr, int i, int j);

#endif /* SORT_H */
