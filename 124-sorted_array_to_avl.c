#include <stdlib.h>
#include "binary_trees.h"

avl_t *sorted_array_to_avl_recursive(
		avl_t *parent, int *array, size_t start, size_t end);

/**
 * sorted_array_to_avl - Builds an AVL tree from a sorted array.
 * @array: Pointer to the first element of the array to be converted.
 * @size: Number of elements in the array.
 *
 * Return: Pointer to root node of created AVL tree, or NULL on failure.
 */

avl_t *sorted_array_to_avl(int *array, size_t size)
{
	if (size == 0 || array == NULL)
	{
		return (NULL);
	}

	return (sorted_array_to_avl_recursive(NULL, array, 0, size - 1));
}

/**
 * sorted_array_to_avl_recursive - Recursive helper for AVL conversion.
 * @parent: Pointer to the parent node.
 * @array: Pointer to the first element of the array.
 * @start: Starting index of the subarray.
 * @end: Ending index of the subarray.
 *
 * Return: Pointer to root node of created AVL tree, or NULL on failure.
 */

avl_t *sorted_array_to_avl_recursive(
		avl_t *parent, int *array, size_t start, size_t end)
{
	size_t mid;
	avl_t *new_node;

	if (start > end)
	{
		return (NULL);
	}

	mid = (start + end) / 2;

	new_node = binary_tree_node(parent, array[mid]);
	if (new_node == NULL)
	{
		return (NULL);
	}

	new_node->left = sorted_array_to_avl_recursive(
			new_node, array, start, mid - 1);

	if (new_node->left == NULL)
	{
		free(new_node);
		return (NULL);
	}

	new_node->right = sorted_array_to_avl_recursive(
			new_node, array, mid + 1, end);

	if (new_node->right == NULL)
	{
		free(new_node->left);
		free(new_node);
		return (NULL);
	}

	return (new_node);
}
