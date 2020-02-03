#include "sort.h"
/**
 * selection_sort - function that sorts an array
 * of integers in ascending order using the Bubble sort algorithm
 * @array: array to be sorted
 * @size: size of the array
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, index;
	int temp;

	if (array == NULL || size < 2)
		return;
	for (i = 0; i < size; i++)
	{
		index = i;
		for (j = i; j < size; j++)
		{
			if (array[j] < array[index])
			{
				index = j;
			}
		}
		if (index != i)
		{
			temp = array[index];
			array[index] = array[i];
			array[i] = temp;
			print_array(array, size);
		}
	}
}
