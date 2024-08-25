#include <stdlib.h>
#include "binary_trees.h"

/**
 * sorted_array_to_avl - Recursively
 *builds an AVL tree from a sorted array.
 * @array: Pointer to the first element of the array to be converted.
 * @size: Number of elements in the array.
 *
 * Return: Pointer to the root node of the
 * created AVL tree, or NULL on failure.
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	if (array == NULL || size == 0)
		return (NULL);

	return (build_avl(array, 0, size - 1));
}

/**
 * build_avl - Recursively builds an AVL tree from a sorted array.
 * @array: Pointer to the first element of the array to be converted.
 * @start: Starting index of the array.
 * @end: Ending index of the array.
 *
 * Return: Pointer to the root node of the created
 * AVL tree, or NULL on failure.
 */
avl_t *build_avl(int *array, int start, int end)
{
	avl_t *node;
	int mid;

	if (start > end)
		return (NULL);

	mid = (start + end) / 2;
	node = create_node(NULL, array[mid]);
	if (node == NULL)
		return (NULL);

	node->left = build_avl(array, start, mid - 1);
	if (node->left != NULL)
		node->left->parent = node;

	node->right = build_avl(array, mid + 1, end);
	if (node->right != NULL)
		node->right->parent = node;

	return (node);
}

/**
 * create_node - Creates a new AVL tree node.
 * @parent: Pointer to the parent node.
 * @value: Value to be stored in the new node.
 *
 * Return: Pointer to the new node, or NULL on failure.
 */
avl_t *create_node(avl_t *parent, int value)
{
	avl_t *node = malloc(sizeof(avl_t));

	if (node == NULL)
		return (NULL);

	node->n = value;
	node->parent = parent;
	node->left = NULL;
	node->right = NULL;

	return (node);
}
