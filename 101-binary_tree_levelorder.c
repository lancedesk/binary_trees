#include "binary_trees.h"
#include <stdlib.h>

/**
 * binary_tree_levelorder - Traverses a binary tree using level-order traversal
 * @tree: Pointer to the root node of the tree to traverse
 * @func: Pointer to a function to call for each node
 *
 * Description: If `tree` or `func` is NULL, do nothing.
 */

void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	binary_tree_t **queue;
	size_t front = 0, rear = 0;

	if (tree == NULL || func == NULL)
	{
		return;
	}

	/* Create a queue for level-order traversal */
	queue = malloc(sizeof(binary_tree_t *) * 1024);

	if (queue == NULL)
	{
		return;
	}

	queue[rear++] = (binary_tree_t *)tree; /* Enqueue the root */

	/* Process nodes in the queue */
	while (front < rear)
	{
		binary_tree_t *current = queue[front++];

		/* Call the provided function on the current node's value */
		func(current->n);

		/* Enqueue the left child if exists */
		if (current->left != NULL)
		{
			queue[rear++] = current->left;
		}

		/* Enqueue the right child if exists */
		if (current->right != NULL)
		{
			queue[rear++] = current->right;
		}
	}

	free(queue);
}
