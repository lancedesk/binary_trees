#include "binary_trees.h"

avl_t *fully_insert_avl(avl_t *tree, avl_t *parent, int value);
void balance_subtree(avl_t **root, avl_t *tree, int value);

/**
 * avl_insert - Inserts a value in an AVL Tree.
 * @tree: Double pointer to root node of AVL tree for inserting value.
 * @value: The value to store in the node to be inserted.
 *
 * Return: A pointer to the created node, or NULL on failure.
 */

avl_t *avl_insert(avl_t **tree, int value)
{
	avl_t *new_node, *predecessor;

	if (tree == NULL)
	{
		return (NULL);
	}
	if (*tree == NULL)
	{
		new_node = binary_tree_node(NULL, value);
		*tree = new_node;
		return (new_node);
	}
	new_node = fully_insert_avl(*tree, NULL, value);

	if (new_node == NULL)
	{
		return (NULL);
	}

	predecessor = new_node->parent;

	while (predecessor != NULL)
	{
		balance_subtree(tree, predecessor, value);
		predecessor = predecessor->parent;
	}

	return (new_node);
}

/**
 * fully_insert_avl - Inserts a value in an AVL Tree with full logic.
 * @tree: The AVL tree.
 * @parent: The parent node.
 * @value: The value to be inserted.
 *
 * Return: A pointer to the created node, or NULL on failure.
 */

avl_t *fully_insert_avl(avl_t *tree, avl_t *parent, int value)
{
	avl_t *new_node;

	if (tree == NULL)
	{
		new_node = binary_tree_node(parent, value);
		if (parent->n > new_node->n)
		{
			parent->left = new_node;
		}
		else
		{
			parent->right = new_node;
		}
		return (new_node);
	}
	else if (value == tree->n)
	{
		return (NULL);
	}
	else if (value < tree->n)
	{
		return (fully_insert_avl(tree->left, tree, value));
	}
	else
	{
		return (fully_insert_avl(tree->right, tree, value));
	}
}

/**
 * balance_subtree - Balances subtree rooted at given node.
 * @root: Pointer to the root node.
 * @tree: The current node being checked for balancing.
 * @value: The value being inserted.
 */

void balance_subtree(avl_t **root, avl_t *tree, int value)
{
	int new_balance;

	new_balance = binary_tree_balance(tree);
	if (new_balance > 1)
	{
		if (tree->left->n > value)
		{
			if (*root == tree)
			{
				*root = tree->left;
			}
			binary_tree_rotate_right(tree);
		}
		else
		{
			if (*root == tree)
			{
				*root = tree->left->right;
			}
			binary_tree_rotate_left(tree->left);
			binary_tree_rotate_right(tree);
		}
	}
	if (new_balance < -1)
	{
		if (tree->right->n < value)
		{
			if (*root == tree)
			{
				*root = tree->right;
			}
			binary_tree_rotate_left(tree);
		}
		else
		{
			if (*root == tree)
			{
				*root = tree->right->left;
			}
			binary_tree_rotate_right(tree->right);
			binary_tree_rotate_left(tree);
		}
	}
}
