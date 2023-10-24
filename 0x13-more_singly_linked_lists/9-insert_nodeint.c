#include "lists.h"

/**
 * insert_nodeint_at_index - a function that inserts a
 * new node at a given position.
 * @head: a pointer to a pointer to the list's head.
 * @idx: is the index of the list where the new node
 * should be added. Index starts at 0.
 * @n: value of the new node to be added.
 * Return: the address of the new node, or NULL if it failed.
*/
listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
	listint_t *temp = *head, *ptr = *head, *new_node;
	unsigned int i, len = 0, b = 0;

	if (temp == NULL || head == NULL || *head == NULL)
		return (NULL);
	while (temp != NULL)
	{
		len++;
		temp = temp->next;
	}
	new_node = malloc(sizeof(listint_t));
	new_node->n = n;
	new_node->next = NULL;
	if (idx < b || idx > len || new_node == NULL)
		return (NULL);
	if (idx == b)
	{
		new_node->next = *head;
		*head = new_node;
	}
	if (idx == len)
	{
		temp = *head;
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = new_node;
	}
	if (idx > b && idx < len)
	{
		for (i = b; i < idx - 1; i++)
			ptr = ptr->next;
		new_node->next = ptr->next;
		ptr->next = new_node;
	}
	return (new_node);
}
