#include "sort.h"

/**
 * swap - change two elements of position
 * @array: array to be sorted
 * @fi: index first element
 * @se: index second element
 */
void swap(int *array, int fi, int se)
{
	int temp;

	temp = array[fi];
	array[fi] = array[se];
	array[se] = temp;
}

/**
 * quicksort - Function to divide the array
 * after the new position of the pivot is returned
 * @array: array to be sorted
 * @lo: lowest index of the array
 * @hi: jighest index of the array
 * @size: size of the array
 */
void quicksort(int *array, int lo, int hi, size_t size)
{
	int pivot = array[hi];
	int i = lo;
	int j;

	if (lo < hi)
	{
		for (j = lo; j <= hi; j++)
		{
			if (array[j] < pivot)
			{
				swap(array, i, j);
				if (i != j)
					print_array(array, size);
				i += 1;
			}
		}
		swap(array, i, hi);
		if (i != hi)
			print_array(array, size);
		quicksort(array, lo, i - 1, size);
		quicksort(array, i + 1, hi, size);
	}
}
/**
 * quick_sort - Function to start the sort of the array
 * @array: array to be sorted
 * @size: size of the array
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	quicksort(array, 0, (int)(size - 1), size);
}
