#include "binary_trees.h"

/**
 * binary_tree_uncle - Finds the uncle of a node in a binary tree.
 * @node: A pointer to the node to find the uncle.
 *
 * Return: A pointer to the uncle node.
 * If node is NULL, return NULL.
 * If node has no uncle, return NULL.
 */

binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	if (node == NULL || node->parent == NULL || node->parent->parent == NULL)
	{
		return (NULL);
	}

	if (node->parent == node->parent->parent->left)
	{
		return (node->parent->parent->right);
	}
	else if (node->parent == node->parent->parent->right)
	{
		return (node->parent->parent->left);
	}

	return (NULL);
}
