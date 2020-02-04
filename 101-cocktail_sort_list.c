#include "sort.h"
/**
 * swap_list - function that swaps the nodes in the list
 * @list: list to be print
 * @index: node to swap
 * @current: node to swap
 */
void swap_list(listint_t **list, listint_t *index, listint_t *current)
{
	if (current->prev == NULL && index->next != NULL)
		index->next->prev = current;
	if (index->next == NULL && current->prev != NULL)
		current->prev->next = index;
	if (index->next != NULL && current->prev != NULL)
		index->next->prev = current, current->prev->next = index;
	current->next = index->next;
	index->prev = current->prev;
	current->prev = index, index->next = current;
	while ((*list)->prev != NULL)
		(*list) = (*list)->prev;
	print_list(*list);
}
/**
 * cocktail_sort_list - function that sorts an array
 * of integers in ascending order using the Cocktail sort algorithm
 * @list: list to be sorted
 */
void cocktail_sort_list(listint_t **list)
{
	int ordered = 1;
	listint_t *current = NULL, *index = NULL;

	if (list == NULL || *list == NULL)
		return;
	current = *list;
	while (ordered)
	{
		ordered = 0;
		while (current->next)
		{
			index = current->next;
			if (current->n > index->n)
			{
				swap_list(list, index, current);
				ordered = 1;
			}
			else
				current = current->next;
		}
		while (current->prev)
		{
			index = current->prev;
			if (current->n < index->n)
			{
				swap_list(list, current, index);
				ordered = 1;
			}
			else
				current = current->prev;
		}
	}
}
