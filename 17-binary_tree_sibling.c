#include "binary_trees.h"

/** binary_tree_sibling - Finds the sibling of a node in a binary tree.
 * @node: A pointer to the node to find the sibling.
 *
 * Return: A pointer to the sibling node.
 * If node is NULL or the parent is NULL, return NULL.
 * If node has no sibling, return NULL.
 */

binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	/* Check if the node or its parent is NULL */
	if (node == NULL || node->parent == NULL)
	{
		return (NULL);
	}

	/* Check if the node is the left child of its parent */
	if (node->parent->left == node)
	{
		return (node->parent->right); /* Return the right child as sibling */
	}
	/* Check if the node is the right child of its parent */
	else if (node->parent->right == node)
	{
		return (node->parent->left); /* Return the left child as sibling */
	}

	return (NULL); /* If the node is not a child, return NULL */
}
