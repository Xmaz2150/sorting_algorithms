#include "sort.h"


void swap(int *a, int *b);

/**
 * shell_sort - sorting algo, sorts in ascending order
 * @array: Input, elements
 * @size: Input, len of array
 *
 */
void shell_sort(int *array, size_t size)
{
	size_t gap, i, j;

	if (array == NULL || size < 2)
		return;

	for (gap = 1; gap < (size / 3);)
		gap = gap * 3 + 1;

	for (; gap >= 1; gap /= 3)
	{
		for (i = gap; i < size; i++)
		{
			j = i;
			while (j >= gap && array[j - gap] > array[j])
			{
				swap(array + j, array + (j - gap));
				j -= gap;
			}
		}
		print_array(array, size);
	}
}

/**
 * swap - Swap two elements
 * @a: Input, first ele
 * @b: Input, second ele
 *
 * Return: None
 */
void swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

