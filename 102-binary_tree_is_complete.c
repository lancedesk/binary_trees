#include "binary_trees.h"

int binary_tree_is_complete_recursive(
		const binary_tree_t *tree, int index, int node_count

		);

size_t binary_tree_size(const binary_tree_t *tree);

/**
 * binary_tree_is_complete - Checks if a binary tree is complete.
 * @tree: A pointer to the root node of the tree to check.
 *
 * Return: 1 if the tree is complete, 0 otherwise.
 */

int binary_tree_is_complete(const binary_tree_t *tree)
{
	if (tree == NULL)
	{
		return (0);
	}

	return (binary_tree_is_complete_recursive(tree, 0, binary_tree_size(tree)));
}

/**
 * binary_tree_is_complete_recursive - Recursive helper function
 *                                      to check if a tree is complete.
 * @tree: A pointer to the current node.
 * @index: The index of the current node.
 * @node_count: The total number of nodes in the tree.
 *
 * Return: 1 if the tree is complete, 0 otherwise.
 */

int binary_tree_is_complete_recursive(
		const binary_tree_t *tree, int index, int node_count

		)
{
	if (tree == NULL)
	{
		return (1);
	}

	if (index >= node_count)
	{
		return (0);
	}

	return (
			binary_tree_is_complete_recursive(tree->left, 2 * index + 1, node_count) &&
			binary_tree_is_complete_recursive(tree->right, 2 * index + 2, node_count)
	       );
}

/**
 * binary_tree_size - Measures the size of a binary tree.
 * @tree: A pointer to the root node of the tree to measure.
 *
 * Return: The size of the tree, 0 if the tree is NULL.
 */

size_t binary_tree_size(const binary_tree_t *tree)
{
	if (tree == NULL)
	{
		return (0);
	}

	return (1 + binary_tree_size(tree->left) + binary_tree_size(tree->right));
}
