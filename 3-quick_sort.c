#include "sort.h"

/**
 * swap - change two elements of position
 * @fi: index first element
 * @la: index second element
 * @array: array to be sorted
 * @size: size of the array
 */
void swap(int *fi, int *la, int *array, size_t size)
{
	int temp;

	temp = *fi;
	*fi = *la;
	*la = temp;
	if (temp != *fi)
		print_array(array, size);
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
				swap(&array[i], &array[j], array, size);
				i += 1;
			}
		}
		swap(&array[i], &array[hi], array, size);
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
