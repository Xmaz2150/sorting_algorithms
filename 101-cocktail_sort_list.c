#include <stdio.h>
#include "sort.h"

void swap_nodes(listint_t **list, listint_t *first_node, listint_t *second_node);

/**
* cocktail_sort_list - sorting algo, sorts doubly lls of ints
*
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
* @first_node: Input, first node to be swapped with
* @second_node: Input, second node to be swapped
*
* Return: none
*/
void swap_nodes(listint_t **list, listint_t *first_node, listint_t *second_node)
{

	if (first_node->prev != NULL)
		first_node->prev->next = second_node;
	else
		*list = second_node;

	if (second_node->next != NULL)
		second_node->next->prev = first_node;

	first_node->next = second_node->next;
	second_node->prev = first_node->prev;

	first_node->prev = second_node;
	second_node->next = first_node;
}

