#include "sort.h"

void swap(int *arr, size_t idx0, size_t idx1, size_t *swaps_addr);
void bubble_helper(int *array, size_t size);

void bubble_sort(int *array, size_t size)
{
	bubble_helper(array, size);
	/* calling helper again to ensure comple sort */
	bubble_helper(array, size);
}

void swap(int *arr, size_t idx0, size_t idx1, size_t *swaps_addr)
{
	size_t tmp;

	if (arr[idx0] > arr[idx1])
	{
		tmp = arr[idx0];
		arr[idx0] = arr[idx1];
		arr[idx1] = tmp;
		*swaps_addr = 1;
	}
}

void bubble_helper(int *array, size_t size)
{
	size_t i, swaps;

	print_array(array, size);
	swaps = 0;
	for (i = 0; i < size - 1; i++)
	{
		swap(array, i, i + 1, &swaps);
		if (i == size - 2)
		{
			print_array(array, size);
			if (swaps == 1)
			{
				i = 0;
				swaps = 0;
			}
		}
	}
}
