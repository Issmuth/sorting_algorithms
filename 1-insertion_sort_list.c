#include "sort.h"

/**
 * insertion_sort_list - sort a list of integers
 * using the insertion sort algorithm
 * @list: list to be sorted
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *current, *iterator, *temp;

	if (!list || !(*list) || !((*list)->next))
		return;

	current = (*list)->next;
	while (current)
	{
		temp = current->next;
		iterator = current->prev;

		while (iterator && (current->n < iterator->n))
		{
			iterator->next = current->next;
			if (current->next != NULL)
				current->next->prev = iterator;
			current->prev = iterator->prev;
			current->next = iterator;
			if (iterator->prev != NULL)
				iterator->prev->next = current;
			else
				*list = current;
			iterator->prev = current;
			iterator = current->prev;
			print_list(*list);
		}
		current = temp;
	}
}
