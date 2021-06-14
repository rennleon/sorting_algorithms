#include "sort.h"

void swap_nodes(listint_t **list, listint_t *node_i, listint_t *node_j);
void insert_node_after(listint_t **list, listint_t *prev_node,
	listint_t *node, listint_t *after_node);

/**
 * cocktail_sort_list - Sorts an array using cocktail shaker sort algorithm
 * @list: Doubly linked list
*/
void cocktail_sort_list(listint_t **list)
{
	int swapped = 1;
	listint_t *start, *end, *curr;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	start = end = *list;
	while (end->next != NULL)
		end = end->next;

	while (swapped == 1)
	{
		swapped = 0;

		for (curr = start; curr != NULL &&  curr->next != NULL; curr = curr->next)
		{
			if (curr->n > curr->next->n)
			{
				swap_nodes(list, curr, curr->next);
				print_list(*list);
				end = curr;
				curr = curr->prev;
				swapped = 1;
			}
		}

		if (swapped == 0)
			break;

		for (curr = end; curr != NULL && curr->prev != NULL; curr = curr->prev)
		{
			if (curr->n < curr->prev->n)
			{
				swap_nodes(list, curr->prev, curr);
				print_list(*list);
				start = curr;
				curr = curr->next;
				swapped = 1;
			}
		}
	}
}

/**
 * swap_nodes - Swaps two nodes of a doubly linked list,
 *							node_i must be before than node_j
 * @list: Double pointer to list
 * @node_i: First node
 * @node_j: Second node
*/
void swap_nodes(listint_t **list, listint_t *node_i, listint_t *node_j)
{
	listint_t *prev_i, *prev_j;

	prev_i = node_i->prev;
	insert_node_after(list, prev_i, node_i, node_j);

	prev_j = node_j->prev;
	insert_node_after(list, prev_j, node_j, prev_i);
}

/**
 * insert_node_after - Inserts a node after other passeda as argument
 * @list: Double pointer to list
 * @prev_node: Previous node to 'node'
 * @node: Node to be inserted after 'after_node'
 * @after_node: Node to insert after
*/
void insert_node_after(listint_t **list, listint_t *prev_node,
	listint_t *node, listint_t *after_node)
{
	/* Remove node from list */
	if (prev_node == NULL)
		(*list) = (*list)->next;
	else
		prev_node->next = node->next;
	node->next->prev = prev_node;

	/* Insert node after after_node */
	if (after_node == NULL)
	{
		(*list)->prev = node;
		node->prev = NULL;
		node->next = *list;
		*list = node;
		return;
	}

	node->next = after_node->next;
	node->prev = after_node;
	if (after_node->next != NULL)
		after_node->next->prev = node;
	after_node->next = node;
}
