#include "binary_trees.h"

/**
 * binary_tree_node - Creates a new binary tree node
 *
 * @parent:  is a pointer to the parent node of the node to create
 * @value: is the value to put in the new node
 *
 * Return: Pointer to the newly created node or null
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *node = malloc(sizeof(binary_tree_t));
	/*checks if the memory allocation was successful*/
	if (node)
	{
		/*assigns the integer value to the n member of the newly*/
		/*created node pointed to by node*/
		node->n = value;
		/* sets the parent member of the newly created */
		node->parent = parent;
		/*initialize the left and right pointers of the newly created node to NULL*/
		node->left = NULL;
		node->right = NULL;
	}
	return (node);
}
