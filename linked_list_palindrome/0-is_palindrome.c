#include <stdio.h>
#include "lists.h"

/**
 * is_palindrome - checks if a singly linked list is a palindrome
 * @head: pointer to a pointer to the head of the list
 * Return: 1 if the list is a palindrome, 0 otherwise
 */
int is_palindrome(listint_t **head)
{
	int len = 0;
	int i, j;
	listint_t *current;
	listint_t *array[4096];

	if (*head == NULL)
		return (1);

	current = *head;

	while (current != NULL)
	{
		array[len] = current;
		current = current->next;
		len++;
	}

	for (i = 0, j = len - 1; i < j; i++, j--)
	{
		if (array[i]->n != array[j]->n)
			return (0);
	}

	return (1);
}
