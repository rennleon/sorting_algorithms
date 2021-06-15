#include "deck.h"

/**
 * insert_node_after - Inserts a node after other passeda as argument
 * @list: Double pointer to list
 * @prev_node: Previous node to 'node'
 * @node: Node to be inserted after 'after_node'
 * @after_node: Node to insert after
*/
void insert_node_after(deck_node_t **list, deck_node_t *prev_node,
	deck_node_t *node, deck_node_t *after_node)
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
 * swap_nodes - Swaps two nodes of a doubly linked list,
 *							node_i must be before than node_j
 * @list: Double pointer to list
 * @node_i: First node
 * @node_j: Second node
*/
void swap_nodes(deck_node_t **list, deck_node_t *node_i, deck_node_t *node_j)
{
	deck_node_t *prev_i, *prev_j;

	prev_i = node_i->prev;
	insert_node_after(list, prev_i, node_i, node_j);

	prev_j = node_j->prev;
	insert_node_after(list, prev_j, node_j, prev_i);
}

/**
 * get_numeric_value - Converts a card value to a numeric representation
 * @card: Card from which to get the value and kind
 *
 * Return: Integer representation of card's value
*/
int get_numeric_value(const card_t *card)
{
	char cval = *(card->value);
	char cval_2 = *(card->value + 1);
	int kind = card->kind;
	int kind_val = kind * 100;

	switch (cval)
	{
		case 'A':
			return (1 + kind_val);
		case 'J':
			return (11 + kind_val);
		case 'Q':
			return (12 + kind_val);
		case 'K':
			return (13 + kind_val);
		default:
			if (cval_2 == '0')
				return (10 + kind_val);
			return (cval - 48 + kind_val);
	}
}

/**
 * cocktail_sort - Sorts a doubly linked list using cockatil sort approach
 * @deck: Double pointer to linked list's head
*/
void cocktail_sort(deck_node_t **deck)
{
	int swapped = 1;
	deck_node_t *start, *end, *ni;

	start = end = *deck;
	while (end->next != NULL)
		end = end->next;

	while (swapped == 1)
	{
		swapped = 0;

		for (ni = start; ni->next != NULL; ni = ni->next)
			if (get_numeric_value(ni->card) > get_numeric_value(ni->next->card))
			{
				swap_nodes(deck, ni, ni->next);
				swapped = 1;
				end = ni;
				ni = ni->prev;
			}

		if (swapped == 0)
			return;

		for (ni = end; ni->prev != NULL; ni = ni->prev)
			if (get_numeric_value(ni->prev->card) > get_numeric_value(ni->card))
			{
				swap_nodes(deck, ni->prev, ni);
				swapped = 1;
				start = ni;
				ni = ni->next;
			}
	}
}

/**
 * sort_deck - Sorts a deck of cards
 * @deck: Double poiter to a list of cards
*/
void sort_deck(deck_node_t **deck)
{
	if (deck == NULL || *deck == NULL)
		return;

	cocktail_sort(deck);
}
