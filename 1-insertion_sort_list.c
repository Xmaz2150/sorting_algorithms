#include "sort.h"

listint_t *swap_node(listint_t *node, listint_t **list);

/**
 * insertion_sort_list - sorting algorithm
 * @list: Input, doubly lls to sort
 *
 * Return: none
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *node;

	if (list == NULL || (*list)->next == NULL)
		return;
	node = (*list)->next;
	while (node)
	{
		while ((node->prev) && (node->prev->n > node->n))
		{
			node = swap_node(node, list);
			print_list(*list);
		}
		node = node->next;
	}
}

/**
 * swap_nodo - insertion helper
 * @node: Input, node
 * @list: Input, lls
 *
 * Return: node
 */
listint_t *swap_node(listint_t *node, listint_t **list)
{
	listint_t *prev_node, *current;

	prev_node = node->prev;
	current = node;

	prev_node->next = current->next;
	if (current->next)
		current->next->prev = prev_node;

	current->next = prev_node;
	current->prev = prev_node->prev;
	prev_node->prev = current;

	if (current->prev)
		current->prev->next = current;
	else
		*list = current;
	return (current);
}
