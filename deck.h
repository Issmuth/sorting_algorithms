#ifndef DECK_H
#define DECK_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum kind_e
{
	SPADE = 0,
	HEART,
	CLUB,
	DIAMOND
} kind_t;

/**
 * struct card_s - Playing card
 * 
 * @value: Value of the card
 * From "Ace" to "King"
 * @kind: Kind of the card
 */

typedef struct card_s
{
	const char *value;
	const kind_t kind;
} card_t;

/**
 * struct deck_node_s - Deck of card
 *
 * @card: Pointer to the card of the node
 * @prev: Pointer to the previous node of the list
 * @next: Pointer to the next node of the list
 */

typedef struct deck_node_s
{
	const card_t *card;
	struct deck_node_s *prev;
	struct deck_node_s *next;
} deck_node_t;
void sort_deck(deck_node_t **deck);
int card_sort(const void* a, const void* b);
void re_init(deck_node_t **deck, deck_node_t **cards);
deck_node_t **de_init(deck_node_t **deck);
int value_check(const char *a, const char *b);
#endif
