#include "sort.h"

/**
 * bubble_sort - function that sorts an array
 * of integers in ascending order using the Bubble sort algorithm
 * @array: sorting array
 * @size: length array
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, len = size;
	int swap = 0, ordered = 1;

	if (array == NULL || size < 2)
		return;
	while (ordered)
	{
		ordered = 0;
		for (i = 0; i < len - 1; i++)
		{
			if (array[i] > array[i + 1])
			{
				swap = array[i];
				array[i] = array[i + 1];
				array[i + 1] = swap;
				ordered = 1;
				print_array((const int *)array, size);
			}
			if (i == (len - 2))
				len -= 1;
		}
	}
}
