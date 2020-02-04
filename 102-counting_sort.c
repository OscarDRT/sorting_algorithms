#include "sort.h"
/**
 * counting_sort - function that sorts an array
 * of integers in ascending order using the counting sort algorithm
 * @array: array to be sorted
 * @size: size of the array
 */

void counting_sort(int *array, size_t size)
{
	int k, i = 0, counter = 0;
	int *count, *old;

	if (array == NULL || size < 2)
		return;
	old = malloc(sizeof(int) * (size));
	if (old == NULL)
		return;
	k = array[0];
	for (i = 0; i < (int)size; i++)
	{
		old[i] = array[i];
		if (array[i] > k)
			k = array[i];
	}
	count = malloc(sizeof(int) * (k + 1));
	if (count == NULL)
		return;
	for (i = 0; i < (int)size; i++)
		count[array[i]] += 1;
	for (i = 0; i <= k; i++)
	{
		counter = counter + count[i];
		count[i] = counter;
	}
	print_array(count, (size_t)(k + 1));
	for (i = 0; i < (int)size; i++)
	{
		array[count[old[i]] - 1] = old[i];
		count[old[i]]--;
	}
	free(count);
	free(old);
}
