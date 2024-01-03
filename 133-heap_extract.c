#include "binary_trees.h"
#include <stdlib.h>

/**
 * swap_values - Helper function to swap values between two nodes.
 * @node1: Pointer to the first node.
 * @node2: Pointer to the second node.
 */

void swap_values(heap_t *node1, heap_t *node2)
{
	int temp = node1->n;
	node1->n = node2->n;
	node2->n = temp;
}

/**
 * find_last_node - Helper function to find the last node in the heap.
 * @root: Pointer to the root node of the heap.
 * Return: Pointer to the last node.
 */

heap_t *find_last_node(heap_t *root)
{
	heap_t *last_node = root;

	while (last_node->left || last_node->right)
	{
		if (last_node->right && !last_node->right->left)
		{
			last_node = last_node->right;
		}
		else
		{
			last_node = last_node->left;
		}
	}

	return (last_node);
}

/**
 * remove_last_node - Helper function to remove the last node from the heap.
 * @last_node: Pointer to the last node to be removed.
 */

void remove_last_node(heap_t *last_node)
{
	if (last_node->parent)
	{
		if (last_node->parent->left == last_node)
		{
			last_node->parent->left = NULL;
		}
		else
		{
			last_node->parent->right = NULL;
		}
	}

	free(last_node);
}

/**
 * heapify_down - Helper function to heapify down the tree after extraction.
 * @root: Pointer to the root node of the heap.
 */

void heapify_down(heap_t *root)
{
	heap_t *largest, *temp;

	while (root->left || root->right)
	{
		largest = root;
		if (root->left && root->left->n > largest->n)
		{
			largest = root->left;
		}
		if (root->right && root->right->n > largest->n)
		{
			largest = root->right;
		}

		if (largest != root)
		{
			swap_values(root, largest);
			root = largest;
		}
		else
		{
			break;
		}
	}
}

/**
 * heap_extract - Extracts the root node of a Max Binary Heap.
 * @root: Double pointer to the root node of the heap.
 * Return: Value stored in the root node.
 */

int heap_extract(heap_t **root)
{
	int value;
	heap_t *last_node, *temp;

	if (!root || !*root)
	{
		return (0);
	}

	value = (*root)->n;
	last_node = find_last_node(*root);

	if (*root == last_node)
	{
		*root = NULL;
	}

	if ((*root) && (!(*root)->left && !(*root)->right))
	{
		(*root)->n = last_node->n;
	}
	else if ((*root) && (*root)->left)
	{
		(*root)->n = last_node->n;
		remove_last_node(last_node);
		heapify_down(*root);
	}
	else
	{
		free(last_node);
	}

	return (value);
}
