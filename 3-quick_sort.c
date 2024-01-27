#include "sort.h"

int split(int *array, size_t size, int low, int high);
void swap(int *a, int *b);

/**
 * quick_sort - sorting algorithm that uses devide and conquer approach
 * @array: Input, elements
 * @size: Input, array len
 *
 * Return: none
 */
void quick_sort(int *array, size_t size)
{
	int pivot_index, split_index;

	if (size <= 1)
		return;

	pivot_index = size - 1;
	split_index = split(array, size, 0, pivot_index);

	quick_sort(array, split_index);
	quick_sort(array + split_index + 1, size - split_index - 1);
	print_array(array, size);
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

/**
 * split - splits tot elements by two
 * @array: Input, elements
 * @low: Input, lowest index
 * @high: Input, highest index
 *
 * Return: int
 */
int split(int *array, size_t size, int low, int high)
{
	int ruler, i, j;

	(void)size;
	ruler = array[high];
	i = low - 1;

	for (j = low; j < high; j++)
	{
		if (array[j] <= ruler)
		{
			i++;
			swap(&array[i], &array[j]);
		}
	}
	swap(&array[i + 1], &array[high]);

	return (i + 1);
}

