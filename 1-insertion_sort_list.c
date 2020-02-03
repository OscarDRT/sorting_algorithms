#include "sort.h"

/**
 * insertion_sort_list - function that sorts an array
 * of integers in ascending order using the Bubble sort algorithm
 * @list: list to be sorted
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current = NULL, *index = NULL, *before = NULL;

	if (list == NULL || *list == NULL)
		return;
	current = *list;
	while (current->next != NULL)
	{
		index = current->next;
		if (current->n > index->n)
		{
			before = current;
			while (before != NULL)
			{
				if (before->n > index->n)
				{
					if (before->prev == NULL && index->next != NULL)
						index->next->prev = before, *list = index;
					if (index->next == NULL && before->prev != NULL)
						before->prev->next = index;
					if (index->next != NULL && before->prev != NULL)
						index->next->prev = before, before->prev->next = index;
					before->next = index->next;
					index->prev = before->prev;
					before->prev = index, index->next = before;
					before = index->prev;
					while ((*list)->prev != NULL)
						(*list) = (*list)->prev;
					print_list(*list);
				}
				else
					before = before->prev;
			}
		}
		else
			current = current->next;
	}
}
