#include "binary_trees.h"

bst_t *create_bst_node(bst_t *parent, int value);

/**
 * bst_insert - Inserts a value in a Binary Search Tree (BST).
 * @tree: A double pointer to the root node of the BST to insert the value.
 * @value: The value to store in the node to be inserted.
 *
 * Return: A pointer to the created node, or NULL on failure.
 */

bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *current_node, *new_node;

	if (tree != NULL)
	{
		current_node = *tree;

		if (current_node == NULL)
		{
			new_node = create_bst_node(current_node, value);
			if (new_node == NULL)
			{
				return (NULL);
			}
			return (*tree = new_node);
		}

		if (value < current_node->n)
		{
			if (current_node->left != NULL)
			{
				return (bst_insert(&current_node->left, value));
			}

			new_node = create_bst_node(current_node, value);
			if (new_node == NULL)
			{
				return (NULL);
			}
			return (current_node->left = new_node);
		}
		if (value > current_node->n)
		{
			if (current_node->right != NULL)
			{
				return (bst_insert(&current_node->right, value));
			}

			new_node = create_bst_node(current_node, value);
			if (new_node == NULL)
			{
				return (NULL);
			}
			return (current_node->right = new_node);
		}
	}
	return (NULL);
}

/**
 * create_bst_node - Creates a new node for a Binary Search Tree (BST).
 * @parent: Pointer to the parent node.
 * @value: Value to store in the new node.
 *
 * Return: A pointer to the newly created node, or NULL on failure.
 */

bst_t *create_bst_node(bst_t *parent, int value)
{
	bst_t *new_node = binary_tree_node((binary_tree_t *)parent, value);

	if (new_node == NULL)
	{
		return (NULL);
	}

	return (new_node);
}
