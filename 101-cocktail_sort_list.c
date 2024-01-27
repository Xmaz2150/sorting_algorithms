#include <stdio.h>
#include "sort.h"

void swap_nodes(listint_t **list, listint_t *fst_node, listint_t *sec_node);

/**
* cocktail_sort_list - sorting algo, sorts doubly lls of ints
* @list: Input, head of doubly lls
*
* Return: none
*/
void cocktail_sort_list(listint_t **list)
{
	int swapped;
	listint_t *start, *end;

	swapped = 1;
	start = *list;
	end = NULL;

	if (*list == NULL)
		return;

	while (swapped)
	{
		swapped = 0;

		while (start->next != end)
		{
			if (start->n > start->next->n)
			{
				swap_nodes(list, start, start->next);
				print_list(*list);
				swapped = 1;
			}
			else
				start = start->next;
		}

		if (!swapped)
			break;

		swapped = 0;

		end = start;

		while (start->prev != NULL)
		{
			if (start->n < start->prev->n)
			{
				swap_nodes(list, start->prev, start);
				print_list(*list);
				swapped = 1;
			}
			else
				start = start->prev;
		}
	}
}

/**
* swap_nodes - swaps two nodes in doubly lls
*
* @list: Input, head of lls
* @fst_node: Input, first node to be swapped with
* @sec_node: Input, second node to be swapped
*
* Return: none
*/
void swap_nodes(listint_t **list, listint_t *fst_node, listint_t *sec_node)
{

	if (fst_node->prev != NULL)
		fst_node->prev->next = sec_node;
	else
		*list = sec_node;

	if (sec_node->next != NULL)
		sec_node->next->prev = fst_node;

	fst_node->next = sec_node->next;
	sec_node->prev = fst_node->prev;

	fst_node->prev = sec_node;
	sec_node->next = fst_node;
}

