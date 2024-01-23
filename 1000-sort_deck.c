#include "deck.h"

/**
 * value_check - compares the values of a card
 * @a: first card value
 * @b: second card value
 *
 * Returns: 0 if equal, 1 if a > b, -1 otherwise
 */

int value_check(const char *a, const char *b)
{
	int A, B;
	
	if (!(strcmp("Ace", a)))
		A = 1;
	else if (!(strcmp("Jack", a)))
		A = 11;
	else if (!(strcmp("Queen", a)))
		A = 12;
	else if (!(strcmp("King", a)))
		A = 13;
	else
		A = atoi(a);
		
	if (!(strcmp("Ace", b)))
		B = 1;
	else if (!(strcmp("Jack", b)))
		B = 11;
	else if (!(strcmp("Queen", b)))
		B = 12;
	else if (!(strcmp("King", b)))
		B = 13;
	else
		B = atoi(b);
	
	return (A - B);
}

/**
 * card_sort - comparator function for the qsort
 * @a: element to compare
 * @b: second element
 *
 * Return: 0 if equal, 1 if a > b and -1 if a < b.
 */

int card_sort(const void* a, const void* b)
{
	deck_node_t *cardA = (deck_node_t*)a;
	deck_node_t *cardB = (deck_node_t*)b;

	if (cardA->card->kind > cardB->card->kind)
		return 1;
	else if (cardA->card->kind < cardB->card->kind)
		return -1;
	else
		return value_check(cardA->card->value, cardB->card->value);
}

/**
 * de_init - converts the linked list into an
 * array of the addresses of the nodes
 * @deck: the head node of the list
 *
 * Return: array of cards
 */

deck_node_t **de_init(deck_node_t **deck)
{
	deck_node_t **cards;
	int i = 0;
	deck_node_t *iter = *deck;

	cards = malloc(sizeof(deck_node_t*) * 52);
	if (!cards)
		return NULL;

	while (iter && i < 52)
	{
		cards[i] = iter;
		i++;
		iter = iter->next;
	}
	return cards;
}

/**
 * re_init - rearranges the nodes based on the sorted
 * array of nodes
 * @deck: initial deck of cards
 * @cards: sorted array deck nodes
 */

void re_init(deck_node_t **deck, deck_node_t **cards)
{
	int i = 1;
	deck_node_t *iter;

	*deck = cards[0];
	(*deck)->prev = NULL;
	iter = *deck;
	while (iter && i < 52)
	{
		iter->next = cards[i];
		iter->prev = cards[i - 1];
		iter = iter->next;
		i++;
	}
	iter->next = NULL;
}

/**
 * sort_deck - sorts the a deck of cards
 * using the builtin qsort function.
 *
 * @deck: the deck to sort.
 */

void sort_deck(deck_node_t **deck)
{
	deck_node_t **cards;

	if (!deck || !(*deck) || !((*deck)->next))
		return;

	cards = de_init(deck);
	if (cards == NULL)
		return;

	qsort((deck_node_t*)cards, 52, sizeof(cards[0]), card_sort);
	re_init(deck, cards);
}
