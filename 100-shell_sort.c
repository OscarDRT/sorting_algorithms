#include "sort.h"
/**
 * shell_sort - function that sorts an array of integers in ascending
 * order using the Shell sort algorithm, using the Knuth sequence
 * @array: array to be sorted
 * @size: size of the array
 */
void shell_sort(int *array, size_t size)
{
	int gap = 1;
	int i, j, k, l, temp;

	if (array == NULL || size < 2)
		return;
	while (gap < (int)size / 3)
	{
		gap = gap * 3 + 1;
	}
	while (gap)
	{
		for (i = 0, j = gap; j < (int)size; i++, j++)
		{
			if (array[j] < array[i])
			{
				for (k = j, l = i; l >= 0; k = k - gap, l = l - gap)
				{
					if (array[k] < array[l])
					{
						temp = array[k];
						array[k] = array[l];
						array[l] = temp;
					}
					else
						break;
				}
			}
		}
	print_array(array, size);
	gap = (gap - 1) / 3;
	}
}
