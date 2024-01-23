#include "sort.h"

/**
 * swaps - swaps two nodes
 * @list: list to be sorted
 * @right: ...
 * @left: ...
 */
void swaps(listint_t **list, listint_t *left, listint_t *right)
{
	listint_t *swap;

	if (left->prev)
		left->prev->next = right;
	else
		*list = right;
	if (right->next)
		right->next->prev = left;

	right->prev = left->prev;
	left->prev = right;
	swap = right;
	left->next = right->next;
	swap->next = left;

	print_list(*list);
}

/**
 * cocktail_sort_list - sorts a list of integers using
 * cocktail shaker sort algorithm
 * @list: list to be sorted
 */

void cocktail_sort_list(listint_t **list)
{
	int new_range = 1000000, new_checks;
	int new_swapped_f, new_swapped_b;
	listint_t *temp;

	if (!list || !(*list) || !(*list)->next)
		return;

	temp = *list;
	do {
		new_swapped_f = new_swapped_b = 0;
		for (new_checks = 0; temp->next && new_checks < new_range; new_checks++)
		{
			if (temp->next->n < temp->n)
			{
				swaps(list, temp, temp->next);
				new_swapped_f = 1;
			} else
				temp = temp->next;
		}
		if (!temp->next)
			new_range = new_checks;

		if (new_swapped_f)
			temp = temp->prev;

		new_range--;
		for (new_checks = 0; temp->prev && new_checks < new_range; new_checks++)
		{
			if (temp->n < temp->prev->n)
			{
				swaps(list, temp->prev, temp);
				new_swapped_b = 1;
			} else
				temp = temp->prev;
		}
		if (new_swapped_b)
			temp = temp->next;
	} while (new_swapped_f || new_swapped_b);
}
