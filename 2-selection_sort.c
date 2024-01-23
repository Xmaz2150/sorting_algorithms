#include "sort.h"

/**
 * selection_sort  sorting algorithm
 * @array: Input, array to sort
 * @size: Input, array len
 *
 * Return: none
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j,  tmp, swap, tag;

	if (array == NULL)
		return;
	tag = 0;
	for (i = 0; i < size; i++)
	{
		tmp = i;
		tag = 0;
		for (j = i + 1; j < size; j++)
		{
			if (array[tmp] > array[j])
			{
				tmp = j;
				tag += 1;
			}
		}
		swap = array[i];
		array[i] = array[tmp];
		array[tmp] = swap;
		if (tag != 0)
			print_array(array, size);
	}
}
