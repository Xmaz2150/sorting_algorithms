#include "sort.h"

void swap(int *arr, size_t size);
void bubble_helper(int *array, size_t size);

void bubble_sort(int *array, size_t size)
{
	bubble_helper(array, size);
	/* calling helper again to ensure comple sort */
	bubble_helper(array, size);
}

void swap(int *arr, size_t size)
{
	size_t i, tmp, idx0, idx1;

	for (i = 0; i < size - 1; i++)
	{
		idx0 = i;
		idx1 = i + 1;
		if (arr[idx0] > arr[idx1])
		{
			tmp = arr[idx0];
			arr[idx0] = arr[idx1];
			arr[idx1] = tmp;
		}
	}
}

void bubble_helper(int *array, size_t size)
{
	size_t i;

	if (size < 2)
		return;
	for (i = 0; i < size; i++)
	{
		swap(array, size);
		print_array(array, size);
	}
}
