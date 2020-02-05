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
 * partition - this compares and changes positions
 * @array: array to be sorted
 * @size: size of the array
 * @hi: index first element
 * @lo: index second element
 */
int partition(int *array, size_t size, int hi, int lo)
{
	int i = lo, j = hi, piv = hi;

	size = size;
	while (i < j)
	{
		for ( ; array[i] <= array[piv];)
			i++;
		for ( ; array[j] > array[piv];)
			j--;
		if (j > i)
			swap(&array[i], &array[j], array, size);
		if (j == piv && j > i)
			piv = i;
	}
	swap(&array[piv], &array[j], array, size);
	return (j);
}
/**
 * quicksorthoare - divides the array with the pivot
 * @array: array to be sorted
 * @lo: index second element
 * @hi: index first element
 * @size: size of the array
 */
void quicksorthoare(int *array, int lo, int hi, size_t size)
{
	int piv;

	if (lo < hi)
	{
		piv = partition(array, size, hi, lo);
		quicksorthoare(array, lo, piv - 1, size);
		quicksorthoare(array, piv + 1, hi, size);
	}
}
/**
 * quick_sort_hoare - quick sort hoare function
 * @array: array to be sorted
 * @size: size of the array
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	quicksorthoare(array, 0, ((int)size - 1), size);
}
