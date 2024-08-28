#include "binary_trees.h"

/**
 * binary_tree_is_avl - checks if a binary tree is a valid AVL tree
 * @tree:  pointer to the root node of the tree to check
 *
 * Return: 1 if AVL, 0 if not
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	int check = 0;

	if (tree == NULL)
		return (0);
	check = is_bst_recursive(tree, INT_MIN, INT_MAX);
	if (check == 0)
		return (0);
	check = is_balanced_preorder(tree);
	if (check == 0)
		return (0);
	return (1);
}

/**
 * is_bst_recursive - checks if tree is a valid BST using recursive traversal
 * @tree: pointer to the root node of the tree to check
 * @min: minimum value root node must be greater than
 * @max: maximum value root node must be less than
 *
 * Return: 1 if succesful, 0 if failed
 */
int is_bst_recursive(const binary_tree_t *tree, int min, int max)
{
	int local_min = min, local_max = max, left = 0, right = 0;

	if (tree == NULL)
		return (1);
	if (tree->n == min || tree->n == max)
		return (0);
	if (tree->left)
		local_min = tree->left->n;
	if (tree->right)
		local_max = tree->right->n;
	if (tree->n <= local_min || tree->n >= local_max)
		return (0);
	if (local_min == min && local_max == max)
		return (1);
	left = is_bst_recursive(tree->left, min, tree->n);
	right = is_bst_recursive(tree->right, tree->n, max);
	return (left * right);
}

/**
 * is_balanced_preorder - checks if tree is balanced using preorder traversal
 * balanced = difference between left and right subtrees cannot be more than 1
 * @tree: pointer to the root node of the tree to check
 *
 * Return: 1 if balanced, 0 if unbalanced
 */
int is_balanced_preorder(const binary_tree_t *tree)
{
	int balanced = 0;

	if (tree == NULL)
		return (1);

	balanced = is_balanced(tree);
	if (balanced == 0)
		return (0);
	balanced = is_balanced_preorder(tree->left);
	if (balanced == 0)
		return (0);
	balanced = is_balanced_preorder(tree->right);
	if (balanced == 0)
		return (0);
	return (1);
}

/**
 * is_balanced - determines if the tree is balanced at a specific node
 * balanced = difference between left and right subtrees cannot be more than 1
 * @tree: pointer to the root node of the tree to check
 *
 * Return: 1 if balanced, 0 if unbalanced
 */
int is_balanced(const binary_tree_t *tree)
{
	int left = 0, right = 0, balance_factor = 0;

	if (tree == NULL)
		return (0);

	left = height_helper(tree->left);
	right = height_helper(tree->right);

	balance_factor = left - right;
	if (balance_factor >= -1 && balance_factor <= 1)
		return (1);

	return (0);
}

/**
 * height_helper - height of the subtree
 * @tree: pointer to the root node of the tree to check
 *
 * Return: height of the subtree
 */
size_t height_helper(const binary_tree_t *tree)
{
	size_t left = 0, right = 0;

	if (tree == NULL)
		return (0);

	left = (1 + height_helper(tree->left));
	right = (1 + height_helper(tree->right));

	if (left > right)
		return (left);

	return (right);
}
