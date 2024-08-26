#include "search.h"

/**
 * linear_skip - Searches for a value in a sorted skip list of integers.
 * @list: Pointer to the head of the skip list to search in
 * @value: Value to search for
 *
 * Return: Pointer to the first node where value is located,
 * or NULL if not found
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *current = list, *express = NULL;

	if (!list)
		return (NULL);

	express = current->express;

	while (express)
	{
		printf("Value checked at index [%lu] = [%d]\n",
			   express->index, express->n);
		if (express->n >= value)
		{
			printf("Value found between indexes [%lu] and [%lu]\n",
				   current->index, express->index);
			break;
		}
		current = express;
		express = express->express;
	}

	if (!express)
	{
		current = list;
		while (current->next)
			current = current->next;
		printf("Value found between indexes [%lu] and [%lu]\n",
			   current->index, current->index);
	}

	current = current->express ? current : current->next;
	while (current)
	{
		printf("Value checked at index [%lu] = [%d]\n",
			   current->index, current->n);
		if (current->n == value)
			return (current);
		current = current->next;
	}
	return (NULL);
}
