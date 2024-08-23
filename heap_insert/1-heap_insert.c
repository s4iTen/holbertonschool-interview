#include "binary_trees.h"

/**
 * heap_insert - Inserts a value into a Max Binary Heap.
 * @root: Double pointer to the root node of the Heap.
 * @value: The value to store in the node to be inserted.
 * Return: Pointer to the inserted node, or NULL on failure.
 */

heap_t *heap_insert(heap_t **root, int value)
{
    heap_t *new_node, *current;

    new_node = binary_tree_node(NULL, value);
    if (!new_node)
        return (NULL);

    if (!*root)
        return (*root = new_node);

    current = *root;
    while (current->left || current->right)
    {
        if (value <= current->n)
            break;

        if (!current->right || current->left->n > current->right->n)
        {
            current = current->left;
        }
        else
        {
            current = current->right;
        }
    }

    new_node->parent = current;
    if (!current->left)
        current->left = new_node;
    else
        current->right = new_node;

    while (new_node->parent && new_node->n > new_node->parent->n)
    {
        /*combines two values using bitwise and assigns the result back to the left operand.*/
        new_node->n ^= new_node->parent->n;
        new_node->parent->n ^= new_node->n;
        new_node->n ^= new_node->parent->n;
        new_node = new_node->parent;
    }

    return (new_node);
}
