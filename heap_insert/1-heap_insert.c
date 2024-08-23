#include "binary_trees.h"

/**
 * binary_tree_size - Measures the size of a binary tree
 * @tree: Pointer to the root node of the tree to measure
 *
 * Return: Size of the tree
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
    if (tree == NULL)
        return (0);
    return (1 + binary_tree_size(tree->left) + binary_tree_size(tree->right));
}

/**
 * binary_tree_is_perfect - Checks if a binary tree is perfect
 * @tree: Pointer to the root node of the tree to check
 *
 * Return: 1 if the tree is perfect, 0 otherwise
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
    if (tree == NULL)
        return (0);
    if (binary_tree_size(tree->left) == binary_tree_size(tree->right))
        return (1);
    return (0);
}

/**
 * heapify_up - Bubbles up the node to maintain the max-heap property
 * @node: Pointer to the node to heapify up
 *
 * Return: Pointer to the node after heapifying
 */
heap_t *heapify_up(heap_t *node)
{
    int temp;

    while (node->parent && node->n > node->parent->n)
    {
        temp = node->n;
        node->n = node->parent->n;
        node->parent->n = temp;
        node = node->parent;
    }
    return (node);
}

/**
 * heap_insert - Inserts a value into a Max Binary Heap
 * @root: Double pointer to the root node of the Heap
 * @value: Value to store in the node to be inserted
 *
 * Return: Pointer to the inserted node, or NULL on failure
 */
heap_t *heap_insert(heap_t **root, int value)
{
    heap_t *new_node, *parent;
    size_t size;
    unsigned int bit;

    if (root == NULL)
        return (NULL);

    if (*root == NULL)
    {
        *root = binary_tree_node(NULL, value);
        return (*root);
    }

    size = binary_tree_size(*root) + 1;
    bit = 1;

    while (size >> bit)
        bit++;
    bit -= 2;

    parent = *root;
    while (bit)
    {
        if (size >> bit & 1)
            parent = parent->right;
        else
            parent = parent->left;
        bit--;
    }

    if (size & 1)
        parent->right = binary_tree_node(parent, value);
    else
        parent->left = binary_tree_node(parent, value);

    if (size & 1)
        new_node = parent->right;
    else
        new_node = parent->left;

    return (heapify_up(new_node));
}
