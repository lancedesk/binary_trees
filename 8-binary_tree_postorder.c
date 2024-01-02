#include "binary_trees.h"

/**
 * binary_tree_postorder - Traverses a binary treeusing post-order traversal.
 * @tree: Pointer to the root node of the tree to traverse.
 * @func: Pointer to a function to call for each node. The value in the
 *        node must be passed as a parameter to this function.
 */

void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int))
{
	if (!tree || !func)
	{
		return;
	}

	binary_tree_postorder(tree->left, func); /* Recur on the left subtree */
	binary_tree_postorder(tree->right, func); /* Recur on the right subtree */
	func(tree->n); /* Call the function for the current node */
}
