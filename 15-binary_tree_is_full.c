#include "binary_trees.h"

/**
 * binary_tree_is_full - Checks if a binary tree is full.
 * @tree: Pointer to the root node of the tree to check.
 *
 * Return: 1 if the tree is full, 0 otherwise. If tree is NULL, return 0.
 */

int binary_tree_is_full(const binary_tree_t *tree)
{
	if (!tree)
	{
		return (0);
	}

	/* If the tree is a leaf, it is full by definition */
	if (!tree->left && !tree->right)
	{
		return (1);
	}

	/* If either subtree is missing or the tree is unbalanced, it's not full */
	if (!tree->left || !tree->right)
	{
		return (0);
	}

	/* Recursively check the left and right subtrees */
	return (binary_tree_is_full(tree->left) && binary_tree_is_full(tree->right));
}
