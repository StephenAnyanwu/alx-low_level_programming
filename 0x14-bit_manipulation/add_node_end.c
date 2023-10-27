#include "main.h"

/**
 * add_node_end - a function that add node at the end of a b linked list.
 * @head: a pointer to a pointer to the head of the list.
 * @exp: value of the node.
*/

void add_node_end(b **head, unsigned long int exp)
{
	b *temp;
	
	b *new_node = calloc(1, sizeof(b));
	new_node->exp = exp;
	new_node->next = NULL;
	temp = *head;
	if(*head == NULL)
		*head;
	else
		while (temp->next != NULL)
			temp = temp->next;
	temp->next = new_node;
}
