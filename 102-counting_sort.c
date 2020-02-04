#include "sort.h"
/**
 * counting_sort - function that sorts an array
 * of integers in ascending order using the counting sort algorithm
 * @array: array to be sorted
 * @size: size of the array
 */

void counting_sort(int *array, size_t size)
{
	int k, i = 0;
	int *count, *old;

	if (array == NULL || size < 2)
		return;
	old = malloc(sizeof(int) * (size));
	if (old == NULL)
		return;
	k = array[0];
	while (array[i])
	{
		old[i] = array[i];
		if (array[i] > k)
			k = array[i];
		i++;
	}
	count = malloc(sizeof(int) * (k + 1));
	if (count == NULL)
		return;
	i = 0;
	while (array[i])
	{
		count[array[i]] += 1;
		i++;
	}
	for (i = 0; i <= k; i++)
		count[i] += count[i - 1];
	print_array(count, (size_t)(k + 1));
	i = 0;
	for (i = 0; i < (int)size; i++)
	{
		array[count[old[i]] - 1] = old[i];
		count[old[i]]--;
	}
}
