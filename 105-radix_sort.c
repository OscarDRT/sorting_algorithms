#include "sort.h"
/**
 * radix_sort - function that sorts an array of integers in ascending
 * order using the radix sort algorithm
 * @array: array to be sorted
 * @size: size of the array
 */
void radix_sort(int *array, size_t size)
{
	int big, i, k, j, div = 1, index;
	int *copy;

	if (array == NULL || size < 2)
		return;
	copy = malloc(sizeof(int) * size);
	if (copy == NULL)
		return;
	big = array[0];
	for (i = 0; i < (int)size; i++)
	{
		if (array[i] > big)
			big = array[i];
	}
	for (div = 1; (big / div) > 0; div *= 10)
	{
		index = 0;
		for (i = 0; i < 10; i++)
		{
			for (j = 0; j < (int)size; j++)
			{
				if (div == 1)
				{
					if (array[j] % 10 == i)
						copy[index] = array[j], index++;
				}
				else
				{
					if ((array[j] / div) % 10 == i)
						copy[index] = array[j], index++;
				}
			}
		}
		for (k = 0; k < (int)size; k++)
			array[k] = copy[k];
		print_array(array, size);
	}
	free(copy);
}
