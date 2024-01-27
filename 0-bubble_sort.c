#include "sort.h"

/**
 * bubble_sort - sorting algorithm
 * @array: Input, array to sort
 * @size: Input, array len
 *
 * Return, none
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, j, tmp, idx0, idx1;

	if (size < 2)
		return;
	for (i = 0; i < size; i++)
	{

		for (j = 0; j < size - 1; j++)
		{
			idx0 = j;
			idx1 = j + 1;
			if (array[idx0] > array[idx1])
			{
				tmp = array[idx0];
				array[idx0] = array[idx1];
				array[idx1] = tmp;
				print_array(array, size);
			}
		}
	}
}

