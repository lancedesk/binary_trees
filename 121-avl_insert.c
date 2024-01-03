#include "binary_trees.h"

avl_t *create_avl_node(avl_t *parent, int value);
avl_t *rotate_avl_node(avl_t *current, int value);
avl_t *avl_insert_recursive(
		avl_t **tree, avl_t *parent, avl_t *current, int value);
binary_tree_t *binary_tree_rotate_right_left(binary_tree_t *tree);
binary_tree_t *binary_tree_rotate_left_right(binary_tree_t *tree);

/**
 * avl_insert - Inserts a value in an AVL Tree.
 * @tree: Double pointer to root node of AVL tree
 * for inserting the value.
 * @value: The value to store in the node to be inserted.
 *
 * Return: A pointer to the created node, or NULL on failure.
 */

avl_t *avl_insert(avl_t **tree, int value)
{
	if (!tree)
	{
		return (NULL);
	}

	return (avl_insert_recursive(tree, NULL, *tree, value));
}

/**
 * create_avl_node - Creates a new AVL node.
 * @parent: Pointer to the parent node.
 * @value: The value to store in the node.
 *
 * Return: A pointer to the created node, or NULL on failure.
 */

avl_t *create_avl_node(avl_t *parent, int value)
{
	avl_t *new_node = binary_tree_node(parent, value);

	if (!new_node)
	{
		return (NULL);
	}

	return (new_node);
}

/**
 * rotate_avl_node - Rotates an AVL node as needed for balancing.
 * @current: Current node to be rotated.
 * @value: The value being inserted.
 *
 * Return: The new root of the subtree after rotation.
 */

avl_t *rotate_avl_node(avl_t *current, int value)
{
	if (binary_tree_balance(current) > 1)
	{
		if (value < current->left->n)
		{
			return (binary_tree_rotate_right(current));
		}
		else
		{
			return (binary_tree_rotate_left_right(current));
		}
	}
	else if (binary_tree_balance(current) < -1)
	{
		if (value > current->right->n)
		{
			return (binary_tree_rotate_left(current));
		}
		else
		{
			return (binary_tree_rotate_right_left(current));
		}
	}

	return (current);
}

/**
 * avl_insert_recursive - Recursive helper function for AVL insertion.
 * @tree: Double pointer to root node of AVL tree for inserting the value.
 * @parent: Pointer to the parent node.
 * @current: Current node in the recursive process.
 * @value: The value to store in the node to be inserted.
 *
 * Return: A pointer to the created node, or NULL on failure.
 */

avl_t *avl_insert_recursive(
		avl_t **tree, avl_t *parent, avl_t *current, int value)
{
	avl_t *new_node;

	if (!current)
	{
		new_node = create_avl_node(parent, value);
		if (!new_node)
		{
			return (NULL);
		}

		*tree = new_node;
		return (new_node);
	}
	if (value == current->n)
	{
		return (NULL);
	}
	if (value < current->n)
	{
		new_node = avl_insert_recursive(
				&current->left, current, current->left, value);
		if (!new_node)
		{
			return (NULL);
		}
		current = rotate_avl_node(current, value);
	}
	else
	{
		new_node = avl_insert_recursive(
				&current->right, current, current->right, value);
		if (!new_node)
		{
			return (NULL);
		}
		current = rotate_avl_node(current, value);
	}

	return (current);
}

/**
 * binary_tree_rotate_left_right - Performs a left-right rotation
 * on a binary tree.
 * @tree: Pointer to the root node of the binary tree.
 *
 * Return: Pointer to the new root of the rotated binary tree.
 */

binary_tree_t *binary_tree_rotate_left_right(binary_tree_t *tree)
{
	if (!tree || !tree->left)
	{
		return (NULL);
	}

	tree->left = binary_tree_rotate_left(tree->left);
	return (binary_tree_rotate_right(tree));
}

/**
 * binary_tree_rotate_right_left - Performs a right-left rotation
 * on a binary tree.
 * @tree: Pointer to the root node of the binary tree.
 *
 * Return: Pointer to the new root of the rotated binary tree.
 */

binary_tree_t *binary_tree_rotate_right_left(binary_tree_t *tree)
{
	if (!tree || !tree->right)
	{
		return (NULL);
	}

	tree->right = binary_tree_rotate_right(tree->right);
	return (binary_tree_rotate_left(tree));
}
