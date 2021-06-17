#include "sort.h"

void swap_nodes(listint_t **list, listint_t *node_i, listint_t *node_j);
void insert_node_after(listint_t **list, listint_t *prev_node,
	listint_t *node, listint_t *after_node);

/**
 * swap_nodes - Swaps two nodes of a doubly linked list,
 * node_i must be before than node_j
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

/**
 *insertion_sort_list - function that sorts a
 *doubly linked list of integers in ascending order
 *@list: double pointer to the list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *ni, *nj;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (ni = (*list)->next ; ni != NULL; ni = ni->next)
	{
		for (nj = ni; nj->prev != NULL; nj = nj->prev)
		{
			if (nj->prev->n > nj->n)
			{
				swap_nodes(list, nj->prev, nj);
				nj = nj->next;
				print_list(*list);
			}
		}
	}
}
