#include "sort.h"

/**
 * swap_node - swaps 2 nodes in a list
 *
 * @list: linked list
 * @node_1: first node to swap
 * @node_2: second node to swap
 *
 */

void swap_node(listint_t **list, listint_t *node_1, listint_t *node_2)
{
	listint_t *tmp = node_1->prev;

	node_1->next = node_2->next;

	if (node_1->next != NULL)
		node_2->next->prev = node_1;
	node_1->prev = node_2;
	node_2->next = node_1;
	node_2->prev = tmp;

	if (node_2->prev != NULL)
		node_2->prev->next = node_2;
	else
		*list = node_2;
}

/**
 * insertion_sort_list - sorts a doubly linked list in ascending order
 * using the insertion sort
 *
 * @list: list to sort
 *
 */

/* recursively call swap_node since n must not be touched */

void insertion_sort_list(listint_t **list)
{
	listint_t *tmp = NULL, *current = NULL;

	if (!list || !(*list))
		return;

	current = *list;
	while (current->next != NULL)
	{
		tmp = current->next;
		if (current->n > current->next->n)
		{
			swap_node(list, tmp->prev, tmp);
			print_list(*list);
			current = tmp;
			while (tmp->prev != NULL && tmp->n < tmp->prev->n)
			{
				swap_node(list, tmp->prev, tmp);
				print_list(*list);
			}
		}
		current = current->next;
	}
}
